#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TT_estados 27

typedef struct tabela
{
    char *regiao;
    char *estados;
    int casosConfirmados;
    int mortes;
} tipoTabela;

void exibeTabela(tipoTabela **tabela);

void LerArquivo(tipoTabela **corona, char *filepath);

void regiao(tipoTabela **corona);

void LetraA(tipoTabela **corona);
void LetraB(tipoTabela **corona);
void LetraC(tipoTabela **corona);