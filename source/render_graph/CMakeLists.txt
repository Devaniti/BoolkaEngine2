file(GLOB_RECURSE SourceList CONFIGURE_DEPENDS *.rg)

add_custom_target(RenderGraph
    COMMAND RenderGraphSolverCMD "./graph" "../render_graph_generated"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    SOURCES ${SourceList})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceList})

set_property(TARGET RenderGraphSolverCMD PROPERTY VS_DEBUGGER_COMMAND_ARGUMENTS "./graph ../render_graph_generated")
set_property(TARGET RenderGraphSolverCMD PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
