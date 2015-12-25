#include<stdio.h>

#define V 5
#define startingVertex 0

void prim(int graph[V][V],int start) {

    int i,j,counter=0,temp,min,totalWeight=0;
    int minVertex;

    int selected[V];

    for(i=0; i<V; i++) {
        selected[i] = 0;
    }
    selected[start] = 1;

    while(counter<V-1) {

    min = 32000;
    for(i=0;i<V;i++) {

            if(selected[i])
            {
            for(j=0;j<V;j++) {

                if(graph[i][j]<min && graph[i][j] && !selected[j]) {
                    min = graph[i][j];
                    minVertex = j;
                    temp=i;
                }
            }
        }
    }

    selected[minVertex] = 1;
    printf("\nEdge: %d - %d  Weight: %d",temp,minVertex,graph[temp][minVertex]);
    totalWeight+= graph[temp][minVertex];
    counter++;
    }

    printf("\n\nTotal weight of minimum spanning tree is: %d",totalWeight);

}


int main() {

int i;
int graph[V][V] = {{0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0}
                };


prim(graph,startingVertex);

return 0;
}
