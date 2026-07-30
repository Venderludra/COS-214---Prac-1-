#include "AggregateByRegionStep.h"
#include <iostream>
using namespace std;

AggregateByRegionStep::AggregateByRegionStep() : Transformation("aggregate"){
    //initialization already occured
}

Transformation* AggregateByRegionStep::clone(){
    return new AggregateByRegionStep(*this);
}

vector<string> AggregateByRegionStep::apply(vector<string> _words){
    int size = _words.size();
    string count = "COUNT=";
    count += to_string(size); // update count to count = "COUNT=whatever size"

    return {count};
}