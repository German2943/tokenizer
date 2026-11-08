# Alphabet
---
Σ={a, b, c, d, e, f, g, h, i, h, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, _, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, [, ], (, ), {, }, ., ',', ;, :, ?, ~, +, -, *, /, %, =, <, >, !, &, |, ^, ", ', \, #, ' ', '\t', '\n', '\r', '\v', '\f', EOF}

# Regular expression for each major pattern
## keywords, ID, INT_NUM, reserved words and pre-processing directives
    digit = [0−9]
    letter = [a−z A−Z]
    INT_NUM = [digit]+
    ID = [ letter | _]+[ digit | letters]∗
## tokens that use special symbols
    Logical operators
    &&, ||, !
---
    Bitwise logical operators
    &, |, ^, ~, <<, >>
---
    Relational operators
    <, >, <=, >=, ==, !=
---
    Arithmetic operators
    +, -, *, /, %, ++, --
---
    Assignment operators 
    =, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=
---
    Grouping operators
    (, ), {, }, [, ]
---
    Other operators
    , (comma), ; (semicolon), . (member access), -> (arrow, pointer member access), ? and : (ternary conditional)
---
    special characters
    #
---
    space characters
    escape_seq = \ ( n | t | r | 0 | a | b | f | v | \ | ' | " | ? )
---
    other tokens with special symbols

    any_char_except_quote_or_backslash = [^ " \ ] = (Σ − {", \})
    any_char_except_newline            = [^ \n ] = (Σ − {\n})
    any_char                           = Σ
    
    STRING = " ( any_char_except_quote_or_backslash | escape_seq )* "
    

    CHAR = ' ( any_char_except_quote_or_backslash | escape_seq ) '

    LINE_COMMENT = // ( any_char_except_newline )*
    
    not_star = Σ − {*}
    not_star_or_slash = Σ − {*, /}

    BLOCK_COMMENT = /* (not_star | *⁺ not_star_or_slash)* *⁺ /

    final regex


# TOKEN TUPLES (lexeme, label)
## keywords, ID, INT_NUM, reserved words and pre-processing directives
    digit = [0−9]
    letter = [a−z A−Z]
    INT_NUM = [digit]+
    ID = [ letter | _]+[ digit | letters]∗


    
    ID, ID
    INT_NUM, INT_NUM

    auto,AUTO
    double,DOUBLE
    int,INT
    struct,STRUCT
    break,BREAK
    else,ELSE
    long,LONG
    switch,SWITCH
    case,CASE
    enum,ENUM
    register,REGISTER
    typedef,TYPEDEF
    char,CHAR
    extern,EXTERN
    return,RETURN
    union,UNION
    const,CONST
    float,FLOAT
    short,SHORT
    unsigned,UNSIGNED
    continue,CONTINUE
    for,FOR
    signed,SIGNED
    void,VOID
    default,DEFAULT
    goto,GOTO
    sizeof,SIZEOF
    volatile,VOLATILE
    do,DO
    if,IF
    static,STATIC
    while,WHILE
    scanf,READ
    print,WRITE



    define,DEFINE
    elif,ELIF
    endif,ENDIF
    error,ERROR
    if,IF
    ifdef,IFDEF
    ifndef,IFNDEF
    include,INCLUDE
    message,MESSAGE
    undef,UNDEF 



## tokens that use special symbols
    Logical operators
    &&,ANDAND
    ||,OROR
    !,NOT_EQ
    


---
    Bitwise logical operators
    &,AND_OP
    |,OR_OP
    ^,BIT_XOR
    ~,BIT_NOT
    <<,SHL_OP
    >>,SHR_OP
---
    Relational operators
    <,LT
    >,GT
    <=,LTEQ
    >=,GTEQ
    ==,EQ
    !=,NOT_EQ
---
    Arithmetic operators
    +,PLUS
    -,MINUS
    *,MULT_OP
    /,DIV_OP
    %,MODULE
    ++, INC
    --, DEC
---
    Assignment operators 
    =,ASSIGN
    +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=
---
    Grouping operators
    (,LPAR
    ),RPAR
    {,LBRACE
    },RBRACE
    [,LSQUARE
    ],RSQUARE
---
    Other operators
    ',',COMMA
    ';' SEMICOLON
    '.',MEMBER_ACCESS
    ->,ARROW
    '?:',TERNARY
---
    special characters
    #,DIRECTIVE
---
    space characters
    escape_seq = \ ( n | t | r | 0 | a | b | f | v | \ | ' | " | ? )
    escape_seq,SPACE
---
    other tokens with special symbols

    any_char_except_quote_or_backslash = [^ " \ ] = (Σ − {", \})
    any_char_except_newline            = [^ \n ] = (Σ − {\n})
    any_char                           = Σ
    
    STRING = " ( any_char_except_quote_or_backslash | escape_seq )* "
    

    CHAR = ' ( any_char_except_quote_or_backslash | escape_seq ) '

    LINE_COMMENT = // ( any_char_except_newline )*

    BLOCK_COMMENT = /* ( any_char )*? */
