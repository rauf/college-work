#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node {

    int info;
    struct node *llink;
    struct node *rlink;

} *head=NULL;


struct node * createNode(int info){

        struct node * neww=(struct node *)malloc(sizeof(struct node));
        neww->info=info;
        neww->llink=NULL;
        neww->rlink=NULL;

        return neww;
}

void insert(struct node *temp,int data){

    if(head == NULL){
        temp = head = createNode(data);
    }

    else if(data < temp->info && temp->llink != NULL)
            insert(temp->llink,data);

    else if(data < temp->info && temp->llink == NULL){
        temp->llink=createNode(data);
        return;
    }

    else if(data >= temp->info && temp->rlink != NULL)
        insert(temp->rlink,data);

    else if(data >= temp->info && temp->rlink == NULL){
        temp->rlink=createNode(data);
        return;
    }
}


void displayPostorder(struct node *root) {

    if(head==NULL){

    printf("\nNo nodes in tree\n");
    return;
    }

    if(root->llink != NULL)
    displayPostorder(root->llink);

    if(root->rlink != NULL)
    displayPostorder(root->rlink);

    printf("   %d   ",root->info);
}


void displayPreorder(struct node *root) {

    if(head == NULL){

    printf("\nNo nodes in tree\n");
    return;
    }

    printf("   %d   ",root->info);

    if(root->llink != NULL)
    displayPreorder(root->llink);

    if(root->rlink != NULL)
    displayPreorder(root->rlink);
}


void displayInorder(struct node *root){

    if(head == NULL){

    printf("\nNo nodes in tree\n");
    return;
    }

    if(root->llink != NULL)
    displayInorder(root->llink);

    printf("   %d   ",root->info);

    if(root->rlink != NULL)
    displayInorder(root->rlink);
}


struct node * getMaxNode(struct node * root)
{

    while(root->rlink != NULL)
        root = root->rlink;

    return root;
}


struct node * getMinNode(struct node * root) {

    while(root->llink != NULL)
        root=root->llink;

    return root;
}


struct node * getNodeByInfo(struct node *root,int data) {

    if(root->info == data) {
        return root;
    }

    while(root != NULL) {

        if(data < root->info)
            root = root->llink;

        else if(data > root->info)
            root = root->rlink;

        else return root;

    }

    return (void *)0;
}

struct node * getInorderSucessor(struct node *root,int data) {

    //getting refernce to the node
    struct node * node1 = getNodeByInfo(head,data);
    struct node *succ;
    struct node *maxNode = getMaxNode(head);

    if(node1 == NULL) {
        printf("Node does not exist");
        return (void *)0;
    }

    //if the node is max node
    if(maxNode->info == node1->info) {
        printf("\nSucessor does not exist. It is the largest node");
        return (void *)0;
    }

    //successor will be min value if node1 have right child
    if(node1->rlink != NULL) {
        return  getMinNode(node1->rlink);
    }

    //finding nearest parent for which node will be in its left subtree
    while(root != NULL) {

        if(node1->info < root->info) {
            succ = root;
            root = root->llink;
        }

        else if(node1->info > root->info)
            root = root->rlink;

        else break;
    }

    return succ;
}

struct node *getInorderPredecessor(struct node *root,int data) {

    struct node * node1 = getNodeByInfo(head,data);
    struct node *succ;
    struct node *minNode = getMinNode(head);

    if(node1 == NULL) {
        printf("Node does not exist");
        return (void *)0;
    }

    //if the node is min node
    if(minNode->info == node1->info) {
        printf("\nPredecessor does not exist. It is the smallest node");
        return (void *)0;
    }

    //if node has left subtree ..return largest node in left subtree
    if(node1->llink != NULL) {
        return getMaxNode(node1->llink);
    }

    while(root != NULL) {

        if(node1->info > root->info){
            succ = root;
            root = root->rlink;
        }
        else if(node1->info < root->info)
            root = root->llink;

        else break;
    }
    return succ;
}



void delete(struct node *root,int data) {

    struct node *parent;
    struct node *temp;

    if(head == NULL) {
        printf("\nTree is empty");
        return;
    }

    //searching if node is present or not
    temp = getNodeByInfo(head,data);
    if(temp == NULL) {
        printf("\nNode does not exist");
        return;
    }


    while(root != NULL) {

        if(data < root->info) {
            parent = root;
            root = root->llink;
        }
        else if (data > root->info) {
            parent = root;
            root = root->rlink;
        }
        else break;
    }

    //case 1: when node neither have left nor right child
    if(root->llink == NULL && root->rlink == NULL) {
        if(parent->llink == root)
            parent->llink = NULL;

        else if(parent->rlink == root)
            parent->rlink = NULL;

        free(root);
        return;
    }

    //case 2: when node has both child
    else if(root->llink!=NULL && root->rlink!=NULL) {

        //getting max node from left subtree
        struct node *leftMax = getMaxNode(root->llink);
        root->info = leftMax->info;
        delete(root->llink,leftMax->info);

    }
    //case 3: node have one child only
    else {

        //node has left child
        if(root->llink!=NULL)  {

            //node is in right subtree of parent
            if(parent->rlink == root)
                parent->rlink = root->llink;

            //node is in left subtree of parent
            else if(parent->llink == root) {
                parent->llink = root->llink;
            }

            free(root);
            return;
        }

        //node has right child
        else if(root->rlink!=NULL)  {

        //node is in right subtree of parent
            if(parent->rlink == root)
                parent->rlink = root->rlink;

        //node is in left subtree of parent
            else if(parent->llink == root) {
                parent->llink = root->rlink;
            }

            free(root);
            return;
        }

}
}

int main()
{

    int choice,data;

    while(1) {

        printf("\n\n1. Insert\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. Search for a node");
        printf("\n6. Delete a node\n7. Find Maximum Node\n8. Find Minimum Node\n9. Find Inorder sucessor\n10. Find Inorder Predecessor  \n0. Exit the program\n");
        printf("\nEnter your choice:  ");
        scanf("%d",&choice);


    switch(choice){

        case 1:
                printf("\nEnter data to be entered ");
                scanf("%d",&data);
                insert(head,data);
                break;

        case 2:
                displayPreorder(head);
                break;

        case 3:
                displayInorder(head);
                break;

        case 4:
                displayPostorder(head);
                break;

        case 5:
                printf("\nEnter data to be searched ");
                scanf("%d",&data);
                struct node * found = getNodeByInfo(head,data);
                if(found != NULL)
                    printf("\nNode found: %d",found->info);
                else printf("\nNode not found");
                break;

        case 6:
                printf("\nEnter the data to be deleted  ");
                scanf("%d",&data);
                delete(head,data);
                break;

        case 7:
                printf("Max. element is %d",(getMaxNode(head))->info);
                break;

        case 8:
                printf("Min. element is %d",(getMinNode(head))->info);
                break;


        case 9:
                printf("\nEnter the element you want sucessor of? ");
                scanf("%d",&data);
                struct node * in = getInorderSucessor(head,data);

                if(in != NULL)
                    printf("\nInorder successor of %d is %d ",data,in->info);
                break;

        case 10:
                printf("\nEnter the element you want predecessor of? ");
                scanf("%d",&data);
                struct node * pre = getInorderPredecessor(head,data);

                if(pre != NULL)
                    printf("\nInorder predecessor of %d is %d ",data,pre->info);
                break;


        case 0:
                exit(0);
                break;

    }

    }
    return 0;
}
