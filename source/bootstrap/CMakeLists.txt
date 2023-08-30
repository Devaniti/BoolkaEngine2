file(GLOB_RECURSE SourceList CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HeaderList CONFIGURE_DEPENDS *.h *.hpp)

add_executable(Bootstrap ${SourceList} ${HeaderList})

target_include_directories(Bootstrap
    PUBLIC public
    PRIVATE private
)

target_precompile_headers(Bootstrap
    PUBLIC public/precompiled_header.h
)

set_source_files_properties(${HeaderList} PROPERTIES HEADER_FILE_ONLY TRUE)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceList} ${HeaderList})

target_link_libraries(Bootstrap Allocator Filesystem TaskSystem)

set_property(TARGET Bootstrap PROPERTY VS_DEBUGGER_COMMAND_ARGUMENTS "")
set_property(TARGET Bootstrap PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})