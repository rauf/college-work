#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>

#define MAX 10

void parseFile(int **arr, int *initial, int *final, int *states, int *cols) {

	std::ifstream file("dfa.txt");
	char line[100];
	*initial = 0;
	*final = 0;
	int num = 0;
	int row = 0;
	int col = 0;
	int counter = 0;

	while(file.getline(line, 100) != NULL) {
		
		col = 0;

		if(counter == 0) *initial = atoi(line);
		else if(counter == 1) *final = atoi(line);
		else {
			int length = strlen(line);

			for(int i = 0; i <= length; ++i) {
				
				if(line[i] >= '0' && line[i] <= '9') {
					num = num * 10 + (line[i] - '0');
				}
				else if(line[i] == ' '  || line[i] == '\0') {
					arr[row][col++] = num;
					num = 0;
				}
				else if(line[i] == '-') {
					arr[row][col++] = -1;
					num = 0;
					i++;
					while(line[i] != ' ') i++;
				}
			}
			row++;
		}
		counter++;
	}
	*states = row;
	*cols = col;
}

bool checkString(char *str, int **arr, int initial, int final, int states) {

	int current = initial;

	for (int i = 0; str[i] != '\0'; ++i) {
		int curr_input = str[i] - '0';
	
		if(curr_input >= states){
			std::cout << "\nWrong input: " << curr_input;
			return false;
		}

		if(arr[current][curr_input] == -1) return false;
		current = arr[current][curr_input];	
	}

	if(current != final) return false;
	return true;
}

void printArr(int **arr, int rows, int cols) {

	for (int i = 0; i < rows; ++i) {
		std::cout << std::endl;
		for (int j = 0; j < cols; ++j) {
			std::cout << " " << arr[i][j] << "  ";
		}
	}

}


int main(){

	int initial;
	int final;
	int **arr;
	int states;
	int num;

	arr = new int*[MAX];
	for (int i = 0; i < MAX; ++i)
		arr[i] = new int;
	
	parseFile(arr, &initial, &final, &states, &num);
	printArr(arr, states, num);

	while(true){
		
		std::cout << "\nEnter string: ";
		char str[100];
		std::cin.getline(str, 100);	
		if(checkString(str, arr, initial, final, states))
			std::cout << "\nString accepted";
		else std::cout << "\nString rejected";
	}	
}