#include "Connector.h"
#include "ConnectorFactory.h"
#include "CsvFactory.h"
#include "PostgresConnector.h"
#include "PostgresFactory.h"
#include "RestApiConnector.h"
#include "RestApiFactory.h"
#include <iostream>

using namespace std;

int main(){
    RestApiFactory pf;
    Connector* f = pf.createConnector();

    for(string data : f->extract()){
        cout << data << endl;
    }

    delete f ;
    return 0 ;
}