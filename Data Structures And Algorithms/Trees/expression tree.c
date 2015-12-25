#include<stdio.h>
#include<stdlib.h>

#define N 100

int top = -1;

struct node
{
    char info;
    int x;
    struct node* llink, *rlink;

};


struct node * getNode(char ch,int x)
{

    struct node * neww = (struct node *)malloc(sizeof(struct node));

    neww->info = ch;
    neww->x = x;
    neww->llink = NULL;
    neww->rlink = NULL;

    return neww;

}


void push(struct node *array[],struct node * temp)
{
    if(top >= N)
        printf("Full Capacity");

    else
        array[++top] = temp;
}


struct node * pop(struct node* array[])
{
    if(top <= -1)
        printf("\nEmpty stack");


    else {
        struct node * temp = array[top];
        top--;
        return temp;
    }
}


void inorder(struct node * root) {

    if(root->llink!=NULL)
        inorder(root->llink);

    printf(" %c ",root->info);

    if(root->rlink!=NULL)
        inorder(root->rlink);

}


float  calculate(struct node * root) {

    if( !isalnum(root->llink->info) && root->llink != NULL ) {
        root->llink->x = calculate(root->llink);
    }

    if( !isalnum(root->rlink->info) && root->rlink != NULL ) {
        root->rlink->x = calculate(root->rlink);
    }

    float a = (float)((root->llink)->x);
    float b = (float)((root->rlink)->x);

    switch(root->info) {

        case '+' :
                    return a + b;

        case '-' :
                    return a - b;

        case '*' :
                    return a * b;

        case '/' :
                    return a / b;

    }
}



int main()
{
    struct node *array[100];
    int i;
    char post[100];

    printf("\nEnter the postfix expression  ");
    gets(post);


    for(i=0;post[i]!='\0';i++) {

        if(isalnum(post[i])) {

            int z=(int)(post[i]-'0');
            struct node * neww= getNode(post[i],z);
            push(array,neww);
        }


        else {

            struct node *t1 = pop(array);
            struct node *t2 = pop(array);

            struct node * neww= getNode(post[i],0);

            neww->rlink = t1;
            neww->llink = t2;

            push(array,neww);
        }
    }


    struct node * head = pop(array);

    printf("\nExpression is \n");
    inorder(head);

    printf("\n\nThe evaluated expression is  %f\n",calculate(head));
    printf("\n");

    return 0;
}
