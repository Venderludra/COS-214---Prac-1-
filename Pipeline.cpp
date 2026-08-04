#include "Pipeline.h"
#include <iostream>
using namespace std;

Pipeline::Pipeline(ConnectorFactory* factory) : factory(factory), stage(0) {
    //constructor
}

void Pipeline::run(){//run; template method: fixed lifecycle
    connect();
    extract();
    transform();
    load();
}

void Pipeline::addStep(Transformation* step) {
    steps.push_back(step);
}

void Pipeline::transform() {
    // Implementation of the transform method
    for (auto step : steps) {
        //step->apply(records);
        records = step->apply(records);
    }
    stage = 3;
}

void Pipeline::connect() {
    // Implementation of the connect method
    Connector* c1 = factory->createConnector();
    cout << "Connecting to " << c1->getSource()<< endl;
    stage =  1;
    delete c1;
}

RunCheckpoint* Pipeline::createCheckpoint() {
    return new RunCheckpoint(stage, records);
    //return nullptr; -> gives us seg-faults
}

void Pipeline::restore(RunCheckpoint* checkpoint) {
    //here we have the originator restoring the memento using wide interface
    if(checkpoint!=nullptr){
        //first check that the checkpoinnt actually exists before we attempt to use it
        stage = checkpoint->getStage();
        records = checkpoint->getRecords();
    }
}

Pipeline::~Pipeline() {
    // Implementation of the destructor
    for (auto step : steps) {
        delete step;
    }

    delete factory;
    
}
