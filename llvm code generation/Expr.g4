grammar Expr;

options { language=Cpp;}

program :           ft_def* start_func ft_def*;
start_func :        '(' Int ID ')' '=' Function start '(' ')' block;
ft_def :            (fun_def);
//type_def: Type ID (':' ID)? '{' component+ '}';
//component: access_modifier? (var_def | fun_def);
//access_modifier: Private | Public | Protected;
var_def: Const?  type  var_val (',' var_val)* ';';
type: Int | Bool | Float | String | ID;
var_val: ref ('=' expr)?;
fun_def: ('(' args_var ')' '=')? Function ID '(' args_var? ')' block;
args_var: type ('['']')* ID | args_var ',' type ('['']')* ID;
block: '{' (var_def|stmt)* '}';
stmt:
    assign ';'
    | func_call ';'
    | cond_stmt
    | loop_stmt
    | Break ';'
    | Continue ';' ;
assign: (var | '(' var (',' var)* ')') '=' expr;
var: ref (Dot ref)*;
ref: ID ('[' expr ']')*;
expr: term (arithmetic2 term)*
    |  const_val
    | func_call
    | var
    | Nil;

term: factor (arithmetic1 factor)*;

factor: '(' expr ')' #Ex
        | const_val #Constant
        |ID  #Identifier;

func_call: (var Dot)? handle_call #Call
        | Read '(' ')' #Read_atr
        | Write '(' expr ')' #Write_atr;

//list : '[' (expr | list) (','(expr | list))* ']';
handle_call: ID '(' params? ')';
params: expr | expr ',' params;
cond_stmt: If expr (block | stmt) (Else (block | stmt))? | Switch var '{' switch_body '}' ;
switch_body: (Caseof Int_const ':' block)+ (Default ':' block)?;
loop_stmt: For (type?assign)? ';' expr ';' assign? block | While expr( block | stmt );
const_val: Int_const  #I_const
        | Float_const  #F_const
        |  String_const #Str_const
        | Bool_const #Boolean_const;
//unary_op: '-' | '!' | '~';
arithmetic1: '*' | '/' | '%';
arithmetic2: '+' | '-';
//bitwise: '&' | '|';
//logical: '||' | '&&';
//relational1: '<=' | '>=';
//relational2: '==' | '!=';
//relational3: '<' | '>';
start: START;

Allocate: 'allocate';
Bool: 'bool';
Break: 'break';
Caseof: 'caseof';
Const: 'const';
Continue: 'continue';
Default: 'default';
Destruct: 'destruct';
Else: 'else';
False: 'false';
Function: 'function';
Float: 'float';
For: 'for';
If : 'if';
Int: 'int';
Nil : 'nil';
Private: 'private';
Protected: 'protected';
Public: 'public';
Read: 'read';
String: 'string';
Super: 'super';
Switch : 'switch';
This : 'this';
True: 'true';
Type: 'type';
While: 'while';
Write: 'write';
Dot : '.';
START : 'start';
Int_const: DEC | HEX;
Float_const: ( (Int_const? '.' Int_const) | (Int_const '.') ) EX?|(Int_const)  EX ;
String_const: ['](EXC_BS|SCAPE)*?['];
Bool_const: True | False;
ID: ('@'|'_'|LETTER)('@'|'_'|LETTER|DIGIT)*;


WHITESPACE: [ \t\r\n]+ ->    skip;
Comment:  ( '$$'.*?'$$') -> skip;


fragment SCAPE: '\\n' |'\\r' | '\\t' | '\\\\' | '\\\''  |'\\0'|'\\'[hH][a-fA-F0-9][a-fA-F0-9] ;
fragment EXC_BS: ~('\\');
fragment DEC: DIGIT+;
fragment HEX:('0h'|'0H')[0-9a-fA-F]+;
fragment DIGIT : [0-9];
fragment LETTER: [a-zA-Z];
fragment EX: '^'[-+]?Int_const;