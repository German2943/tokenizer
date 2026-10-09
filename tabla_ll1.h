#ifndef TABLA_LL1_H
#define TABLA_LL1_H

enum
{
    NT_Q,
    NT_L,
    NT_l,
    NT_W,
    NT_E,
    NT_e,
    NT_T,
    NT_t,
    NT_F,
    NT_C,
    NT_O,
    NT_V,
    NUM_NT
};

enum
{
    TK_SELECT,
    TK_WHERE,
    TK_AND,
    TK_OR,
    TK_EQ,
    TK_NOT_EQ,
    TK_GT,
    TK_LT,
    TK_GTEQ,
    TK_LTEQ,
    TK_ID,
    TK_INT_NUM,
    TK_STRING,
    TK_COMMA,
    TK_SEMICOLON,
    TK_LPAR,
    TK_RPAR,
    TK_FIN, /* TK_FIN = $ */
    NUM_TK
};

static const int tabla[NUM_NT][NUM_TK] = {
    [NT_Q] = {[TK_SELECT] = 1},

    [NT_L] = {[TK_ID] = 2},

    [NT_l] = {[TK_COMMA] = 3,
              [TK_WHERE] = 4,
              [TK_SEMICOLON] = 4},

    [NT_W] = {[TK_WHERE] = 5,
              [TK_SEMICOLON] = 6},

    [NT_E] = {[TK_LPAR] = 7, [TK_ID] = 7},

    [NT_e] = {[TK_OR] = 8,
              [TK_SEMICOLON] = 9,
              [TK_RPAR] = 9},

    [NT_T] = {[TK_LPAR] = 10, [TK_ID] = 10},

    [NT_t] = {[TK_AND] = 11,
              [TK_OR] = 12,
              [TK_SEMICOLON] = 12,
              [TK_RPAR] = 12},

    [NT_F] = {[TK_LPAR] = 13, [TK_ID] = 14},

    [NT_C] = {[TK_ID] = 15},

    [NT_O] = {[TK_EQ] = 16, [TK_NOT_EQ] = 17, [TK_LT] = 18, [TK_GT] = 19, [TK_LTEQ] = 20, [TK_GTEQ] = 21},

    [NT_V] = {[TK_INT_NUM] = 22, [TK_STRING] = 24, [TK_ID] = 23},
};

#endif