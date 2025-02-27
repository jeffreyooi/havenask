#ifndef ISEARCH_BS_MOCKGENERATIONTASK_H
#define ISEARCH_BS_MOCKGENERATIONTASK_H

#include "build_service/admin/GenerationTask.h"
#include "build_service/test/test.h"
#include "build_service/test/unittest.h"
#include "build_service/util/Log.h"

namespace build_service { namespace admin {

class MockGenerationTask : public GenerationTask
{
public:
    MockGenerationTask(const proto::BuildId& buildId) : GenerationTask(buildId, NULL) {}
    MockGenerationTask(const proto::BuildId& buildId, cm_basic::ZkWrapper* zkWrapper)
        : GenerationTask(buildId, zkWrapper)
    {
    }
    ~MockGenerationTask() {}
    // MockGenerationTask(const MockGenerationTask& other)
    //     : GenerationTask(other) {}
public:
    void doPrepareGeneration(WorkerTable&) { _step = GENERATION_STARTED; }

protected:
    MOCK_METHOD1(prepareGeneration, void(WorkerTable&));
};

typedef ::testing::StrictMock<MockGenerationTask> StrictMockGenerationTask;
typedef ::testing::NiceMock<MockGenerationTask> NiceMockGenerationTask;

}} // namespace build_service::admin

#endif // ISEARCH_BS_MOCKGENERATIONTASK_H
