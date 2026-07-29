#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <string>
#include <vector>

class Connector{
    public:
        Connector(std::string);
        virtual std::vector<std::string> extract() = 0;
        std::string getSource();
        virtual ~Connector();

    protected:
        std::string source;
};

#endif