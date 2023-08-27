set(SourceList 
    grammar/render_graph_lexer.g4
    grammar/render_graph_parser.g4)

antlr_target(RenderGraphParserGeneratorLexer grammar/render_graph_lexer.g4 LEXER
    )
antlr_target(RenderGraphParserGeneratorParser grammar/render_graph_parser.g4 PARSER
    DEPENDS_ANTLR RenderGraphParserGeneratorLexer
    COMPILE_FLAGS -lib ${ANTLR_RenderGraphParserGeneratorLexer_OUTPUT_DIR})

set(RenderGraphParserGenerator_OUTPUTS ${ANTLR_RenderGraphParserGeneratorLexer_CXX_OUTPUTS} ${ANTLR_RenderGraphParserGeneratorParser_CXX_OUTPUTS} PARENT_SCOPE)
add_custom_target(RenderGraphParserGenerator DEPENDS ${ANTLR_RenderGraphParserGeneratorLexer_OUTPUTS} ${ANTLR_RenderGraphParserGeneratorParser_OUTPUTS})
set(RenderGraphParserGenerator_INCLUDE_DIR ${ANTLR_RenderGraphParserGeneratorLexer_OUTPUT_DIR} ${ANTLR_RenderGraphParserGeneratorParser_OUTPUT_DIR} PARENT_SCOPE)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceList})
