#include "StreamingPipeline.h"
#include <iostream>

using namespace std;

void StreamingPipeline::extract() {
    Connector* c1 = factory->createConnector();
    vector<string> data = c1->extract();
    records.insert(records.end(), data.begin(), data.end());

    cout << "Streaming extract:" << records.size() << " records" << endl;
    stage = 2;
    delete c1;
}

void StreamingPipeline::load() {
    cout << "Streaming load:" << records.size() << " records streamed." << endl;
    stage= 4;
}
