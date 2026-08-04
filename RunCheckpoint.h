#ifndef RUNCHECKPOINT_H
#define RUNCHECKPOINT_H
#include <vector>
#include <string>

class RunCheckpoint {
    public:
        RunCheckpoint(int stage, std::vector<std::string> records);
        int getStage() const;
        std::vector<std::string> getRecords() const;
        ~RunCheckpoint();

    private:
        int stage;
        std::vector<std::string> records;
};

#endif