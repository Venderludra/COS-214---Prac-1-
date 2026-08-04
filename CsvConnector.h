#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H
#include "Connector.h"

class CsvConnector : public Connector{
    public:
        std::vector<std::string> extract() override;
        CsvConnector();
};

#endif