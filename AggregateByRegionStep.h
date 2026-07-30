#ifndef AGGREGATEBYREGIONSTEP_H
#define AGGREGATEBYREGIONSTEP_H
#include "Transformation.h"

class AggregateByRegionStep : public Transformation{
    public:
        AggregateByRegionStep();
        Transformation* clone() override;
        std::vector<std::string> apply(std::vector<std::string>) override;
};

#endif