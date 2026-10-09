#ifndef PRODUCCIONES_H
#define PRODUCCIONES_H

#include "tabla_ll1.h"

#define SYM_NT(x) (NUM_TK + (x))
#define ES_TERMINAL(s) ((s) < NUM_TK)
#define ES_NO_TERMINAL(s) ((s) >= NUM_TK)
#define IDX_NT(s) ((s) - NUM_TK)

#define MAX_RHS 4
#define NUM_PROD 25

typedef struct
{
    int lhs;
    int len;
    int rhs[MAX_RHS];
} Produccion;

static const Produccion producciones[NUM_PROD] = {
    [0] = {0, 0, {0}}, /* sin uso: 0 en la tabla = error */

    [1] = {NT_Q, 4, {TK_SELECT, SYM_NT(NT_L), SYM_NT(NT_W), TK_SEMICOLON}},

    [2] = {NT_L, 2, {TK_ID, SYM_NT(NT_l)}},

    [3] = {NT_l, 2, {TK_COMMA, SYM_NT(NT_L)}},
    [4] = {NT_l, 0, {0}},

    [5] = {NT_W, 2, {TK_WHERE, SYM_NT(NT_E)}},
    [6] = {NT_W, 0, {0}},

    [7] = {NT_E, 2, {SYM_NT(NT_T), SYM_NT(NT_e)}},

    [8] = {NT_e, 3, {TK_OR, SYM_NT(NT_T), SYM_NT(NT_e)}},
    [9] = {NT_e, 0, {0}},

    [10] = {NT_T, 2, {SYM_NT(NT_F), SYM_NT(NT_t)}},

    [11] = {NT_t, 3, {TK_AND, SYM_NT(NT_F), SYM_NT(NT_t)}},
    [12] = {NT_t, 0, {0}},

    [13] = {NT_F, 3, {TK_LPAR, SYM_NT(NT_E), TK_RPAR}},
    [14] = {NT_F, 1, {SYM_NT(NT_C)}},

    [15] = {NT_C, 3, {TK_ID, SYM_NT(NT_O), SYM_NT(NT_V)}},

    [16] = {NT_O, 1, {TK_EQ}},
    [17] = {NT_O, 1, {TK_NOT_EQ}},
    [18] = {NT_O, 1, {TK_LT}},
    [19] = {NT_O, 1, {TK_GT}},
    [20] = {NT_O, 1, {TK_LTEQ}},
    [21] = {NT_O, 1, {TK_GTEQ}},

    [22] = {NT_V, 1, {TK_INT_NUM}},
    [23] = {NT_V, 1, {TK_ID}},
    [24] = {NT_V, 1, {TK_STRING}},
};

#endif