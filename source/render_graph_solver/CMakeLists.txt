file(GLOB_RECURSE SourceList CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HeaderList CONFIGURE_DEPENDS *.h *.hpp)

add_library(RenderGraphSolver STATIC ${SourceList} ${HeaderList})

target_include_directories(RenderGraphSolver
    PUBLIC public
    PRIVATE private
)

target_precompile_headers(RenderGraphSolver
    PUBLIC public/precompiled_header.h
)

set_source_files_properties(${HeaderList} PROPERTIES HEADER_FILE_ONLY TRUE)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceList} ${HeaderList})

target_link_libraries(RenderGraphSolver Common Allocator Filesystem TaskSystem RenderGraphParser)
