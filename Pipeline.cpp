#include "Pipeline.h"
#include <iostream>
using namespace std;

Pipeline::Pipeline(ConnectorFactory* factory) : factory(factory), stage(0) {
    // Constructor implementation
}

void Pipeline::run(){
    // Implementation of the run method
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
        step->apply(records);
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
    // Implementation of the createCheckpoint method
    return nullptr;
}

void Pipeline::restoreCheckpoint(RunCheckpoint* checkpoint) {
    // Implementation of the restoreCheckpoint method
}

Pipeline::~Pipeline() {
    // Implementation of the destructor
    for (auto step : steps) {
        delete step;
    }

    delete factory;
    
}
