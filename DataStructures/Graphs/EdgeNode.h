#pragma once

typedef struct
{
    int y;                 //adjacency info
    int weight;            //edge weight if any
    struct edgenode* next; //next edge in list
}edgenode;