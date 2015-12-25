#include<stdio.h>

#define V 7
#define Nqueue 30
#define startingVertex 0


void BFS(int graph[V][V],int start) {

    int i;
    int discovered[V],queue[Nqueue];
    int front=0,rear=0;

    for(i=0; i<V; i++) {
        discovered[i] = 0;
    }

    queue[rear++] = start;      //enqueue

    while( front<rear ) {

        start =  queue[front++];    //dequeue

        if( !discovered[start] ) {

        printf(" %d ",start);
        discovered[start] = 1;

        for(i=0;i<V;i++) {
            if(graph[start][i]!=0 && !discovered[i]) {
                queue[rear++] = i;      //enqueue
                }
            }
        }
    }
}

int main() {

int i;
int graph[V][V] =  {{0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 1, 1, 1, 0},
                    {1, 0, 0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0, 0 ,0},
                    {0, 0, 1, 1, 1, 0, 0}};

BFS(graph,startingVertex);

return 0;
}
