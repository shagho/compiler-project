lexer grammar Lexe;

options { language=Cpp;}


UNARY_OP :          MINUS | BANG | TILDE;

BITWISE :           AMP | BITWISE_OR;
LOGICAL :           OP_OR | OP_AND;
RELATIONAL1 :       EQ | OP_NE;
RELATIONAL2 :       OP_LE | OP_GE;
RELATIONAL3 :       LT | GT;
ARITHMETIC1 :       STAR | DIV |PERCENT;
ARITHMETIC2 :       PLUS | MINUS ;
INT_CONST :         INTEGER |[0][hH]Hex_numbers+;
BOOL_CONST :        TRUE | FALSE;
REAL_CONST :        ( (INT_CONST? '.' INT_CONST) | (INT_CONST '.') ) EX?|(INT_CONST)  EX;
STRING_CONST :      [']   (~('\\') | ESC)*? ['];

//keywords
FOR :       'for';
WHILE :     'while';
ALLOCATE :  'allocate';
DESTRUCT :  'destruct';
IF:         'if';
ELSE:       'else';
BREAK :     'break';
CASEOF :    'caseof';
CONTINUE :  'continue';
DEFAULT:    'default' ;
FUNCTION :  'function';
NIL :       'nil';
BOOL   :    'bool' ;
TYPE   :    'type' ;
INT    :    'int' ;
FLOAT :     'float';
STRING :    'string';
CONST :     'const';
READ :      'read';
WRITE :     'write';
PUBLIC :    'public';
PRIVATE :   'private';
PROTECTED : 'protected';
SUPER :     'super';
THIS   :    'this';
SWITCH :    'switch';
TRUE :      'true';
FALSE :     'false';
START:      'start';

//operands
STAR:           '*';
OP_NE:          '!=';
OP_LE:          '<=';
OP_GE:          '>=';
OP_AND:         '&&';
OP_OR:          '||';
LT:             '<';
GT:             '>';
BANG:           '!';
TILDE:          '~';
AMP:            '&';
BITWISE_OR:     '|';
PERCENT:        '%';
SEMIC  :        ';';
COLON  :        ':';
COMMA  :        ',';
EQ     :        '==';
ASM    :        '=';
PLUS   :        '+';
MINUS  :        '-';
DIV    :        '/';
LPAR   :        '(';
RPAR   :        ')';
CLPAR  :        '{';
CRPAR  :        '}';
BR :            ']';
BL :            '[';
DOT    :        '.';

WhiteSpace:         [ \t\n\r]+ -> skip;
Comment :   ('$$' .*? '$$') -> skip;
fragment ESC: '\\n' |'\\r' | '\\t' | '\\\\' | '\\\''  |'\\0'|'\\'Escape_hax_numbers ;
//Numbers
fragment DIGIT :    [0-9];
INTEGER       :     DIGIT+;
//hex numbers
fragment Hex_numbers :          [0-9a-fA-F];
fragment Escape_hax_numbers :   [hH]Hex_numbers Hex_numbers;
//id defination
fragment CHAR :     [a-zA-Z] |'@'|'_';
ID :                CHAR (CHAR | DIGIT)*;
fragment EX: '^'[-+]?INT_CONST;