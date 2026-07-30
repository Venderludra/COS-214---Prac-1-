#include "TransformationRegistry.h"
#include <iostream>
using namespace std;

void TransformationRegistry::registerStep(string _key,Transformation* prototype){
    if(prototypes.find(_key) != prototypes.end()){
        delete prototypes[_key];
    }

    prototypes[_key] = prototype;
}

Transformation* TransformationRegistry::create(string _key){
    if(prototypes.find(_key) != prototypes.end()){
        return nullptr;
    }
    return prototypes[_key]->clone(); //creates the designated prototype based on the 
}

TransformationRegistry::~TransformationRegistry(){
    for(map<string,Transformation*>::iterator it = prototypes.begin() ; it != prototypes.end() ; ++it){
        delete it->second;
    }
}