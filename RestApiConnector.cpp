#include "RestApiConnector.h"
using namespace std;

RestApiConnector::RestApiConnector(): Connector("restapi"){}

vector<string> RestApiConnector::extract(){
    if(Connector::source == "restapi"){
        return {"API:44","API:45","API:45"};
    }
    return {};
}