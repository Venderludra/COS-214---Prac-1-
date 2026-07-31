#include "CsvConnector.h"
using namespace std;


CsvConnector::CsvConnector() : Connector("csv"){}

vector<string> CsvConnector::extract(){
    if(Connector::source == "csv"){
        return {"CSV:x1","CSV:x2","CSV:x3","CSV:x3"};
    }
    return {};
}