lexer grammar render_graph_lexer;


// Resource definition
RESOURCE: 'Resource';

BUFFER: 'Buffer';
TEXTURE1D: 'Texture1D';
TEXTURE2D: 'Texture2D';
TEXTURE3D: 'Texture3D';

// PSO definition
PSO: 'PSO';

GRAPHICS: 'Graphics';
COMPUTE: 'Compute';

// Shader definition
SHADER: 'Shader';

// Shader types
VS: 'VS';
AS: 'AS';
MS: 'MS';
PS: 'PS';
CS: 'CS';

// Variable definitions
VARIABLE: 'Variable';

// Parameters
FORMAT: 'Format';
RESOLUTION: 'Resolution';
OPTIMIZED_CLEAR_VALUE: 'OptimizedClearValue';
FILENAME: 'Filename';
ENTRYPOINT: 'Entrypoint';
UPDATE_FREQUENCY: 'UpdateFrequency';

OPEN_BRACKET: '{';
CLOSED_BRACKET: '}';

ID_START: 'a' .. 'z' | 'A' .. 'Z' | '_';
ID_CHAR: ID_START | '0' .. '9';

ID: ID_START ID_CHAR*;
INTEGER: '1'..'9' '0'..'9'*;

WHITESPACE : [ \r\n\t] + -> skip;
