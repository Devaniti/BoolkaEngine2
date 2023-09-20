parser grammar variable_parser;

options {
	tokenVocab = render_graph_lexer;
}

variable: VARIABLE ID OPEN_CURLY_BRACKET variableBody CLOSE_CURLY_BRACKET;

variableBody:
	variableFormatDeclaration updateFrequencyDeclaration;

variableFormatDeclaration: FORMAT variableFormatValue;
updateFrequencyDeclaration:
	UPDATE_FREQUENCY updateFrequencyValue;

variableFormatValue:
	UINT
	| UINT2
	| UINT3
	| UINT4
	| FLOAT
	| FLOAT2
	| FLOAT3
	| FLOAT4;

updateFrequencyValue: CONST | STALL | FRAME;
