#include<stdio.h>
#include<stdbool.h>


void bubbleSort(int a[], int n)
{
    int i,j,temp;

    for(i=0;i<n;i++) {

        for(j=0;j<n-i-1;j++) {

            if(a[j]>a[j+1]){

                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


///////////////////////////////////////////////////

bool isListSorted(int a[],int n)
{
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


int main()
{
int i=0,n=0,arr[1000];

FILE *fp = fopen("numbers.txt","r");

while(fscanf(fp,"%d",&arr[i])!=EOF) {
     i++;
     n++;
 }

 bubbleSort(arr,n);
 isListSorted(arr,n);

}

////////////////////////////////////////////////
