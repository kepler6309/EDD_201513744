#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

struct node
{
    int data;
    struct node *next;
    struct node *prev;

};

typedef struct
{
    struct node *first;
    struct node *last;

}Doubly;

Doubly *linkedList;

void push(Doubly *List, int data);
void pop(Doubly *List,int data);
void print(Doubly *List);
void option();
int menu();

#endif // HEAD_H_INCLUDED
