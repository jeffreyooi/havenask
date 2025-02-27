load('//aios/storage:defs.bzl', 'strict_cc_library')
package(default_visibility=['//aios/storage/indexlib:__subpackages__'])
strict_cc_library(
    name='table',
    srcs=[],
    hdrs=[],
    visibility=['//visibility:public'],
    deps=[':KKVTabletFactory']
)
strict_cc_library(
    name='KKVTabletFactory',
    visibility=['//aios/storage/indexlib/table:__subpackages__'],
    deps=[
        ':KKVMemSegment', ':KKVSchemaResolver', ':KKVTabletExporter',
        ':KKVTabletOptions', ':KKVTabletReader', ':KKVTabletSessionReader',
        ':KKVTabletWriter', '//aios/autil:NoCopyable', '//aios/future_lite',
        '//aios/storage/indexlib/base:Status',
        '//aios/storage/indexlib/base:Types',
        '//aios/storage/indexlib/config:TabletSchema',
        '//aios/storage/indexlib/document:DocumentBatch',
        '//aios/storage/indexlib/document/kkv:KKVDocumentFactory',
        '//aios/storage/indexlib/framework:ITabletFactory',
        '//aios/storage/indexlib/framework:TabletLoader',
        '//aios/storage/indexlib/framework:TabletReader',
        '//aios/storage/indexlib/framework/index_task:IIndexOperationCreator',
        '//aios/storage/indexlib/framework/index_task:IIndexTaskPlanCreator',
        '//aios/storage/indexlib/framework/index_task:IIndexTaskResourceCreator',
        '//aios/storage/indexlib/index:IIndexFactory',
        '//aios/storage/indexlib/index/kkv:factory',
        '//aios/storage/indexlib/table:builtin_define',
        '//aios/storage/indexlib/table/common:CommonTabletValidator',
        '//aios/storage/indexlib/table/common:CommonVersionImporter',
        '//aios/storage/indexlib/table/common:LSMTabletLoader',
        '//aios/storage/indexlib/table/kkv_table/index_task:KKVTableResourceCreator',
        '//aios/storage/indexlib/table/kkv_table/index_task:KKVTableTaskOperationCreator',
        '//aios/storage/indexlib/table/kkv_table/index_task:KKVTableTaskPlanCreator',
        '//aios/storage/indexlib/table/plain:MultiShardDiskSegment',
        '//aios/storage/indexlib/table/plain:MultiShardMemSegment',
        '//aios/storage/indexlib/table/plain:PlainDiskSegment'
    ],
    alwayslink=True
)
strict_cc_library(
    name='KKVTabletWriter',
    deps=[
        ':KKVTabletOptions', ':KKVTabletReader', '//aios/autil:result',
        '//aios/storage/indexlib/table/common:CommonTabletWriter',
        '//aios/storage/indexlib/table/kv_table:RewriteDocUtil'
    ]
)
strict_cc_library(
    name='KKVTabletOptions',
    deps=['//aios/storage/indexlib/config:TabletOptions']
)
strict_cc_library(
    name='KKVIndexOptions',
    deps=[
        '//aios/storage/indexlib/framework:TabletData',
        '//aios/storage/indexlib/index/common/field_format/pack_attribute',
        '//aios/storage/indexlib/index/kkv/config'
    ]
)
strict_cc_library(
    name='KKVReadOptions',
    srcs=[],
    deps=['//aios/storage/indexlib/index/kkv/config']
)
strict_cc_library(
    name='KKVReader',
    deps=[
        ':KKVIndexOptions', ':KKVReadOptions',
        '//aios/storage/indexlib/index/kkv:factory',
        '//aios/storage/indexlib/index/kkv:reader',
        '//aios/storage/indexlib/index/kkv/config',
        '//aios/storage/indexlib/index/kkv/search'
    ]
)
strict_cc_library(
    name='KKVReaderImpl',
    deps=[
        ':KKVReader', '//aios/storage/indexlib/index/kkv:factory',
        '//aios/storage/indexlib/index/kkv/search',
        '//aios/storage/indexlib/table/plain:MultiShardDiskSegment',
        '//aios/storage/indexlib/table/plain:MultiShardMemSegment'
    ]
)
strict_cc_library(
    name='KKVCachedReaderImpl',
    srcs=[],
    hdrs=['KKVCachedReaderImpl.h'],
    deps=[
        ':KKVReaderImpl', '//aios/storage/indexlib/index/kkv:factory',
        '//aios/storage/indexlib/table/plain:MultiShardDiskSegment',
        '//aios/storage/indexlib/table/plain:MultiShardMemSegment'
    ]
)
strict_cc_library(
    name='KKVReaderFactory',
    deps=[
        ':KKVCachedReaderImpl', ':KKVReaderImpl',
        '//aios/storage/indexlib/framework:TabletReader'
    ]
)
strict_cc_library(
    name='KKVTabletSessionReader',
    deps=[
        ':KKVTabletReader',
        '//aios/storage/indexlib/table/common:CommonTabletSessionReader'
    ]
)
strict_cc_library(
    name='KKVTabletReader',
    srcs=['KKVTabletReader.cpp'],
    hdrs=['KKVReader.h', 'KKVTabletReader.h'],
    deps=[
        ':KKVReaderFactory', '//aios/storage/indexlib/framework:TabletReader',
        '//aios/storage/indexlib/index/attribute:attr_helper',
        '//aios/storage/indexlib/util:ProtoJsonizer'
    ]
)
strict_cc_library(
    name='KKVSchemaResolver',
    implementation_deps=['//aios/storage/indexlib/indexlib/config'],
    deps=[
        '//aios/storage/indexlib/config:SchemaResolver',
        '//aios/storage/indexlib/config:UnresolvedSchema',
        '//aios/storage/indexlib/table/kv_table:KVSchemaResolver'
    ]
)
strict_cc_library(
    name='KKVTabletDocIterator',
    deps=[
        '//aios/storage/indexlib/index/kkv:factory',
        '//aios/storage/indexlib/table/kv_table:KVTabletFactory'
    ]
)
strict_cc_library(
    name='KKVTabletExporter',
    deps=[
        ':KKVTabletDocIterator',
        '//aios/storage/indexlib/framework:ITabletExporter'
    ]
)
strict_cc_library(
    name='KKVMemSegment',
    deps=[
        '//aios/storage/indexlib/index/kkv:factory',
        '//aios/storage/indexlib/table/plain:MultiShardMemSegment'
    ]
)
