#include "Connector.h"
#include<iostream>
using namespace std;

Connector::Connector(string _source){
    source = _source;
}

Connector::~Connector(){
    //delete this;
}

string Connector::getSource(){
    return source;
}

