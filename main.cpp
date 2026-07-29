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
    ConnectorFactory** pf = new ConnectorFactory*[3];
    pf[0] = new PostgresFactory();
    pf[1] = new CsvFactory();
    pf[2] = new RestApiFactory();

    Connector* f  = nullptr;

    for(int i = 0 ; i < 3 ; i++){
        f = pf[i]->createConnector();
        cout << "Source of Connector: " << f->getSource() << endl;
        for(string data : f->extract()){
            cout << data << endl;
        }
        delete f;
        f = 0;
    }

    for(int i = 0 ; i < 3 ;i++){
        delete pf[i];
    }

    delete[] pf;
    return 0 ;
}