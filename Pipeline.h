#ifndef PIPELINE_H
#define PIPELINE_H
#include "ConnectorFactory.h"
#include "Transformation.h"
#include "RunCheckpoint.h"

#include <vector>
#include <string>
#include <iostream>

class Pipeline {
    public:
        Pipeline(ConnectorFactory*);
        void run();
        void addStep(Transformation*);
        void connect();
        void transform();
        virtual void extract() = 0;
        virtual void load() = 0;
        RunCheckpoint* createCheckpoint();
        void restoreCheckpoint(RunCheckpoint*);
        ~Pipeline();

    protected:
        ConnectorFactory* factory;
        std::vector<Transformation*> steps;
        int stage;
        std::vector<std::string> records;
    };

#endif // PIPELINE_H