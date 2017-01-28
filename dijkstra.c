/********************************************
Name:   		Alex Hollis
Course: 		CSCE 4110.001
Assignment:     Dijkstra's Algorithm
Due Date:       May 01, 2016 at 11:55PM
 ********************************************/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#define infinity 998


int prev[10000];

void printPath(int index) {
    if (prev[index] > 0) {
        printPath(prev[index]);
    }
    if (prev[index] == 0 || prev[index] == -1)
        printf("1 ");


    printf("%d ", index + 1);
}

void lowestCost(int nodes, int startN, int cost[nodes][nodes], int *distance) //Dijkstra's Algorithm Function
{
    int i, j, count, k, flag[nodes], min;

    /////////////////////////////


    //////////////////////////////


    for (i = 0; i < nodes; i++)
        distance[i] = infinity; //initialize all nodes to infinity.

    for (i = 0; i < nodes; i++) {
        flag[i] = 0;
        distance[i] = cost[startN][i]; //fill in initial known distances from start node to neighbors.
        if (distance[i] != infinity) //valid edge found, take time
        {




        }

    }
    count = 0;
    while (count <= nodes) {
        min = 999;

        for (j = 0; j < nodes; j++) {
            if (distance[j] < min && !flag[j])
                min = distance[j], k = j; // set smallest edge to current node
        }

        flag[k] = 1;
        count++;

        for (j = 0; j < nodes; j++) {
            if (((distance[k] + cost[k][j] < distance[j])) && !flag[j]) //new route found, shorter distance calculated.
            {
                distance[j] = distance[k] + cost[k][j]; //new path set
                prev[j] = k; //update path



            }
        }
    }

    //////////// 	PRINT	///////////////

    int z;

    for (z = 1; z < nodes; z++) {
        if (distance[z] != infinity) {
            printPath(z);
            printf("\n");

        }

    }
    //////////////////////////////////////
}

int experiment1() {
    int nodes, startN, i, j;
    struct timeval start, end;
    double mtime, secs, usecs; 
   
    printf("Enter number of nodes: ");
    scanf("%d",&nodes);
    
    int  cost[nodes][nodes], distance[nodes];
    
    printf("\n\nThe remainder of this experiment will use the file input.dat, and not require user interaction\n\n");
    
    freopen("input.dat", "r", stdin);
    
  
    gettimeofday(&start, NULL);
    for (i = 0; i < nodes; i++) // scan in cost matrix
    {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = infinity;
        }
    }

    for (i = 0; i < nodes; i++)
        prev[i] = -1;

    startN = 0;
    printf("Dijkstra's Algorithm - Experiment: \n\n\n");
    lowestCost(nodes, startN, cost, distance); // run Dijkstra's Algorithm

    gettimeofday(&end, NULL);
     
    secs  = end.tv_sec  - start.tv_sec;
    usecs = end.tv_usec - start.tv_usec;
    mtime = ((secs) * 1000 + usecs/1000.0) + 0.5;
    printf("Elapsed time: %lf millisecs\n", mtime);
     
    
   

    return 0;
}