#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <string>
#include <vector>

class Transformation{
    public:
        Transformation(std::string);
        Transformation(const Transformation&);
        virtual Transformation* clone() = 0; //prototype
        virtual std::vector<std::string> apply(std::vector<std::string>) = 0;
        std::string getName() const;
        virtual ~Transformation();
        
    protected:
        std::string name;
};

#endif