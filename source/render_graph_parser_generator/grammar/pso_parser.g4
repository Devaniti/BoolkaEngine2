parser grammar pso_parser;

options {
	tokenVocab = render_graph_lexer;
}

import graphic_pso_parser, compute_pso_parser;

psoHelper: graphicPSOHelper;
pso: graphicPSO | computePSO;
