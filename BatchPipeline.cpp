#include "BatchPipeline.h"
#include <iostream>
using namespace std;

//BatchPipeline::BatchPipeline(ConnectorFactory* factory) : Pipeline(factory) {}

void BatchPipeline::extract() {
    Connector* c1 = factory->createConnector();
    vector<string> data = c1->extract();
    records.insert(records.end(), data.begin(), data.end());

    cout << "Batch extract: " << records.size() << " records" << endl;
    stage = 2;
    delete c1;
}

void BatchPipeline::load() {
    cout << "Batch load:" << records.size() << " records written" << endl;
    stage= 4;
}
