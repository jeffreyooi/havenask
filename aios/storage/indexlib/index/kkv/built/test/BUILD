load('//aios/storage:defs.bzl', 'strict_cc_fast_test')
strict_cc_fast_test(
    name='indexlib_kkv_built_test',
    srcs=[
        'BuiltSKeyIteratorTest.cpp', 'InlineKKVBuiltSegmentIteratorTest.cpp',
        'KKVBuiltSegmentReaderTest.cpp', 'KKVBuiltValueReaderTest.cpp',
        'KKVDiskIndexerTest.cpp', 'NormalKKVBuiltSegmentIteratorTest.cpp'
    ],
    shard_count=10,
    deps=[
        '//aios/future_lite/future_lite/executors:simple_executor',
        '//aios/storage/indexlib/config:schema',
        '//aios/storage/indexlib/document',
        '//aios/storage/indexlib/document/test:KVDocumentBatchMaker',
        '//aios/storage/indexlib/framework:tablet_schema_loader',
        '//aios/storage/indexlib/index/kkv:KKVIndexFactory',
        '//aios/storage/indexlib/index/kkv/building:kkv_mem_indexer',
        '//aios/storage/indexlib/index/kkv/config/test:kkv_index_config_builder',
        '//aios/storage/indexlib/table/kkv_table/test:KKVTabletSchemaMaker',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='KKVBuiltSegmentValidateSKeyTest',
    srcs=['KKVBuiltSegmentValidateSKeyTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/config:schema',
        '//aios/storage/indexlib/document/test:KVDocumentBatchMaker',
        '//aios/storage/indexlib/index/kkv/building:kkv_mem_indexer',
        '//aios/storage/indexlib/index/kkv/built:kkv_disk_iterator',
        '//aios/unittest_framework'
    ]
)
