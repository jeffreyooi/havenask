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
#pragma once

#include "build_service/common_define.h"
#include "build_service/util/Log.h"
#include "build_service/workflow/RealtimeBuilderImplV2.h"

namespace build_service { namespace workflow {

class DocReaderProducer;

class RawDocRtServiceBuilderImplV2 : public RealtimeBuilderImplV2
{
public:
    RawDocRtServiceBuilderImplV2(const std::string& configPath, std::shared_ptr<indexlibv2::framework::ITablet> tablet,
                                 const RealtimeBuilderResource& builderResource,
                                 future_lite::NamedTaskScheduler* tasker);
    virtual ~RawDocRtServiceBuilderImplV2();

    RawDocRtServiceBuilderImplV2(const RawDocRtServiceBuilderImplV2&) = delete;
    RawDocRtServiceBuilderImplV2& operator=(const RawDocRtServiceBuilderImplV2&) = delete;

protected:
    bool doStart(const proto::PartitionId& partitionId, KeyValueMap& kvMap) override;
    bool getLastTimestampInProducer(int64_t& timestamp) override;
    bool getLastReadTimestampInProducer(int64_t& timestamp) override;
    bool producerAndBuilderPrepared() const override;
    bool producerSeek(const common::Locator& locator) override;
    bool seekProducerToLatest() override;

    virtual void externalActions() override;
    virtual FlowFactory* createFlowFactory();

private:
    bool getBuilderAndProducer();

private:
    DocReaderProducer* _producer;
    std::unique_ptr<FlowFactory> _factory;
    bool _startSkipCalibrateDone;
    bool _isProducerRecovered;
    indexlib::document::SrcSignature _rtSrcSignature;

private:
    BS_LOG_DECLARE();

private:
    friend class RawDocRtServiceBuilderImplV2Test;
};

}} // namespace build_service::workflow
