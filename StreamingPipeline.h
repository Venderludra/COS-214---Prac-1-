#ifndef STREAMING_PIPELINE_H
#define STREAMING_PIPELINE_H

#include "Pipeline.h"

class StreamingPipeline : public Pipeline {
    public:
        using Pipeline::Pipeline;//this allows streampipeline to inherit pipeline's constructor
        void extract() override;
        void load() override;
};

#endif // STREAMING_PIPELINE_H