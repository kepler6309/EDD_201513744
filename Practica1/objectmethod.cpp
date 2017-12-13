#include <iostream>
#include <stdlib.h>
#include "objects.h"

Plane::Plane(string type_, int passg_, int turnD_, int turnM_)
{
    type = type_;
    passg = passg_;
    turnD = turnD_;
    turnM = turnM_;
}

Passenger::Passenger(int id_,int lugg_,int doc_,int turnR_)
{
    id = id_;
    lugg = lugg_;
    doc = doc_;
    turnR = turnR_;
}
