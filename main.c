/********************************************
Name:   		Alex Hollis
Course: 		CSCE 4110.001
Assignment:     Main Function File
Due Date:       May 01, 2016 at 11:55PM
 ********************************************/

/* 
 * File:   main.c
 * Author: Alex Hollis
 *
 * Created on March 28, 2016, 11:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */

int experiment1();
int experiment2();
void newGraph(int, int);

int main() {
    srand(time(NULL));
    int choice=0, size=0, type=0;
    
    printf("Which program to run: \n");
    printf("1 - Dijkstra's Algorithm\n");
    printf("2 - Floyd's Algorithm\n");
    printf("3 - Generate a new graph\n");
    printf("4 - Quit Program\n");
    printf("/> ");
    
     
    scanf("%d", &choice);
    printf("\n");
    if(choice == 1)
        experiment1();
    if(choice == 2)
        experiment2();
    if(choice == 3)
    {
      printf("Enter number of vertices: ");
      scanf("%d",&size);
      printf("Choose type of graph (0 --> undirected, 1 --> directed ): ");
      scanf("%d",&type);
      if(type != 0 || type != 1) type = 1;  //default directed graph is user gives garbage input.
      newGraph(size,type);
      continue;
    }
    if(choice == 4) break;

    
 return (EXIT_SUCCESS);

}

