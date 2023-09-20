lexer grammar common_lexer;

OPEN_CURLY_BRACKET: '{';
CLOSE_CURLY_BRACKET: '}';

OPEN_SQUARE_BRACKET: '[';
CLOSE_SQUARE_BRACKET: ']';

TRUE: 'True';
FALSE: 'False';

OR: '|';

fragment ID_START: 'a' .. 'z' | 'A' .. 'Z';
fragment ID_CHAR: ID_START | '_' | '0' .. '9';

ID: ID_START ID_CHAR*;

fragment FILENAME_CHAR: '0' .. '9' | 'a' .. 'z' | 'A' .. 'Z' | '.' | '_' | '-';
fragment DIRECTORY_SEPARATOR: '/';
fragment FILENAME_VALUE: FILENAME_CHAR+;
fragment DIRECTORY_VALUE: (FILENAME_VALUE DIRECTORY_SEPARATOR)+;

FILEPATH_VALUE: DIRECTORY_VALUE? FILENAME_VALUE;

WHITESPACE: [ \r\n\t]+ -> skip;