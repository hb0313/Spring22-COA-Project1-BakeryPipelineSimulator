#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "pipelineHeader.h"


void initializePipe()
{
    for (int i = 0; i < SIZE; i++)
        pipeStage[i] = 99;
}

void LineStatus ()
{
    printf("\n Inside LineStatus");
    bool empty = false;
    int i, order;
    printf("\n");
    for (i=0; i<SIZE; i++) 
    {
        if (pipeStage[i] == 0 || pipeStage[i] == 99)    // 0 is no_request and 99 is empty. We check if there is any item in pipline
        { 
            empty = true;
        }
        else 
        {
            empty = false;
            break;
        }

    }
        if (empty == false)
            clkCycle();
        else 
        {
            printPipe();
            while (status == 0)
            {
            pipeStage[0] = nextOrder(order);
            }
            clkCycle();
        }
}


int nextOrder(int order)
{
    fscanf(fetchRequest,"%s",buffer);
    if(feof(fetchRequest)) {
        status = 1;
        return 0;
    }
        if(strcmp(buffer,"Bake-Bagel") == 0) 
        {
            order = 1;
            bagel_baked++;
            baking_count++;
            bakery_time++;
            return order;
        }
        else if(strcmp(buffer,"Bake-Baguette") == 0)
        {
            order = 1;
            baguette_baked++;
            baking_count++;
            bakery_time++;
            return order;
        }
        else if(strcmp(buffer,"No-Request") == 0)
        {
            no_request++;
            bakery_time++;
            order = 0;
            return order;
        }
}

void clkCycle()
{
    int IP, temp = pipeStage[SIZE-1];
    for (IP = SIZE-1; IP > 0; IP--)
    {
        if(IP == 0 && baking_count == 1000)
            bakery_time = bakery_time+10;
        if(IP == 9 && baking_count == 10)
            bakery_time = bakery_time + 1;
        pipeStage[IP] = pipeStage[IP-1];
    }
    pipeStage[0] = 99;
}

int main(int argc, char *argv[])  
{
    initializePipe();
    fetchRequest = fopen(argv[1], "r"); 
    if(fetchRequest == NULL)
        printf("\n Error opening file!");
    else
        LineStatus();
    fclose(fetchRequest);
                     
    
    // Check if the file is opened successfully
    
    //output formats
    printf("\nBaking count: %d\n", baking_count);
    printf(" -Bagel baked: %d\n", bagel_baked);
    printf(" -Baguette baked: %d\n", baguette_baked);
    printf("No request: %d\n", no_request);

    printf("\nHow many minutes to bake: %d\n", bakery_time);
    //performance = baking_count/bakery_time;
    printf("\nPerformance (bakes/minutes): %.2f\n", performance);

    return 0;
}