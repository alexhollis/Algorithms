/********************************************
Name:   		Alex Hollis
Course: 		CSCE 4110.001
Assignment:     Graph Generating Function for use with Dijkstra's & Floyd's
Due Date:       May 01, 2016 at 11:55PM
 ********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int generateCost()
{
    int cost;
    
   
    cost = rand() % 30;         //capping max cost at 30, didn't feel it needed to be larger
    
    return cost;
    
}

int chooseNode(int loc, int size)
{
    int node;
   
    
    while(1)
    {
    node = rand() % size;
    if(node != loc) break;      // not choosing a node that is the same row we're looking at, as cost to self is zero.
    else continue;
    }
    
    return node;
    
}

int setEdges()
{
    int edges;
    
    edges = rand() % 4 ;     // 1-3 edges per row.
    
    if(edges == 0 ) edges = 1;
    
    return edges;
    
}

void newGraph(int size, int type)           // type = 0 --> undirected, type = 1 --> directed 
{
    
    int graph[size][size];     // A 2-D table to store our cost matrix.
    int i, j;
    int count = 0, limit = 3;       // I want no more than 3 edges per node; personal choice.
    int node, cost;
    //initialize the cost matrix.
    
    for(i=0; i< size; i++)
        for(j=0; j<size; j++)
            graph[i][j] = 0;        // initialize all spaces to zero to start.
    //
    
    
    // build the cost matrix
    
    for(i=0; i<size; i++)
    {
        limit = setEdges();     // pick number of edges for each row, will be 0-3 randomly.
        for(j=0; j<size; j++)
        {
            if(graph[i][j]==0)      // will not write over spaces already filled in
            {
              
                if(count <= limit)
                {
                    if(type == 1)       // directed
                    {
                    node = chooseNode(i,size);
                    cost = generateCost();
                    if(graph[i][node] == 0)
                    {
                    graph[i][node] = cost; 
                    count++;
                    }
                    }
                    if(type == 0)       // undirected
                    {
                    node = chooseNode(i,size);
                    cost = generateCost();
                    if(graph[i][node] == 0)
                    {
                    graph[i][node] = cost; 
                    graph[node][i] = cost;
                    count++;  
                    }
                    }
                }
                
            }
            
            
        }
        count = 0;      // reset count for new row.
    }
    
    // build
    
    
    // output the graph
    
    freopen("input.dat", "w", stdout);
    
    for(i=0; i< size; i++)
    {
        for(j=0; j< size; j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    //
    
    
    
}   //new graph