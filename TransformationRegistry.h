#ifndef TRANSFORMATIONREGISTRY_H
#define TRANSFORMATIONREGISTRY_H
#include "Transformation.h"
#include <map>

class TransformationRegistry{
    public:
        void registerStep(std::string,Transformation*);
        Transformation* create(std::string);
        ~TransformationRegistry();

    private:
        std::map<std::string,Transformation*> prototypes;
};

#endif