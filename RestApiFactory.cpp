#include "RestApiFactory.h"
#include <iostream>
using namespace std;

Connector* RestApiFactory::createConnector(){
    return new RestApiConnector();
}