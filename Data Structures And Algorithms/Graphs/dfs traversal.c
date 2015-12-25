#include<stdio.h>
#include<stdbool.h>

#define V 7
#define startingVertex 0

int top=-1;

void push(int stack[],int data) {
    if(top>=V)
        printf("\nStack is full");
    else {
        stack[++top] = data;
    }
}

int pop(int stack[]) {
    if(top<=-1)
        printf("\nStack is empty");
    else {
        int x = stack[top];
        top--;
        return x;
    }
}

void DFS(int graph[V][V],int stack[],int start) {

    int i;
    int visited[V];

    for(i=0; i<V; i++) {
        visited[i] = 0;
    }

    push(stack,start);

    while(top>-1) {
        int x = pop(stack);

        if(!visited[x])
        {
            printf(" %d ",x);
            visited[x] = 1;

            for(i=V-1; i>=0; i--) {
                if(graph[x][i]!=0 && visited[i] == 0){
                    push(stack,i);
                }
            }
        }
    }
}


int main() {

    int i,stack[V];
    int graph[V][V] =  { {0, 1, 1, 0, 0, 0, 0},
                        {1, 0, 0, 1, 1, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0 ,0},
                        {0, 0, 1, 1, 1, 0, 0}};

    DFS(graph,stack,startingVertex);

    return 0;
}
