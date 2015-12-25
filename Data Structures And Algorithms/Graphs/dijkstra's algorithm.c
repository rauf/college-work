#include<stdio.h>

#define V 9
#define startingVertex 0

void dijkstra(int graph[][V],int start) {

    int i,counter=0,cost[V],set[V];

    for(i=0;i<V;i++) {
        cost[i] = 32000;
        set[i] = 0;
    }

    cost[start] = 0;

    while(counter<V) {
        int min = 12345;

            for(i=0;i<V;i++) {
                if(cost[i]<min && !set[i] ) {
                    min = cost[i];
                    start = i;
                }
            }

        set[start] = 1;

        for(i=0;i<V;i++) {
            if(graph[start][i]!=0) {
                int temp = cost[start] + graph[start][i];
                if(temp<cost[i]) {
                    cost[i] = temp;
                }
            }
        }
    counter++;
    }


    for(i=0;i<V;i++) {
        printf("\nVertex: %d  Distance: %d ",i,cost[i]);
    }
}

int main() {

    int i;

    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph,startingVertex);

    return 0;
}
