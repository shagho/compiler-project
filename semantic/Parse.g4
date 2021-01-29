parser grammar Parse;

options { tokenVocab=Lexe;
            language=Cpp;}


program :           start '('')' '{' ft_def+ '}' EOF;
ft_def :            (type_def|fun_def);
type_def :          TYPE ID (COLON ID)? CLPAR component+ CRPAR;
component :         access_modifier? ( var_def | fun_def );
access_modifier :   PRIVATE | PUBLIC | PROTECTED;
var_def:            CONST? type var_val (COMMA var_val )* SEMIC;
type :              INT | BOOL | FLOAT | STRING | ID;
var_val :           ref (ASM expr)?;
fun_def :           ( LPAR args_var RPAR ASM )? FUNCTION ID LPAR args_var? RPAR block;
args_var :          type (BL BR)* ID | args_var COMMA type (BL BR)* ID;
block :             CLPAR ( var_def | stmt )* CRPAR;
stmt :              assign SEMIC | func_call SEMIC | cond_stmt | loop_stmt | BREAK SEMIC
                    | CONTINUE SEMIC | DESTRUCT ( BL BR )* ID SEMIC;
assign :            ( var | LPAR var ( COMMA var )* RPAR ) ASM expr;
var :               ( ( THIS | SUPER ) DOT )? ref (DOT ref )*;
ref :               ID ( BL expr BR )*;
expr :              unary_op expr | expr arithmetic1 expr | expr arithmetic2 expr
                    | expr ( relational1|relational3) expr | expr relational2 expr
                    | expr bitwise expr | expr logical expr
                    | const_val | ALLOCATE handle_call | func_call | var | list | NIL;
func_call :         ( var '.' )? handle_call | READ LPAR RPAR | WRITE LPAR expr RPAR;
list :              BL ( expr | list ) ( COMMA ( expr | list ) ) * BR;
handle_call :       ID LPAR params? RPAR;
switch_body :       ( CASEOF INT_CONST COLON block ) + ( DEFAULT COLON block )?;
params :            expr | expr COMMA params;
cond_stmt :         IF expr ( block | stmt ) ( ELSE ( block | stmt ) )? |
                    SWITCH var CLPAR switch_body CRPAR;
loop_stmt :         for_loop|
                    WHILE expr ( block | stmt );
for_loop:                 FOR ( type? assign )? SEMIC expr SEMIC assign? block;

const_val :         INT_CONST | REAL_CONST | BOOL_CONST | STRING_CONST;
relational1 :       RELATIONAL1;
relational2 :       RELATIONAL2;
relational3 :       RELATIONAL3;
arithmetic1 :       ARITHMETIC1;
arithmetic2 :       ARITHMETIC2;
logical     :       LOGICAL;
unary_op    :       UNARY_OP;
bitwise     :       BITWISE;
start       :       START;
