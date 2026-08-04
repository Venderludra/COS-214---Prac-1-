#include "DeduplicateStep.h"
#include <iostream>
using namespace std;


DeduplicateStep::DeduplicateStep() : Transformation("dedup"){
    //nothing here initialization already occured
}


Transformation* DeduplicateStep::clone(){
    return new DeduplicateStep(*this);
}

vector<string> DeduplicateStep::apply(vector<string> _records){
    if(_records.empty()) 
        return {};//prevents temp from crashing when/if _records is empty
    vector<string> noDupes = {};
    string temp = _records.at(0);
    
    for(int i = 1 ; i < _records.size() ; i++){
        if(temp != _records.at(i)){
            noDupes.push_back(temp);
            temp = _records.at(i);
        }
        
        if(i == _records.size() - 1){
            noDupes.push_back(temp);
        }
    }

    return noDupes;
}