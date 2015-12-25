#include<stdio.h>
#include<stdbool.h>


void mergeSort(int a[],int beg,int end)
{
        int mid = (beg+end)/2;

        if(beg<end) {
            mergeSort(a,beg,mid);
            mergeSort(a,mid+1,end);

            merge(a,beg,mid,end);
        }
}

void merge(int a[],int beg,int mid,int end){

    int temp[1000];
    int i=beg,j=mid+1;
    int x=0,z;

    while((i<=mid)&&(j<=end)){

        if(a[i]<a[j])
            temp[x++]=a[i++];

        else if(a[i]>=a[j])
            temp[x++]=a[j++];
    }

    if(j>=end)
        while(i<=mid)             //when second sub array is empty
            temp[x++]=a[i++];

    if(i>=mid)
        while(j<=end)             // when first sub array is empty
            temp[x++]=a[j++];

       for(z=0;z<x;z++)           //copying back
        a[beg+z]=temp[z];

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

 mergeSort(arr,0,n);

 isListSorted(arr,n);

}

////////////////////////////////////////////////

