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
#ifndef ISEARCH_BS_MAINSUBDOCPROCESSORCHAIN_H
#define ISEARCH_BS_MAINSUBDOCPROCESSORCHAIN_H

#include "build_service/common_define.h"
#include "build_service/processor/DocumentProcessorChain.h"
#include "build_service/processor/SingleDocProcessorChain.h"
#include "build_service/util/Log.h"

namespace build_service { namespace processor {

class MainSubDocProcessorChain : public DocumentProcessorChain
{
public:
    MainSubDocProcessorChain(DocumentProcessorChain* mainDocProcessor, DocumentProcessorChain* subDocProcessor);
    MainSubDocProcessorChain(MainSubDocProcessorChain& other);
    ~MainSubDocProcessorChain();

public:
    DocumentProcessorChain* clone() override;

protected:
    bool processExtendDocument(const document::ExtendDocumentPtr& extendDocument) override;

    void batchProcessExtendDocs(const std::vector<document::ExtendDocumentPtr>& extDocVec) override;

private:
    DocumentProcessorChain* _mainDocProcessor;
    DocumentProcessorChain* _subDocProcessor;

private:
    BS_LOG_DECLARE();
};

BS_TYPEDEF_PTR(MainSubDocProcessorChain);

}} // namespace build_service::processor

#endif // ISEARCH_BS_MAINSUBDOCPROCESSORCHAIN_H
