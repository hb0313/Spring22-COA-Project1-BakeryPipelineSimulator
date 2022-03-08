#include <stdio.h>
#define SIZE 12
#define CLOCK 12

int pipeStage[SIZE];

/* Double ended queue structure defination declared as global */
// typedef struct pipe
// {
// int data[SIZE];
// int pipeRear,pipeFront;
// }pipe;

// /* Operations functions for double ended queue */
// void initialize(pipe *p);
// int empty(pipe *p);
// int full(pipe *p);
// void enqueueR(pipe *p,int x);
// void enqueueF(pipe *p,int x);
// int pipeF(pipe *p);
// int pipeR(pipe *p);
// void print(pipe *p);
int bakeryLine(FILE* FILENAME);
void LineStatus();
int nextOrder(int order);
void clkCycle();
void initializePipe();
void printPipe();

// struct pipe pipePointer;

char buffer[10000];
int status = 0;                 
    
FILE *fetchRequest;

/* Bakery status variables */
int bakery_time;
int no_request;
int bagel_baked;
int baguette_baked;
int baking_count;
float performance;
