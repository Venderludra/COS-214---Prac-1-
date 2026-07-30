#include "Transformation.h"
#include <iostream>
using namespace std;

Transformation::Transformation(string _name){
    name = _name;
}

string Transformation::getName(){
    return name;
}

Transformation::~Transformation(){
    //for now it won't do anything
}