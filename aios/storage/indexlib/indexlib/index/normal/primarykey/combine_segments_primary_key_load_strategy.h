/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __INDEXLIB_COMBINE_SEGMENTS_PRIMARY_KEY_LOAD_STRATEGY_H
#define __INDEXLIB_COMBINE_SEGMENTS_PRIMARY_KEY_LOAD_STRATEGY_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/config/primary_key_load_strategy_param.h"
#include "indexlib/index/normal/primarykey/primary_key_load_strategy.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace index {

class CombineSegmentsPrimaryKeyLoadStrategy : public PrimaryKeyLoadStrategy
{
public:
    CombineSegmentsPrimaryKeyLoadStrategy(const config::PrimaryKeyIndexConfigPtr& pkIndexConfig)
        : mPkConfig(pkIndexConfig)
    {
        config::PrimaryKeyLoadStrategyParamPtr param = mPkConfig->GetPKLoadStrategyParam();
        assert(param);
        assert(param->NeedCombineSegments());
        mMaxDocCount = param->GetMaxDocCount();
    }
    ~CombineSegmentsPrimaryKeyLoadStrategy() {}

public:
    void CreatePrimaryKeyLoadPlans(const index_base::PartitionDataPtr& partitionData,
                                   PrimaryKeyLoadPlanVector& plans) override;

private:
    bool NeedCreateNewPlan(bool isRtSegment, const PrimaryKeyLoadPlanPtr& plan, bool isRtPlan);
    void PushBackPlan(const PrimaryKeyLoadPlanPtr& plan, PrimaryKeyLoadPlanVector& plans);

private:
    config::PrimaryKeyIndexConfigPtr mPkConfig;
    size_t mMaxDocCount;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(CombineSegmentsPrimaryKeyLoadStrategy);
}} // namespace indexlib::index

#endif //__INDEXLIB_COMBINE_SEGMENTS_PRIMARY_KEY_LOAD_STRATEGY_H
