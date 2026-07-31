#include "PostgresConnector.h"
using namespace std;

PostgresConnector::PostgresConnector() : Connector("postgres"){}

vector<string> PostgresConnector::extract(){
    if(Connector::source == "postgres"){
        return {"PG:001","PG:002","PG:002","PG:003"};
    }
    return {};
}