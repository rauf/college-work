 #include <fstream>
 #include <iostream>
 #include <stdlib.h>

 int search_contact() {

	 std::string name,line;
	 std::cout << "Enter the name to be searched: " << std::endl;
	 std::cin >> name;
	 std::ifstream file;
	 file.open("abd.txt");

	 while (getline(file,line)) {

	 if (line == name) {

	 	std::cout << "Search successful!. The name is found."<< std::endl;
		return 1;

	 }
	 }
	std::cout << "Search unsuccessful. Name not found .";
	return 0;

 }


 void add_contact() {

	 std::string name;
	 std::string mobile_no;
	 std::cout << "Enter name: " << std::endl;
	 std::cin >> name;
	 std::cout << "Enter mobile no: " << std::endl;
	 std::cin >> mobile_no;
	 std::ofstream file;
	 file.open("abd.txt",std::ios::app | std::ios :: out );
	 file << name << std::endl << mobile_no << std::endl ;
	 file.close();

 }

 void delete_contact()

 {

	 std::string name,line;
	 std::cout << "Give the name to be deleted: " << std::endl;
	 std::cin >> name;
	 std::ifstream file;
	 std::ofstream temp;
	 file.open("abd.txt");
	 temp.open("temp.txt");

	 while (getline(file,line)) {

	 	if (line != name){
	 		temp << line << std::endl;
	 	} else {

	 std::cout << "The name was present and deleted successfully.";

	 getline(file,line);
	 getline(file,line);

	 }
	 }

	 file.close();
	 temp.close();
	 remove("abd.txt");
	 rename("temp.txt","abd.txt");

 }

 int main()

 {

	 int choice;

	 while (1) {

	 std::cout << "\nMENU\n" << std::endl;

	 std::cout << "\n1. Add \n2. Delete \n3. Search \n4. Exit"<< std::endl;

	 std::cout << "Enter your choice: " << std::endl;

	 std::cin >> choice;

	 switch(choice) {

	 case 1: add_contact();
	 		break;

	 case 2: delete_contact();
	 		break;

	 case 3: search_contact();
	 		break;

	 case 4: exit(1);

	 default:	 std::cout<< "Please Enter a correct choice.";
	 		break;

	 }

	 }

 }