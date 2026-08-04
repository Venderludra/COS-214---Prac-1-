#include "CheckpointManager.h"

void CheckpointManager::save(RunCheckpoint* checkpoint) {
    //caretaker appends checkpoint to history (narrow interface only)
    history.push_back(checkpoint);
}

RunCheckpoint* CheckpointManager::undo() {
    //remove and return most recent checkpoint, or nullptr if empty
    if (history.empty()) {
        return nullptr;
    }
    
    RunCheckpoint* latest = history.back();
    history.pop_back();
    return latest;
}

CheckpointManager::~CheckpointManager() {
    //felete all remaining checkpoints
    for (auto checkpoint : history) {
        delete checkpoint;
    }
}