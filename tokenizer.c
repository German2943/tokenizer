#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"
char *transicion_getter(char caracter, char *estado)
{

    FILE *f = fopen("dfa_datos.txt", "r");
    char linea[100];

    while (fgets(linea, sizeof(linea), f) != NULL)
    {

        char estado_origen[strcspn(linea, ",") + 1];
        estado_origen[0] = linea[0];
        int i = 1;
        for (i; i <= strcspn(linea, ",") + 1; i++)
        {
            if (linea[i] == ',')
            {
                estado_origen[i] = '\0';
                break;
            }
            estado_origen[i] = linea[i];
        }
        char caracter_leido[strcspn(linea + i + 1, ",") + 1];
        caracter_leido[0] = linea[i + 1];
        int j = 1;
        for (j; j <= strcspn(linea + i + 1, ",") + 1; j++)
        {
            if (linea[i + 1 + j] == ',')
            {
                caracter_leido[j] = '\0';
                break;
            }
            caracter_leido[j] = linea[i + 1 + j];
        }
        char estado_destino[strcspn(linea + i + 1 + j + 1, "\n") + 1];
        estado_destino[0] = linea[i + 1 + j + 1];
        int k = 1;
        for (k; k <= strcspn(linea + i + 1 + j + 1, "\n") + 1; k++)
        {
            if (linea[i + 1 + j + 1 + k] == '\n')
            {
                estado_destino[k] = '\0';
                break;
            }
            estado_destino[k] = linea[i + 1 + j + 1 + k];
        }

        if (atoi(estado) == atoi(estado_origen) && caracter == caracter_leido[0])
        {

            char *result = malloc(strlen(estado_destino) + 1);
            strcpy(result, estado_destino);
            fclose(f);
            return result;
        }
    }

    return "253";
}

char *lexem_identifier(char *lexem) // given a str, gives what is its state
{
    char *estado = (char *)malloc((strlen(lexem) + 1) * sizeof(char));
    estado[0] = '0';
    estado[1] = '\0';

    for (int i = 0; i < strlen(lexem) + 1; i++)
    {
        if (lexem[i] == '\0')
        {
            break;
        }
        if (transicion_getter(lexem[i], estado) == NULL)
        {
            return NULL;
        }

        strcpy(estado, transicion_getter(lexem[i], estado));
        estado[strlen(lexem) + 1] = '\0';
    }
    return estado;
}

char *string_divider(FILE *f) // reads the input file and makes an array with all its characters
{

    int capacidad = 100;
    int elementos = 0;
    char *ptr = (char *)malloc(sizeof(char) * capacidad);
    char *tmp;

    int c;
    int iteration = 0;
    while ((c = fgetc(f)) != EOF)
    {
        if (elementos >= capacidad)
        {
            capacidad = capacidad * 2;
            tmp = (char *)realloc(ptr, capacidad);
            ptr = tmp;
        }

        ptr[iteration] = (char)c;
        elementos++;
        iteration++;
    }
    ptr[elementos] = '\0';
    return ptr;
}

char *token_assigner(int estado) // given an state, tells the token it produces
{
    FILE *f = fopen("tokens.txt", "r");
    char linea[100];
    while (fgets(linea, sizeof(linea), f) != NULL)
    {
        char estado_origen[strcspn(linea, ",") + 1];
        estado_origen[0] = linea[0];
        int i = 1;
        for (i; i <= strcspn(linea, ",") + 1; i++)
        {
            if (linea[i] == ',')
            {
                estado_origen[i] = '\0';
                break;
            }
            estado_origen[i] = linea[i];
        }
        char token[strcspn(linea + i + 1, "\n") + 1];
        token[0] = linea[i + 1];
        int j = 1;
        for (j; j <= strcspn(linea + i + 1, "\n") + 1; j++)
        {
            if (linea[i + 1 + j] == '\n')
            {
                token[j] = '\0';
                break;
            }
            token[j] = linea[i + 1 + j];
        }
        if (atoi(estado_origen) == estado)
        {

            char *s = malloc(strlen(token) + 1);
            strcpy(s, token);
            fclose(f);
            return s;
        }
    }
    fclose(f);
    return "INVALID_TOKEN";
}
int es_aceptacion(int valor)
{
    int aceptacion[238] = {1, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 155, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 243, 247, 249, 248, 251};
    for (int i = 0; i < 238; i++)
    {
        if (valor == aceptacion[i])
        {
            return 0;
        }
    }
    return 1;
}

char *keyword_identifier(char *lexem)
{

    char lexemas_posibles[44][15] = {
        "auto",
        "double",
        "int",
        "struct",
        "break",
        "else",
        "long",
        "switch",
        "case",
        "enum",
        "register",
        "typedef",
        "char",
        "extern",
        "return",
        "union",
        "const",
        "float",
        "short",
        "unsigned",
        "continue",
        "for",
        "signed",
        "void",
        "default",
        "goto",
        "sizeof",
        "volatile",
        "do",
        "if",
        "static",
        "while",
        "scanf",
        "print",
        "define",
        "elif",
        "endif",
        "error",
        "if",
        "ifdef",
        "ifndef",
        "include",
        "message",
        "undef"};
    char keyword_token[44][15] = {"AUTO", "DOUBLE", "INT", "STRUCT", "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM", "REGISTER", "TYPEDEF", "CHAR", "EXTERN", "RETURN", "UNION", "CONST", "FLOAT", "SHORT", "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID", "DEFAULT", "GOTO", "SIZEOF", "VOLATILE", "DO", "IF", "STATIC", "WHILE", "READ", "WRITE", "DEFINE", "ELIF", "ENDIF", "ERROR", "IF", "IFDEF", "IFNDEF", "INCLUDE", "MESSAGE", "UNDEF"};

    /*
    char lexemas_posibles[4][15] = {"SELECT", "WHERE", "AND", "OR"};
    char keyword_token[4][15] = {"SELECT", "WHERE", "AND", "OR"};
    */
    char *match;
    int length = sizeof(lexemas_posibles) / sizeof(lexemas_posibles[0]);
    int i = 0;
    while (i < length)
    {

        if (strcmp(lexem, lexemas_posibles[i]) == 0)
        {

            match = (char *)malloc(sizeof(char) * strlen(keyword_token[i]));
            match = strcpy(match, keyword_token[i]);

            return match;
        }

        i++;
    }

    match = (char *)malloc(sizeof(char) * 3);
    match = strcpy(match, "ID");
    return match;
}
int maximalMunch(char *str, TOKEN **tokens, int *capacidad_tokens, int *token_counter)
{

    int inicio = 0;

    while (inicio < strlen(str))
    {
        int estado = 0;
        int ultima_pos_aceptora = -1;
        int ultimo_token_aceptado = -1;
        int pos = inicio;
        while (pos < strlen(str))
        {
            char buffer[12];
            sprintf(buffer, "%d", estado);
            int siguiente = atoi(transicion_getter(str[pos], buffer));
            if (siguiente == 253)
                break;
            estado = siguiente;
            pos++;
            if (es_aceptacion(estado) == 0)
            {
                ultima_pos_aceptora = pos;
                ultimo_token_aceptado = estado;
            }
        }

        if (ultima_pos_aceptora == -1)
        {
            inicio++;
        }
        else
        {
            char temp[ultima_pos_aceptora - inicio + 1];
            temp[ultima_pos_aceptora - inicio] = '\0';
            for (int x = 0; x < ultima_pos_aceptora - inicio; x++)
            {
                temp[x] = str[inicio + x];
            }
            printf("version primitiva\n");
            char *label = token_assigner(estado);
            if (label[0] == 'I' && label[1] == 'D')
            {

                free(label);
                label = NULL;
                label = keyword_identifier(temp);
            }
            if ((*token_counter) >= (*capacidad_tokens))
            {
                (*capacidad_tokens) *= 2;
                (*tokens) = realloc((*tokens), sizeof(TOKEN) * (*capacidad_tokens));
            }

            (*tokens)[(*token_counter)].label = (char *)malloc(sizeof(char) * strlen(label));
            (*tokens)[(*token_counter)].label = strcpy((*tokens)[(*token_counter)].label, label);

            (*tokens)[(*token_counter)].lexem = (char *)malloc(sizeof(char) * strlen(temp));
            (*tokens)[(*token_counter)].lexem = strcpy((*tokens)[(*token_counter)].lexem, temp);

            free(label);
            printf("(\"%s\",%s)\n", temp, token_assigner(estado));
            inicio = ultima_pos_aceptora;
            (*token_counter)++;
        }
    }

    return 0;
}
int maximal_munch(char *str, TOKEN **tokens, int *capacidad_tokens, int *token_counter)
{
    int inicio = 0;

    while (inicio < strlen(str))
    {
        int estado = 0;
        int ultima_pos_aceptora = -1;
        int ultimo_token_aceptado = -1;
        int pos = inicio;
        while (pos < strlen(str))
        {
            char buffer[12];
            int siguiente = atoi(transicion_getter(str[pos], buffer));
            if (siguiente == 253)
                break;
            estado = siguiente;
            pos++;
            if (es_aceptacion(estado) == 0)
            {
                ultima_pos_aceptora = pos;
                ultimo_token_aceptado = estado;
            }
        }

        if (ultima_pos_aceptora == -1)
        {
            inicio++;
        }
        else
        {
            char temp[ultima_pos_aceptora - inicio + 1];
            temp[ultima_pos_aceptora - inicio] = '\0';
            for (int x = 0; x < ultima_pos_aceptora - inicio; x++)
            {
                temp[x] = str[inicio + x];
            }
            char *token_label = (char *)malloc(sizeof(char) * 15);
            token_label = token_assigner(estado);

            if (token_label[0] == 'I' && token_label[1] == 'D')
            {

                free(token_label);
                token_label = NULL;

                token_label = keyword_identifier(temp);
            }
            TOKEN new_token;
            new_token.label = token_label;

            new_token.lexem = temp;
            if ((*token_counter) >= *capacidad_tokens)
            {
                (*capacidad_tokens) = (*capacidad_tokens) * 2;
                (*tokens) = realloc((*tokens), (*capacidad_tokens) * sizeof(TOKEN));
            }

            (*tokens)[(*token_counter)].label = (char *)malloc(sizeof(char) * strlen(token_label));
            strcpy((*tokens)[(*token_counter)].label, token_label);

            (*tokens)[(*token_counter)].lexem = (char *)malloc(sizeof(char) * strlen(temp));
            strcpy((*tokens)[(*token_counter)].lexem, temp);

            free(token_label);

            inicio = ultima_pos_aceptora;
            (*token_counter)++;
        }
    }

    return 0;
}
void reader(FILE *f, TOKEN **tokens, int *capacidad_tokens, int *token_counter)
{
    char *raw_chars = string_divider(f);

    int index_buffer = 0;
    int capacidad_buffer = 100;
    char *buffer = (char *)malloc(sizeof(char) * capacidad_buffer);
    for (int i = 0; i <= strlen(raw_chars); i++)
    {
        if (isspace(raw_chars[i]) || i >= strlen(raw_chars))
        {
            if (strlen(buffer) == 0)
            {
                continue;
            }
            if (index_buffer >= capacidad_buffer)
            {
                capacidad_buffer = capacidad_buffer * 2;
                buffer = realloc(buffer, capacidad_buffer);
            }

            buffer[index_buffer] = '\0';
            index_buffer = 0;
            maximalMunch(buffer, tokens, capacidad_tokens, token_counter);

            continue;
        }
        if (index_buffer >= capacidad_buffer)
        {
            capacidad_buffer = capacidad_buffer * 2;
            buffer = realloc(buffer, capacidad_buffer);
        }

        buffer[index_buffer] = raw_chars[i];
        index_buffer++;
    }

    free(buffer);
    free(raw_chars);
}

char no_terminales[] = {'Q', 'L', 'l', 'W', 'E', 'e', 'T', 't', 'F', 'C', 'O', 'V'};

char simbolo_inicial = 'Q';

char terminales[][15] = {"SELECT", "WHERE", "AND", "OR", "EQ", "NOT_EQ", "GT", "LT",
                         "GTEQ", "LTEQ", "ID", "INT_NUM", "STRING", "COMMA",
                         "SEMICOLON", "LPAR", "RPAR", "$"};

int main(void)
{
    int capacidad_tokens = 100;
    int token_counter = 0;
    TOKEN(*tokens);
    tokens = (TOKEN *)malloc(sizeof(TOKEN) * capacidad_tokens);

    reader(fopen("testing.txt", "r"), &tokens, &capacidad_tokens, &token_counter);

    printf("\ntokens generados\n");

    for (int i = 0; i < token_counter; i++)
    {
        printf("#%d label=\"%s\" lexem=\"%s\"\n", i, tokens[i].label, tokens[i].lexem);
    }
    // int ok = parsear();

    for (int i = 0; i < token_counter; i++)
    {
        free((tokens[i]).label);
        free((tokens[i]).lexem);
    }
    // printf(ok ? "Consulta valida\n" : "Consulta invalida\n");

    // return ok ? 0 : 1;
    return 0;
}