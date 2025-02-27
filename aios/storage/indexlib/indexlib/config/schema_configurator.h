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
#ifndef __INDEXLIB_SCHEMACONFIGURATOR_H
#define __INDEXLIB_SCHEMACONFIGURATOR_H

#include <string>

#include "autil/legacy/any.h"
#include "autil/legacy/json.h"
#include "indexlib/common_define.h"
#include "indexlib/indexlib.h"

DECLARE_REFERENCE_CLASS(config, IndexPartitionSchemaImpl);
DECLARE_REFERENCE_CLASS(config, DictionarySchema);
DECLARE_REFERENCE_CLASS(config, DictionaryConfig);
DECLARE_REFERENCE_CLASS(config, FieldConfig);
DECLARE_REFERENCE_CLASS(config, RegionSchema);
DECLARE_REFERENCE_CLASS(config, AdaptiveDictionarySchema);
DECLARE_REFERENCE_CLASS(test, ModifySchemaMaker);

namespace indexlib { namespace config {

class SchemaConfigurator
{
public:
    void Configurate(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema, bool isSubSchema);

private:
    AdaptiveDictionarySchemaPtr LoadAdaptiveDictSchema(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema);
    DictionarySchemaPtr LoadDictSchema(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema);
    std::shared_ptr<DictionaryConfig> LoadDictionaryConfig(const autil::legacy::Any& any,
                                                           IndexPartitionSchemaImpl& schema);

    void LoadRegions(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema);

    RegionSchemaPtr LoadRegionSchema(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema,
                                     bool multiRegionFormat);

    void LoadModifyOperations(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema);

    static void LoadOneModifyOperation(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema);

    void LoadCustomizedConfig(const autil::legacy::Any& any, IndexPartitionSchemaImpl& schema);
    static void AddOfflineJoinVirtualAttribute(const std::string& attrName, IndexPartitionSchemaImpl& destSchema);

private:
    friend class test::ModifySchemaMaker;
    IE_LOG_DECLARE();
};
}} // namespace indexlib::config

#endif //__INDEXLIB_SCHEMACONFIGURATOR_H
