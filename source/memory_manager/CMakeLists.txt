file(GLOB_RECURSE SourceList CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HeaderList CONFIGURE_DEPENDS *.h *.hpp)

add_library(MemoryManager STATIC ${SourceList} ${HeaderList})

target_include_directories(MemoryManager
    PUBLIC public
    PRIVATE private
)

target_precompile_headers(MemoryManager
    PUBLIC public/precompiled_header.h
)

set_source_files_properties(${HeaderList} PROPERTIES HEADER_FILE_ONLY TRUE)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceList} ${HeaderList})

target_link_libraries(MemoryManager Common)
