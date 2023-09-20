parser grammar graphic_pso_parser;

options {
	tokenVocab = render_graph_lexer;
}

import render_targets_config_parser;

graphicPSOHelper: renderTargetsConfig;

graphicPSO:
	GRAPHIC_PSO ID OPEN_CURLY_BRACKET graphicsPSOBody CLOSE_CURLY_BRACKET;

graphicsPSOBody: 
	vsDeclaration? 
	asDeclaration? 
	msDeclaration? 
	psDeclaration;

vsDeclaration: VS ID;
asDeclaration: AS ID;
msDeclaration: MS ID;
psDeclaration: PS ID;
