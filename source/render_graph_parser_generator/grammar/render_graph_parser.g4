parser grammar render_graph_parser;

options {   tokenVocab = render_graph_lexer; }

resourceTex1D: RESOURCE TEXTURE1D ID OPEN_BRACKET CLOSED_BRACKET;
