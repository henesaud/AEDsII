// By Hene S. S.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp2.h"
#define TAM 60000

int main(int argc, const char *argv[])
{
    int i;
    FILE *arquivo = fopen(argv[1], "r");
    FILE *saida = fopen("saida.txt", "w");
    int a = atoi(argv[2]);
    int c = 0, d = 3000, o, p;

    if (argc > 3)
    {
        c = atoi(argv[3]);
    }
    if (argc > 4)
    {
        d = atoi(argv[4]);
    }

    item_list_player *lista1 = (item_list_player *)malloc(sizeof(item_list_player) * TAM);
    item_list_confronto *lista2 = (item_list_confronto *)malloc(sizeof(item_list_confronto) * TAM);

    item_list_player *lista3 = (item_list_player *)malloc(sizeof(item_list_player) * TAM);
    item_list_confronto *lista4 = (item_list_confronto *)malloc(sizeof(item_list_confronto) * TAM);

    node *root = NULL;
    nodec *root2 = NULL;

    switch (a)
    {
    case 1:
        o = lista(c, d, arquivo, lista1);
        rewind(arquivo);
        p = lista_confronto(c, d, arquivo, lista2);
        exporta_lista(saida, lista1, lista2, o, p);

        break;

    case 2:
        o = arvore(c, d, arquivo, root, lista1);
        rewind(arquivo);
        p = arvore_confronto(c, d, arquivo, root2, lista2);
        exporta_lista(saida, lista1, lista2, o, p);

        break;

    case 3:
        o = hash(c, d, arquivo, lista1, lista3);
        rewind(arquivo);
        p = hash_confronto(c, d, arquivo, lista2, lista4);
        exporta_lista(saida, lista3, lista4, o, p);

        break;

    default:
        printf("erro: n invalido de entrada. precisa-se escolher uma estrutura de dados");
    }

    free(lista1);
    free(lista2);
    free(lista3);
    free(lista4);
    free(root);
    free(root2);
    fcloseall();
}
