parser grammar render_graph_parser;

options {
	tokenVocab = render_graph_lexer;
}

import resource_parser, variable_parser, shader_parser, pso_parser;

main: object+;

object: resource | variable | shader | pso | psoHelper;