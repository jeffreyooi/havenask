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
#ifndef __INDEXLIB_CODEGEN_CHECKER_H
#define __INDEXLIB_CODEGEN_CHECKER_H

#include <memory>

namespace indexlib { namespace codegen {

#define COLLECT_CONST_MEM(checkerPtr, var)
#define COLLECT_TYPE_DEFINE(checkerPtr, type)

class CodegenChecker
{
};

typedef std::shared_ptr<CodegenChecker> CodegenCheckerPtr;

}} // namespace indexlib::codegen

#endif //__INDEXLIB_CODEGEN_CHECKER_H
