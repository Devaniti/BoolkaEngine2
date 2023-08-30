file(GLOB_RECURSE SourceList CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HeaderList CONFIGURE_DEPENDS *.h *.hpp)
set(AutogenList ${RenderGraphParserGenerator_OUTPUTS})

add_library(RenderGraphParser STATIC 
  ${SourceList} ${HeaderList} ${AutogenList})
add_dependencies(RenderGraphParser RenderGraphParserGenerator)

target_include_directories(RenderGraphParser
  PUBLIC public
  PRIVATE private
)

target_include_directories(RenderGraphParser SYSTEM
  PRIVATE ${RenderGraphParserGenerator_INCLUDE_DIR}
)

target_precompile_headers(RenderGraphParser
    PUBLIC public/precompiled_header.h
)

set_source_files_properties(${HeaderList} PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties(${AutogenList} PROPERTIES SKIP_PRECOMPILE_HEADERS ON)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceList} ${HeaderList})
source_group(autogen FILES ${AutogenList})

target_link_libraries(RenderGraphParser Common Allocator Filesystem TaskSystem antlr4_static)
