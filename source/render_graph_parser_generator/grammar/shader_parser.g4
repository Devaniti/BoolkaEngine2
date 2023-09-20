parser grammar shader_parser;

options {
	tokenVocab = render_graph_lexer;
}

shader:
	SHADER ID OPEN_CURLY_BRACKET shaderBody CLOSE_CURLY_BRACKET;

shaderBody: shaderTypeDeclaration filenameDeclaration entrypointDeclaration;

shaderTypeDeclaration: TYPE shaderType;
filenameDeclaration: FILENAME FILEPATH_VALUE;
entrypointDeclaration: ENTRYPOINT ID;

shaderType: VS | AS | MS | PS | CS;