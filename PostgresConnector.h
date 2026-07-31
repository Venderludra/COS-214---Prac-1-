#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H
#include "Connector.h"

class PostgresConnector : public Connector{
    public:
        PostgresConnector();
        std::vector<std::string> extract() override;
};

#endif