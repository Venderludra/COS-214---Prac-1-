#ifndef RESTAPICONNECTOR_H
#define RESTAPICONNECTOR_H
#include "Connector.h"

class RestApiConnector : public Connector{
    public:
        RestApiConnector();
        std::vector<std::string> extract() override;
};

#endif