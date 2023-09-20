parser grammar compute_pso_parser;

options {
	tokenVocab = render_graph_lexer;
}

computePSO:
	COMPUTE_PSO ID OPEN_CURLY_BRACKET computePSOBody CLOSE_CURLY_BRACKET;

computePSOBody: csDeclaration;

csDeclaration: CS ID;
