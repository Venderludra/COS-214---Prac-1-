#include "Transformation.h"
#include <iostream>
using namespace std;


Transformation::Transformation(string _name){
    name = _name;
}

Transformation::Transformation(const Transformation& t1) : Transformation(t1.getName()){
}

string Transformation::getName() const{
    return name;
}

Transformation::~Transformation(){
    //for now it won't do anything
}
