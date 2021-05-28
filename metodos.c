#include "estrutura.h"

void exibeTabela(tipoTabela **tabela)
{
    int i;

    int soma = 0;
    int soma2 = 0;
    for (i = 0; i < TT_estados; i++)
    {
        soma = soma + tabela[i]->casosConfirmados;
        soma2 = soma2 + tabela[i]->mortes;
    }

    printf("\n\tTabela 1 - Todos os casos de Coronavírus no Brasil até 08/03/2021\n");
    printf("\n\t _____________________________________________________________________________________\n\n");
    printf("\t   ESTADOS \t  Casos Confirmados \t \t Mortes \t\t   Região    ");
    printf("\n\t _____________________________________________________________________________________\n");
    for (i = 0; i < TT_estados; i++)
    {
        printf("\n\t     %s \t\t %d  \t\t  %d  \t\t %s ", tabela[i]->estados, tabela[i]->casosConfirmados, tabela[i]->mortes, tabela[i]->regiao);
    }
    printf("\n\t_____________________________________________________________________________________\n");
    printf("\n\tFonte: Secretarias de Estado de Saúde. Dados tratados por Álvaro Justen e colaboradores/Brasil.IO \n");
    printf("\n\n");
    printf("\n Quantidade de casos confirmado -[%d] ", soma);
    printf("\n Quantidade de mortos -----------[%d] ", soma2);
    printf("\n\n");
}

void LerArquivo(tipoTabela **tabela, char *filepath)
{
    FILE *arquivo;

    int i = 0;
    int mort;
    int casos;
    char ESTD[200];
    char REG[200];

    arquivo = fopen(filepath, "r");

    if (arquivo == NULL)
    {
        printf("\n Houve um erro ao abrir o arquivo . \n ");
        return;
    }

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %d %s %[^\n]", &casos, &mort, ESTD, REG);

        tabela[i] = (tipoTabela *)malloc(sizeof(tipoTabela));

        tabela[i]->casosConfirmados = casos;

        tabela[i]->mortes = mort;

        tabela[i]->estados = (char *)malloc((2 + 1) * sizeof(char));

        ESTD[2] = '\0';

        strcpy(tabela[i]->estados, ESTD);

        tabela[i]->regiao = (char *)malloc((12 + 1) * sizeof(char));

        REG[12] = '\0';

        strcpy(tabela[i]->regiao, REG);

        i++;
    }

    fclose(arquivo);
}

void regiao(tipoTabela **corona) // bubble
{
    tipoTabela *DadosAUX;
    int i, j;

    for (i = 0; i < TT_estados; i++)
    {
        for (j = 0; j < TT_estados; j++)
        {
            if (strcmp(corona[j]->regiao, corona[i]->regiao) > 0)
            {
                DadosAUX = corona[i];
                corona[i] = corona[j];
                corona[j] = DadosAUX;
            }
        }
    }
}

void LetraA(tipoTabela **corona) // Bubble sort
{
    tipoTabela *DadosAUX;
    int i, j;

    for (i = 0; i < TT_estados; i++)
    {
        for (j = 0; j < TT_estados; j++)
        {
            if (strcmp(corona[j]->regiao, corona[i]->regiao) < 0)
            {
                DadosAUX = corona[i];
                corona[i] = corona[j];
                corona[j] = DadosAUX;
            }
        }
    }

    for (i = 0; i < TT_estados; i++)
    {
        for (j = 0; j < TT_estados; j++)
        {
            if (strcmp(corona[j]->estados, corona[i]->estados) < 0)
            {
                DadosAUX = corona[i];
                corona[i] = corona[j];
                corona[j] = DadosAUX;
            }
        }
    }
}

void LetraB(tipoTabela **corona) // Selection sort
{
    tipoTabela *DadosAUX;

    int menorPosicao;
    int i, j;

    for (i = 0; i < TT_estados; i++)
    {
        menorPosicao = i;
        for (j = i + 1; j < TT_estados; j++)
        {
            if (corona[menorPosicao]->casosConfirmados < corona[j]->casosConfirmados)
            {
                menorPosicao = j;
            }
        }
        if (menorPosicao != i)

        {
            DadosAUX = corona[i];
            corona[i] = corona[menorPosicao];
            corona[menorPosicao] = DadosAUX;
        }
    }
}

void LetraC(tipoTabela **corona) // Insertion sort
{
    int n;

    int posicaoAuxiliar;
    tipoTabela *DadosAUX;
    for (n = 1; n < TT_estados; n++)
    {
        posicaoAuxiliar = n;
        while (corona[posicaoAuxiliar - 1]->mortes > corona[posicaoAuxiliar]->mortes && posicaoAuxiliar > 0)
        {
            DadosAUX = corona[posicaoAuxiliar];
            corona[posicaoAuxiliar] = corona[posicaoAuxiliar - 1];
            corona[posicaoAuxiliar - 1] = DadosAUX;

            posicaoAuxiliar--;
        }
    }
}
