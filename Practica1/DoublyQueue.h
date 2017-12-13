#ifndef NODE
#define NODE
#include <string>

typedef struct node node;
using namespace std;

class Plane;
class Passenger;

struct node{
    Plane *data;
    Passenger *passg;
    struct node *next;
    struct node *prev;
};

typedef struct{
    node *first;
    node *last;
    int size;
}Dqueue;

typedef struct{
    node *first;
    node *last;
    int size;
}Squeue;

typedef struct{
    node *first;
    int size;
}DoublyC;


Dqueue *wen();
Squeue *ween();
void insert(Dqueue *List, Plane *data);
void insert(Squeue *List, Passenger *data);
void insert(DoublyC *List, Plane *data);
void remove(Dqueue *List);
void remove(Squeue *List);
void remove(DoublyC *List);
bool IsEmpty(Dqueue *List);
bool IsEmpty(Squeue *List);
bool IsEmpty(DoublyC *List);
void Print(Dqueue *List);
void Print(Squeue *List);

#endif // NODE
