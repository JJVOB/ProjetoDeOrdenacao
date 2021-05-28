#include "estrutura.h"

int main(int argc, char const *argv[])
{

    int opcao;

    tipoTabela **tabela;

    tabela = (tipoTabela **)malloc(TT_estados * sizeof(tipoTabela *));

    do
    {

        printf("\n 0 - Sair ");
        printf("\n 1 - Exibir por região ");
        printf("\n 2 - Letra A");
        printf("\n 3 - Letra B");
        printf("\n 4 - Letra C \n ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 0:
            free(tabela);
            exit(1);
            break;

        case 1:

            system("cls");
            LerArquivo(tabela, "tabela.txt");
            regiao(tabela);
            printf("\n\n");
            exibeTabela(tabela);

            break;

        case 2:

            system("cls");
            LerArquivo(tabela, "tabela.txt");
            LetraA(tabela);
            printf("\n\n");
            exibeTabela(tabela);

            break;

        case 3:

            system("cls");
            LerArquivo(tabela, "tabela.txt");
            LetraB(tabela);
            printf("\n\n");
            exibeTabela(tabela);

            break;

        case 4:

            system("cls");
            LerArquivo(tabela, "tabela.txt");
            LetraC(tabela);
            printf("\n\n");
            exibeTabela(tabela);

            break;

        default:
            printf("\n Opção invalida \n");
            break;
        }

    } while (opcao != 0);

    free(tabela);
    return 0;
}
