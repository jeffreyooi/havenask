#include "indexlib/index/test/lifecycle_segment_metrics_updater_unittest.h"

#include "indexlib/config/index_partition_options.h"
#include "indexlib/index/segment_metrics_updater/lifecycle_segment_metrics_updater.h"
#include "indexlib/index_base/index_meta/segment_merge_info.h"
#include "indexlib/test/document_creator.h"
#include "indexlib/test/schema_maker.h"

using namespace std;
using namespace autil;
using namespace autil::legacy;

using namespace indexlib::test;
using namespace indexlib::index_base;
using namespace indexlib::config;
using namespace indexlib::index;

namespace indexlib { namespace index {
IE_LOG_SETUP(index, LifecycleSegmentMetricsUpdaterTest);

LifecycleSegmentMetricsUpdaterTest::LifecycleSegmentMetricsUpdaterTest() {}

LifecycleSegmentMetricsUpdaterTest::~LifecycleSegmentMetricsUpdaterTest() {}

void LifecycleSegmentMetricsUpdaterTest::CaseSetUp() {}

void LifecycleSegmentMetricsUpdaterTest::CaseTearDown() {}

void LifecycleSegmentMetricsUpdaterTest::TestSimpleProcess()
{
    string field = "pk:uint64:pk;string1:string;long1:uint32;double1:double;";
    string index = "pk:primarykey64:pk;";
    string attr = "string1;long1;double1";
    auto schema = SchemaMaker::MakeSchema(field, index, attr, "");
    auto attrSchema = schema->GetAttributeSchema();
    IndexPartitionOptions options;
    assert(attrSchema);
    {
        util::KeyValueMap parameters;
        parameters["attribute_name"] = "long1";
        parameters[LifecycleSegmentMetricsUpdater::DEFAULT_LIFECYCLE_TAG] = "hot";
        LifecycleSegmentMetricsUpdater updater(nullptr);
        ASSERT_TRUE(updater.Init(schema, options, parameters));
        string docStrings = "cmd=add,pk=1,string1=A,long1=100,double1=1.1;"
                            "cmd=add,pk=2,string1=B,long1=10,double1=1.3;"
                            "cmd=add,pk=3,string1=C,long1=55,double1=1.5;";
        auto docs = DocumentCreator::CreateNormalDocuments(schema, docStrings);
        ASSERT_EQ(3u, docs.size());
        for (const auto& doc : docs) {
            updater.Update(doc);
        }
        auto jsonMap = updater.Dump();
        json::JsonMap expected;
        expected["checked_doc_count"] = 3;
        json::JsonMap attrValues;
        attrValues["max"] = 100u;
        attrValues["min"] = 10u;
        expected["attribute:long1"] = attrValues;
        expected[LIFECYCLE] = string("hot");
        EXPECT_EQ(ToJsonString(expected), ToJsonString(jsonMap));
    }
}
}} // namespace indexlib::index
