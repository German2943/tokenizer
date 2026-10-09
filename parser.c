#include <stdio.h>
#include <string.h>

#include "tokenizer.h"    /* TOKEN, tokens, token_counter, capacidad_tokens */
#include "producciones.h" /* incluye tabla_ll1.h */

#define MAX_PILA 256

extern char terminales[][15];
extern char no_terminales[];

static int label_a_tk(const char *label)
{
    for (int k = 0; k < NUM_TK; k++)
        if (strcmp(label, terminales[k]) == 0)
            return k;
    return -1;
}

static int token_actual(int i)
{
    if (i >= token_counter)
        return TK_FIN;
    return label_a_tk(tokens[i].label);
}

static int pila[MAX_PILA];
static int tope;

static int apilar(int s)
{
    if (tope + 1 >= MAX_PILA)
        return 0; /* desbordamiento */
    pila[++tope] = s;
    return 1;
}

int parsear(void)
{
    int i = 0; /* puntero al token actual */

    tope = -1;
    apilar(TK_FIN);       /* fondo de la pila */
    apilar(SYM_NT(NT_Q)); /* símbolo inicial */

    while (1)
    {
        int cima = pila[tope];
        int token = token_actual(i);

        if (token < 0)
        {
            fprintf(stderr,
                    "Error: token #%d con label desconocido \"%s\"\n",
                    i, tokens[i].label);
            return 0;
        }

        /* CASO A: terminal (o $) en la cima -> comparar */
        if (ES_TERMINAL(cima))
        {
            if (cima == token)
            {
                if (cima == TK_FIN)
                    return 1;
                tope--;
                i++;
            }
            else
            {
                fprintf(stderr,
                        "Error sintactico (token #%d): se esperaba %s, llego %s\n",
                        i, terminales[cima], terminales[token]);
                return 0;
            }
        }

        else
        {
            int n = tabla[IDX_NT(cima)][token];

            if (n == 0)
            {
                fprintf(stderr,
                        "Error sintactico (token #%d): %s inesperado al analizar <%c>\n",
                        i, terminales[token], no_terminales[IDX_NT(cima)]);
                return 0;
            }

            const Produccion *p = &producciones[n];
            tope--;
            for (int k = p->len - 1; k >= 0; k--)
            {
                if (!apilar(p->rhs[k]))
                {
                    fprintf(stderr, "Error: desbordamiento de pila\n");
                    return 0;
                }
            }
        }
    }
}