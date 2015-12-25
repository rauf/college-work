#include<stdio.h>
#include<stdlib.h>

#define N 20

int top=-1;

struct node {

    int weight;
    struct node *llink,*rlink;

}*head;


struct node * getNode(int data)
{
    struct node * temp;

    temp=(struct node *)malloc(sizeof(struct node));
    temp->weight = data;
    temp->llink = NULL;
    temp->rlink = NULL;

    return temp;

}


void push(struct node *array[],struct node * node) {

    if(top>N)
        printf("\nFull capacity");

    else
        array[++top] = node;
}


struct node *pop(struct node * array[]){

    if(top<-1)
        printf("\nEmpty ");

    else {
        struct node *t = array[top];
        top--;
        return t;
    }

}



void sort(struct node * array[],int n)
{
    int i,j;

    for(i=0;i<n;i++){

        for(j=0;j<n-1;j++){

            if((array[j+1]->weight) > (array[j]->weight)){

                struct node * temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


void inorder(struct node *root){

    if(root->llink != NULL)
        inorder(root->llink);

    printf(" %d ",root->weight);

    if(root->rlink != NULL)
        inorder(root->rlink);
}


int main() {

    struct node * array[N];
    int i,j,k,n;

    printf("\nEnter the number of elements  ");

    scanf("%d",&n);

    printf("\nEnter their weights ");

    for(i=0;i<n;i++) {

        scanf("%d",&k);

        struct node *x = getNode(k);
        push(array,x);

    }

    //sort the array
    sort(array,n);

    while(top>=1) {

        struct node *t1 = pop(array);
        struct node *t2 = pop(array);

        int w = t1->weight + t2->weight;
        struct node *temp = getNode(w);

        temp->llink = t1;
        temp->rlink = t2;

        push(array,temp);
        sort(array,n);

    }

    printf("\n\n");

    struct node *head = pop(array);

    printf("Inorder traversal of tree is\n");
    inorder(head);

    return 0;
}
