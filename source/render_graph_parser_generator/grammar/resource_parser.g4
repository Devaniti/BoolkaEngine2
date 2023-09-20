parser grammar resource_parser;

options {
	tokenVocab = render_graph_lexer;
}

import resource_formats_parser;

resource: RESOURCE ID OPEN_CURLY_BRACKET resourceBody CLOSE_CURLY_BRACKET;

resourceBody:
	resourceTypeDeclaration resourceFormatDeclaration? resolutionDeclaration? optimizedClearValueDeclaration
		? sliceCountDeclaration? sizeDeclaration?;

resourceTypeDeclaration: TYPE resourceTypeValue;
resourceFormatDeclaration: FORMAT resourceFormatValue;
resolutionDeclaration: RESOLUTION ID;
optimizedClearValueDeclaration: OPTIMIZED_CLEAR_VALUE ID;
sliceCountDeclaration: SLICE_COUNT ID;
sizeDeclaration: SIZE ID;

resourceTypeValue: BUFFER | TEXTURE1D | TEXTURE2D | TEXTURE3D;