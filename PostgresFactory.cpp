#include "PostgresFactory.h"
#include <iostream>
using namespace std;

Connector* PostgresFactory::createConnector(){
    return new PostgresConnector();
}