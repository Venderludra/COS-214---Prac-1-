#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H
#include "RunCheckpoint.h"
#include <vector>

class CheckpointManager {
    public:
        void save(RunCheckpoint* checkpoint);
        RunCheckpoint* undo();
        ~CheckpointManager();

    private:
        std::vector<RunCheckpoint*> history;
};

#endif