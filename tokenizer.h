#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef struct TOKEN
{
    char *label;
    char *lexem;
} TOKEN;

/* Definidas (sin "static") en tokenizer.c, usadas desde parser.c */
extern int capacidad_tokens;
extern int token_counter;
extern TOKEN *tokens;

/* Implementada en parser.c; se llama al final del main de tokenizer.c */
int parsear(void);

#endif