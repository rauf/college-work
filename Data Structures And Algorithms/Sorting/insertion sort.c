#include<stdio.h>
#include<stdbool.h>

void insertionSort(int a[],int n){

    int i,j,k,temp,key;

    for(i=1;i<n;i++){

        key=i;

        while((key>0)&&(a[key]<a[key-1])){

            temp=a[key-1];
            a[key-1]=a[key];
            a[key]=temp;
            key--;
        }
    }
}


///////////////////////////////////////////////////

bool isListSorted(int a[],int n) {

    int i;
    bool listSorted;

    for(i=0;i<n-1;i++){

        if(a[i+1]>=a[i]){
            listSorted=true;
        }

        else{
            listSorted=false;
            break;
        }
    }
        if(listSorted==true){

             for(i=0;i<n;i++){
                    printf("%d ",a[i]);
                }
            printf("\n\nList is sorted\n");
        }
        else printf("\n\nList is not sorted\n");
}


int main(){

    int i=0,n=0,arr[1000];

    FILE *fp = fopen("numbers.txt","r");

    while(fscanf(fp,"%d",&arr[i])!=EOF) {
         i++;
         n++;
     }

     insertionSort(arr,n);
     isListSorted(arr,n);
}

////////////////////////////////////////////////
