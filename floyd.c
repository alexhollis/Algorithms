/********************************************
Name:   		Alex Hollis
Course: 		CSCE 4110.001
Assignment:     Floyd's Algorithm
Due Date:       May 01, 2016 at 11:55PM
 ********************************************/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

void floyds(int nodes, int (*Table)[nodes]) {
    int i, j, k;
    for (k = 0; k < nodes; k++) {
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                if ((Table[i][k] * Table[k][j] != 0) && (i != j)) {
                    if ((Table[i][k] + Table[k][j] < Table[i][j]) || (Table[i][j] == 0)) {
                        Table[i][j] = Table[i][k] + Table[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < nodes; i++) {
        printf("\nMinimum Cost With Respect to Node: %d |", i);
        for (j = 0; j < nodes; j++) {
            printf("\t%d\t", Table[i][j]);
        }

    }




}

int experiment2() {

    int nodes;
    struct timeval start, end;
    long mtime, secs, usecs;
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    printf("\n\nThe rest of this experiment will use the input file [input.dat] without user input\n\n");


    int table[nodes][nodes];
    int i, j;
    freopen("input.dat", "r", stdin);
    gettimeofday(&start, NULL);
    for (i = 0; i < nodes; i++) //row
    {
        for (j = 0; j < nodes; j++) //col
        {
            scanf("%d", &table[i][j]);
        }
    }
    
    floyds(nodes, table);
    gettimeofday(&end, NULL);
    
    secs  = end.tv_sec  - start.tv_sec;
    usecs = end.tv_usec - start.tv_usec;
    mtime = ((secs) * 1000 + usecs/1000.0) + 0.5;
    printf("\n\n\n\nElapsed time: %ld millisecs\n", mtime);


    return 0;
}