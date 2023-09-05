parser grammar render_graph_parser;

options {
	tokenVocab = render_graph_lexer;
}

main: object+;

object: resource | variable | shader | pso;

resource: RESOURCE ID OPEN_BRACKET resourceBody CLOSE_BRACKET;

resourceBody:
	typeDeclaration resourceFormatDeclaration? resolutionDeclaration? optimizedClearValueDeclaration
		? sliceCountDeclaration? sizeDeclaration?;

variable: VARIABLE ID OPEN_BRACKET variableBody CLOSE_BRACKET;

variableBody:
	variableFormatDeclaration updateFrequencyDeclaration;

shader:
	SHADER shaderType ID OPEN_BRACKET shaderBody CLOSE_BRACKET;

shaderBody: filenameDeclaration entrypointDeclaration;

pso: graphicsPSO | computePSO;

graphicsPSO:
	PSO GRAPHICS ID OPEN_BRACKET graphicsPSOBody CLOSE_BRACKET;

graphicsPSOBody: (vsDeclaration? asDeclaration? msDeclaration) psDeclaration;

computePSO:
	PSO COMPUTE ID OPEN_BRACKET computePSOBody CLOSE_BRACKET;

computePSOBody: csDeclaration;

typeDeclaration: TYPE resourceTypeValue;
resolutionDeclaration: RESOLUTION ID;
resourceFormatDeclaration: FORMAT resourceFormatValue;
optimizedClearValueDeclaration: OPTIMIZED_CLEAR_VALUE ID;
sliceCountDeclaration: SLICE_COUNT ID;
sizeDeclaration: SIZE ID;
variableFormatDeclaration: FORMAT variableFormatValue;
updateFrequencyDeclaration:
	UPDATE_FREQUENCY updateFrequencyValue;
filenameDeclaration: FILENAME FILEPATH_VALUE;
entrypointDeclaration: ENTRYPOINT ID;

vsDeclaration: VS ID;
asDeclaration: AS ID;
msDeclaration: MS ID;
psDeclaration: PS ID;
csDeclaration: CS ID;

shaderType: VS | AS | MS | PS | CS;

resourceTypeValue: BUFFER | TEXTURE1D | TEXTURE2D | TEXTURE3D;

resourceFormatValue:
	R8
	| R8G8
	| R8G8B8A8
	| R16
	| R16G16
	| R16G16B16A16
	| R32
	| R32G32
	| R32G32B32
	| R32G32B32A32
	| R8_UNORM
	| R8G8_UNORM
	| R8G8B8A8_UNORM
	| R8_SNORM
	| R8G8_SNORM
	| R8G8B8A8_SNORM
	| R8_UINT
	| R8G8_UINT
	| R8G8B8A8_UINT
	| R8_SINT
	| R8G8_SINT
	| R8G8B8A8_SINT
	| R16_FLOAT
	| R16G16_FLOAT
	| R16G16B16A16_FLOAT
	| R16_UNORM
	| R16G16_UNORM
	| R16G16B16A16_UNORM
	| R16_SNORM
	| R16G16_SNORM
	| R16G16B16A16_SNORM
	| R16_UINT
	| R16G16_UINT
	| R16G16B16A16_UINT
	| R16_SINT
	| R16G16_SINT
	| R16G16B16A16_SINT
	| D32_FLOAT
	| R32_FLOAT
	| R32G32_FLOAT
	| R32G32B32A32_FLOAT
	| R32_UINT
	| R32G32_UINT
	| R32G32B32A32_UINT
	| R32_SINT
	| R32G32_SINT
	| R32G32B32A32_SINT;

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
