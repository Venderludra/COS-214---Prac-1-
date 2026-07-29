#include "CsvFactory.h"
#include <iostream>
using namespace std;

Connector* CsvFactory::createConnector(){
    return new CsvConnector();
}