#include "Connector.h"
#include "ConnectorFactory.h"
#include "CsvFactory.h"
#include "PostgresConnector.h"
#include "PostgresFactory.h"
#include "RestApiConnector.h"
#include "RestApiFactory.h"
#include "Transformation.h"
#include "TransformationRegistry.h"
#include "Pipeline.h"
#include "BatchPipeline.h"
#include "StreamingPipeline.h"
#include "CheckpointManager.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"

#include <iostream>

using namespace std;

int main(){
    ConnectorFactory** pf = new ConnectorFactory*[3];
    pf[0] = new PostgresFactory();
    pf[1] = new CsvFactory();
    pf[2] = new RestApiFactory();

    Connector* f  = nullptr;

    for(int i = 0 ; i < 3 ; i++){
        f = pf[i]->createConnector();
        cout << "Source of Connector: " << f->getSource() << endl;
        for(string data : f->extract()){
            cout << data << endl;
        }
        delete f;
        f = 0;
    }

    for(int i = 0 ; i < 3 ;i++){
        delete pf[i];
    }

    delete[] pf;

    //task 5.2 - the pipeline with all the patterns
    cout << "\nTASK 5.2:\n";
    //transformation registry + registering the prototypes
    cout<<"\nCreating the registry:\n";
    TransformationRegistry* registry = new TransformationRegistry();
    registry->registerStep("dedup", new DeduplicateStep()); //"dedup" as per instructions
    registry->registerStep("aggregate", new AggregateByRegionStep()); //"aggregate" as per instructions
    cout<<"Done creating the registry\n";

    //then: the batchpipeline with a postgres factory
    cout<<"\nCreating the pipeline:\n";
    Pipeline* pipeline = new BatchPipeline(new PostgresFactory());
    cout<<"Done creating the pipeline\n";

    //then we add he cloned transformation steps from the registry (that also happen to not be constructed directly)
    cout<<"\nAdding the cloned steps:\n";
    pipeline->addStep(registry->create("dedup"));
    pipeline->addStep(registry->create("aggregate"));
    cout<<"Done adding the cloned steps\n";

    //then - the checkpoint manager
    cout<<"\nCreating the checkpoint manager:\n";
    CheckpointManager* manager = new CheckpointManager();
    cout<<"Done creating the checkpoint manager:\n";

    //lets run the pipeline:
    cout<<"\nRunning the Pipeline:\n";
    pipeline->run();

    //the checkpoint that saves the run (its important to get the stage)
    cout<<"\nSaving the checkpoint:\n";
    RunCheckpoint* checkpoint = pipeline->createCheckpoint();
    cout << "\nCheckpoint created successfully\n";
    manager->save(checkpoint);
    cout<<"Checkpoint saved at stage: "<<checkpoint->getStage() <<endl;

    //then we delete everything:
    cout<<"\nDeletion Point:\n";
    cout<<"Deletion 1 - Registry:\n";
    delete registry; //this also deletes the prototypes that it owns
    cout<<"Deletion 1 - Registry (Done)\nDeletion 2 Pipeline:\n";
    delete pipeline; //also deletes the factory and the transformation steps
    cout<<"Deletion 2 Pipeline (Done)\nDeletion 3 - Manager:\n";
    delete manager; //also deltes the checkpoints in history
    cout<<"Deletions Done...Success ngwanaka!\n";

    return 0 ;
}