#ifndef BATCH_PIPELINE_H
#define BATCH_PIPELINE_H

#include "Pipeline.h"

class BatchPipeline : public Pipeline {
    public:
        using Pipeline::Pipeline;//this allows batchpipeline to inherit pipeline's constructor
        void extract() override;
        void load() override;
};

#endif // BATCH_PIPELINE_H