#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DoublyQueue.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

//---cola doble enlazada---

Dqueue *wen()
{
    Dqueue *Plns = (Dqueue*)malloc(sizeof(Dqueue));
    Plns->first = NULL;
    Plns->last = NULL;
    return  Plns;
}


void insert(Dqueue *List, Plane *data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(IsEmpty(List))
    {
        List->first = List->last = newNode;
        List->first->next = NULL;
        List->last->prev = NULL;
        List->size++;
    }
    else
    {
        newNode->next = List->last;
        List->last->prev = newNode;
        List->last = newNode;
        List->first->next = NULL;
        List->last->prev = NULL;
        List->size++;
    }
}

void remove(Dqueue *List)
{
    if(!IsEmpty(List))
    {
        List->first = List->first->prev;
        free(List->first->next);
        List->first->next = NULL;
        List->size--;
    }
}

bool IsEmpty(Dqueue *List)
{
    return List->first == NULL;
}

void Print(Dqueue *List)
{
    FILE *fp;
    fp = fopen("grafica.dot","w");    
    fprintf(fp, "%s", "digraph G{\n");
    node *aux = (node*)malloc(sizeof(node));
    aux = List->last;
    while(aux->next!=NULL)
    {
        fprintf(fp, "%d", aux->data);
        fprintf(fp, "%s", "->");
        fprintf(fp, "%d", aux->next->data);
        fprintf(fp, "%s", "\n");
        fprintf(fp, "%d", aux->next->data);
        fprintf(fp, "%s", "->");
        fprintf(fp, "%d", aux->data);
        fprintf(fp, "%s", "\n");
        aux = aux->next;

    }
    fprintf(fp, "%s", "}");
    fclose ( fp );
    system("dot -Tpng grafica.dot -o grafica.png");

}


//----cola simple enlazada----

void insert(Squeue *List, Passenger *data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->passg = data;
    if(IsEmpty(List))
    {
        List->first = List->last = newNode;
        List->last->next = NULL;
        List->size++;
    }
    else
    {
        List->last->next = newNode;
        List->last = newNode;
        List->size++;
    }
}

void remove(Squeue *List)
{
    if(!IsEmpty(List))
    {
        node *aux = List->first;
        List->first = List->first->next;
        free(aux);
        List->size--;
    }
}


bool IsEmpty(Squeue *List)
{
    return List->first == NULL;
}

//---circular doblemente enlazada---

void insert(DoublyC *List, Plane *data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    if(IsEmpty(List))
    {
        List->first = newNode;
        List->first->next = List->first;
        List->first->prev = List->first;
        List->size++;
    }
    else
    {
        newNode->next = List->first->next;
        List->first->next->prev = newNode;
        List->first->next = newNode;
        newNode->prev = List->first;
        List->size++;
    }
}

void remove(DoublyC *List)
{
    if(!IsEmpty(List))
    {
        //solo dos elementos
        List->first->next = List->first;
        List->first->prev = List->first;
        List->size--;

        //mas de dos
        List->first->next->next->prev = List->first;
        List->first->next = List->first->next->next;
        List->size--;
    }
}

bool IsEmpty(DoublyC *List)
{
    return List->first == NULL;
}
