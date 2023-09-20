parser grammar common_parser;

options {
	tokenVocab = render_graph_lexer;
}

boolValue: TRUE | FALSE;
