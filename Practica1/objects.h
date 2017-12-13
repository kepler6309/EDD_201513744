#ifndef OBJECTS
#define OBJECTS
#include <string>
#include "DoublyQueue.h"

class Plane
{

public:
    std::string type;
    int passg,turnD,turnM;
    Squeue lpassg;

    Plane(std::string type_,int passg_,int turnD_,int turnM_);
    bool PassTurn();
};

class Passenger
{
public:
    int id,lugg,doc,turnR;
    Passenger(int id_,int lugg_,int doc_,int turnR_);
};

class DeskR
{
    Squeue passg;
};
#endif // OBJECTS

