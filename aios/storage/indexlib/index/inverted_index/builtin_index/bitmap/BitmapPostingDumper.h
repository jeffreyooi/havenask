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
#include <memory>

#include "indexlib/index/inverted_index/PostingDumper.h"
#include "indexlib/index/inverted_index/builtin_index/bitmap/BitmapPostingWriter.h"

namespace indexlib::index {

class BitmapPostingDumper : public PostingDumper
{
public:
    BitmapPostingDumper() = default;
    ~BitmapPostingDumper() = default;

    BitmapPostingDumper(autil::mem_pool::PoolBase* pool = NULL) { _postingWriter.reset(new BitmapPostingWriter(pool)); }

    void Dump(const std::shared_ptr<file_system::FileWriter>& postingFile) override;
    uint64_t GetDumpLength() const override;

public:
    bool IsCompressedPostingHeader() const override { return false; }

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlib::index
