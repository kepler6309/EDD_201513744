#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{

    linkedList = malloc(sizeof(Doubly));
    linkedList->first = NULL;
    linkedList->last = NULL;
    option();
    return 0;
}

int menu()
{
    int selected;
    printf("1. Ingresar datos:\n");
    printf("2. Eliminar:\n");
    printf("3. Imprimir lista:\n");
    printf(">> ");
    scanf("%d",&selected);
    return selected;
}

void option()
{
    int dat = 0;
    int pas = 0;
    while(pas<4)
    {
        switch(pas = menu())
        {
        case 1:
            printf("ingrece el numero:\n");
            printf(">> ");
            scanf("%d",&dat);
            push(linkedList,dat);
        break;
        case 2:
            printf("ingrece el numero a eliminar:\n");
            printf(">> ");
            scanf("%d",&dat);
            pop(linkedList,dat);
        break;
        case 3:
            print(linkedList);
        break;
        }

    }
}

void push(Doubly *List, int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(List->first == NULL)
    {
        List->first = List->last = newnode;
    }
    else
    {
        newnode->next = linkedList->first;
        List->first->prev = newnode;
        List->first = newnode;
    }

}

void print(Doubly *List)
{
    struct node *aux = (struct node*)malloc(sizeof(struct node));
    aux = List->last;
    while(aux!=NULL)
    {
        printf("valor: %d\n",aux->data);
        aux = aux->prev;
    }
    free(aux);
}

void pop(Doubly *List, int data)
{
    struct node *aux = (struct node*)malloc(sizeof(struct node));
    aux = List->first;
    if(List->first == NULL)
    {
        printf("la lista esta vacia");
    }
    else
    {
        while(aux!=NULL)
        {
            if(aux->data==data)
            {
                if(aux->prev==NULL)
                {
                    List->first = aux->next;
                    List->first->prev = NULL;
                    break;
                }
                else if(aux->next==NULL)
                {
                    List->last = aux->prev;
                    List->last->next = NULL;
                    break;
                }
                else
                {
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    break;
                }

            }
            aux = aux->next;
        }
        free(aux);

    }
}
