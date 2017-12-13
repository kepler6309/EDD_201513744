#include "mainwindow.h"
#include  <stdlib.h>
#include "systemport.h"
#include "objects.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;    
    w.show();
    return a.exec();
}

void InsertPlane(Dqueue *list)
{
    int type = rand()%3;
    switch(type)
    {
    case 0:
    {
        Plane *dock = new Plane("Pequeño",5+rand()%6,1,1+rand()%3);
        insert(list,dock);
    }
        break;
    case 1:
    {
        Plane *dock = new Plane("Mediano",15+rand()%11,2,2+rand()%3);
        insert(list,dock);
    }
        break;
    case 2:
    {
        Plane *dock = new Plane("Grande",30+rand()%11,3,3+rand()%4);
        insert(list,dock);
    }
        break;
    }
}

void InsertPassg(Squeue *List, Plane *Dock)
{
    for(int i = 0; i<Dock->passg;i++)
    {
        Passenger *NewPassg = new Passenger(1,1,1,1);
        insert(List,NewPassg);
    }
}
