#include<stdio.h>
#include<stdbool.h>


void shellSort(int a[],int n,int nsort){

    int i=0,j=0,k=0,temp=0,key;


    while(nsort>=1) {

    for(i=nsort;i<n;i++) {

        while((i>=nsort)&&(a[i]<a[i-nsort])) {

            temp=a[i-nsort];
            a[i-nsort]=a[i];
            a[i]=temp;

            i-=nsort;
        }
    }
    nsort/=2;
  }
}


///////////////////////////////////////////////////

bool isListSorted(int a[],int n){

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

     shellSort(arr,n,n/2);
     isListSorted(arr,n);

}

////////////////////////////////////////////////

