// By Hene S. S.

#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAM 60000

int gera_indice(char *nome)
{
    int i = strlen(nome) - 2;
    int j, peso = 3, fin = 0;
    for (j = 0; j < i; j++)
    {
        fin += (nome[j] * (18 + peso++));
    }
    return fin;
}

void insere_hash_player(item_list_player *lista1, item_list_player key, int *contador)
{

    int h = gera_indice(key.nome);
    h = h % TAM;
    int i;

    if ((lista1[h].c == 0))
    {

        (*contador)++;
        strcpy(lista1[h].nome, key.nome);
        lista1[h].pontos = key.pontos;
        lista1[h].saldo = key.saldo;
        lista1[h].gols = key.gols;
        lista1[h].gols_sofridos = key.gols_sofridos;
        lista1[h].jogos = key.jogos;
        lista1[h].vitorias = key.vitorias;
        lista1[h].empates = key.empates;
        lista1[h].derrotas = key.derrotas;
        lista1[h].aproveitamento = key.aproveitamento;
        lista1[h].c = 2;
    }

    else if ((lista1[h].c == 2) && (strcmp(key.nome, lista1[h].nome) == 0))
    {

        lista1[h].pontos += key.pontos;
        lista1[h].saldo += key.saldo;
        lista1[h].gols += key.gols;
        lista1[h].gols_sofridos += key.gols_sofridos;
        lista1[h].jogos += key.jogos;
        lista1[h].vitorias += key.vitorias;
        lista1[h].empates += key.empates;
        lista1[h].derrotas += key.derrotas;
        lista1[h].aproveitamento += key.aproveitamento;
    }

    else if ((lista1[h].c == 2) && ((strcmp(key.nome, lista1[h].nome)) != 0))
        for (i = 0; i < 1000; i++)
        {
            h = (h + 1) % TAM;

            if ((strcmp(lista1[h].nome, key.nome) == 0))
            {
                lista1[h].pontos += key.pontos;
                lista1[h].saldo += key.saldo;
                lista1[h].gols += key.gols;
                lista1[h].gols_sofridos += key.gols_sofridos;
                lista1[h].jogos += key.jogos;
                lista1[h].vitorias += key.vitorias;
                lista1[h].empates += key.empates;
                lista1[h].derrotas += key.derrotas;
                lista1[h].aproveitamento += key.aproveitamento;
                break;
            }

            else if (lista1[h].c == 0)
            {
                (*contador)++;
                strcpy(lista1[h].nome, key.nome);
                lista1[h].pontos = key.pontos;
                lista1[h].saldo = key.saldo;
                lista1[h].gols = key.gols;
                lista1[h].gols_sofridos = key.gols_sofridos;
                lista1[h].jogos = key.jogos;
                lista1[h].vitorias = key.vitorias;
                lista1[h].empates = key.empates;
                lista1[h].derrotas = key.derrotas;
                lista1[h].aproveitamento = key.aproveitamento;
                lista1[h].c = 2;
                break;
            }
        }
    }
}

void insere_hash_confronto(item_list_confronto *lista2, item_list_confronto key, char *nome, int *contador)
{

    int h = gera_indice(nome);
    h = h % TAM;
    int i;

    if ((lista2[h].c == 0))
    {

        (*contador)++;
        strcpy(lista2[h].nome_a, key.nome_a);
        strcpy(lista2[h].nome_b, key.nome_b);
        strcpy(lista2[h].nome_c, nome);
        lista2[h].confrontos = 1;
        lista2[h].c = 2;
        return;
    }

    else if ((lista2[h].c == 2) && (strcmp(nome, lista2[h].nome_c) == 0))
    {

        lista2[h].confrontos++;
        return;
    }

    else if ((lista2[h].c == 2) && ((strcmp(nome, lista2[h].nome_c)) != 0))
    { // printf("%s \n", key.nome);
        for (i = 0; i < 1000; i++)
        {
            h = (h + 1) % TAM;

            if ((strcmp(lista2[h].nome_c, nome) == 0))
            {
                lista2[h].confrontos++;
                break;
                return;
            }

            else if (lista2[h].c == 0)
            {
                (*contador)++;

                strcpy(lista2[h].nome_a, key.nome_a);
                strcpy(lista2[h].nome_b, key.nome_b);
                strcpy(lista2[h].nome_c, nome);
                lista2[h].confrontos = 1;
                lista2[h].c = 2;
                break;
                return;
            }
        }
    }
}

int hash(int c, int d, FILE *arquivo, item_list_player *lista1, item_list_player *lista3)
{
    int pontoA, pontoB, aux4, g = 0;
    int *contador = (int *)malloc(sizeof(int));
    (*contador) = 0;
    int *h = (int *)malloc(sizeof(int));
    int A, B;
    float data;
    char aux1[100];
    char aux2[100];
    char aux3[200]; // auxiliar lixo;
    fscanf(arquivo, "%s", &aux3);

    item_list_player aux6;
    aux6.aproveitamento = 0.0;
    aux6.derrotas = aux6.empates = aux6.gols = aux6.gols_sofridos = aux6.jogos = aux6.pontos = aux6.saldo = aux6.vitorias = 0;

    while ((fscanf(arquivo, "%f,%[^,],%[^,],%d,%d", &data, &aux1, &aux2, &pontoA, &pontoB)) > 0)
    {
        fgets(&aux3, ",%s", arquivo);
        aux4 = data / 10000;
        A = B = 0;

        if (strncmp(aux1, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux1, "St. Vincent and the Grenadine");
        if (strncmp(aux2, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux2, "St. Vincent and the Grenadine");

        if ((aux4 >= c) && (aux4 <= d) && ((strncmp(",FIFA World Cup", aux3, 14)) == 0))
        {
            if (pontoA > pontoB)
                A = 3;
            if (pontoB > pontoA)
                B = 3;
            if (pontoA == pontoB)
                A = B = 1;

            strcpy(aux6.nome, aux1);
            aux6.pontos = A;
            aux6.saldo = (pontoA - pontoB);
            aux6.gols = pontoA;
            if (A == 3)
                aux6.vitorias = 1;
            if (A == 1)
                aux6.empates = 1;
            if (B == 3)
                aux6.derrotas = 1;
            aux6.jogos = 1;
            aux6.gols_sofridos = pontoB;
            insere_hash_player(lista1, aux6, contador);

            strcpy(aux6.nome, aux2);
            aux6.pontos = B;
            aux6.saldo = (pontoB - pontoA);
            aux6.gols = pontoB;
            if (B == 3)
                aux6.vitorias = 1;
            if (B == 1)
                aux6.empates = 1;
            if (A == 3)
                aux6.derrotas = 1;
            aux6.jogos = 1;
            aux6.gols_sofridos = pontoA;
            insere_hash_player(lista1, aux6, contador);
        }
    }

    for (int i = 0; i < 60000; i++)
    {
        if (lista1[i].c == 2)
        {
            item_list_cpy(lista1, lista3, i, g++);
        }
    }
    aproveitamento(lista3, (*contador));
    mergesort_ordena_lista(lista3, 0, (*contador) - 1);

    return ((*contador));
}

int hash_confronto(int c, int d, FILE *arquivo, item_list_confronto *lista2, item_list_confronto *lista4)
{
    int pontoA, pontoB, aux4, g = 0;
    int *contador = (int *)malloc(sizeof(int));
    (*contador) = 0;
    int *h = (int *)malloc(sizeof(int));
    float data;
    char aux1[100];
    char aux2[100];
    char aux3[200]; // auxiliar lixo;
    char aux8[200];
    fscanf(arquivo, "%s", &aux3);

    item_list_confronto aux6;
    aux6.confrontos = 0;

    while ((fscanf(arquivo, "%f,%[^,],%[^,],%d,%d", &data, &aux1, &aux2, &pontoA, &pontoB)) > 0)
    {
        fgets(&aux3, ",%s", arquivo);
        aux4 = data / 10000;

        if (strncmp(aux1, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux1, "St. Vincent and the Grenadine");
        if (strncmp(aux2, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux2, "St. Vincent and the Grenadine");

        if ((aux4 >= c) && (aux4 <= d))
        {

            if (strcmp(aux1, aux2) < 0)
            {

                strcpy(aux8, aux1);
                strcat(aux8, aux2);

                strcpy(aux6.nome_a, aux1);
                strcpy(aux6.nome_b, aux2);

                strcpy(aux6.nome_c, aux8);
            }

            else
            {

                strcpy(aux8, aux2);
                strcat(aux8, aux1);

                strcpy(aux6.nome_a, aux2);
                strcpy(aux6.nome_b, aux1);
                strcpy(aux6.nome_c, aux8);
            }

            insere_hash_confronto(lista2, aux6, aux8, contador);
        }
    }

    int i;

    for (i = 0; i < 60000; i++)
    {
        if (lista2[i].c == 2)
        {
            item_confr_cpy(lista2, lista4, i, g++);
        }
    }

    mergesort_ordena_confronto(lista4, 0, *(contador)-1);

    return ((*contador));
}

int pesquisa_lista(item_list_player *lista1, char *nome, int tamanho)
{
    int i;
    for (i = 0; i < (tamanho + 2); i++)
    {
        if ((strcmp(lista1[i].nome, nome)) == 0)
            return i;
    }
    return -1;
}

int pesquisa_lista_confronto(item_list_confronto *lista2, char *nome1, char *nome2, int tamanho)
{
    int i;
    for (i = 0; i < (tamanho + 2); i++)
    {
        if (((strcmp(lista2[i].nome_a, nome1) == 0) && (strcmp(lista2[i].nome_b, nome2) == 0)) || ((strcmp(lista2[i].nome_a, nome2) == 0) && (strcmp(lista2[i].nome_b, nome1) == 0)))
            return i;
    }
    return -1;
}

void aproveitamento(item_list_player *lista1, int tamanho)
{
    float j, k;
    int i;

    for (i = 0; i < tamanho; i++)
    {
        j = lista1[i].pontos;
        j = j * 100;

        k = lista1[i].jogos;
        k = k * 3;

        if (k != 0)
            lista1[i].aproveitamento = j / k;
    }
}

void item_list_cpy(item_list_player *src, item_list_player *dest, int a, int b)
{
    strcpy(dest[b].nome, src[a].nome);
    dest[b].pontos = src[a].pontos;
    dest[b].saldo = src[a].saldo;
    dest[b].gols = src[a].gols;
    dest[b].gols_sofridos = src[a].gols_sofridos;
    dest[b].jogos = src[a].jogos;
    dest[b].vitorias = src[a].vitorias;
    dest[b].empates = src[a].empates;
    dest[b].derrotas = src[a].derrotas;
    dest[b].aproveitamento = src[a].aproveitamento;
}
void item_confr_cpy(item_list_confronto *src, item_list_confronto *dest, int a, int b)
{
    strcpy(dest[b].nome_a, src[a].nome_a);
    strcpy(dest[b].nome_b, src[a].nome_b);
    dest[b].confrontos = src[a].confrontos;
}

void mergesort_merge_l(item_list_player *lista1, int esq, int meio, int dir, int h)
{
    int i, j, k;
    int aTam = meio - esq + 1;
    int bTam = dir - meio;

    item_list_player *a = (item_list_player *)malloc(sizeof(item_list_player) * aTam);
    item_list_player *b = (item_list_player *)malloc(sizeof(item_list_player) * bTam);

    for (i = 0; i < aTam; i++)
        item_list_cpy(lista1, a, i + esq, i);

    for (i = 0; i < bTam; i++)
        item_list_cpy(lista1, b, (i + meio + 1), i);

    for (i = 0, j = 0, k = esq; k <= dir; k++)
    {
        if (i == aTam)
            item_list_cpy(b, lista1, j++, k);

        else if (j == bTam)
            item_list_cpy(a, lista1, i++, k);

        else

            switch (h)
            {
            case 0:
                if (a[i].pontos >= b[j].pontos)
                    item_list_cpy(a, lista1, i++, k);
                else
                    item_list_cpy(b, lista1, j++, k);
                break;

            case 1:
                if (a[i].aproveitamento >= b[j].aproveitamento)
                    item_list_cpy(a, lista1, i++, k);
                else
                    item_list_cpy(b, lista1, j++, k);
                break;

            case 2:
                if (a[i].saldo >= b[j].saldo)
                    item_list_cpy(a, lista1, i++, k);
                else
                    item_list_cpy(b, lista1, j++, k);
                break;

            case 3:
                if (a[i].gols >= b[j].gols)
                    item_list_cpy(a, lista1, i++, k);
                else
                    item_list_cpy(b, lista1, j++, k);
                break;

            case 4:
                if (strcmp(a[i].nome, b[j].nome) < 0)
                    item_list_cpy(a, lista1, i++, k);
                else
                    item_list_cpy(b, lista1, j++, k);
                break;

            default:
                return;
            }
    }
    free(a);
    free(b);
}

void mergesort_ordena_l(item_list_player *lista1, int esq, int dir, int h)
{
    if (esq == dir)
        return;
    int meio = (esq + dir) / 2;
    mergesort_ordena_l(lista1, esq, meio, h);
    mergesort_ordena_l(lista1, meio + 1, dir, h);
    mergesort_merge_l(lista1, esq, meio, dir, h);
}

void mergesort_ordena_lista(item_list_player *lista1, int esq, int dir)
{
    int i;
    for (i = 4; i >= 0; i--)
        mergesort_ordena_l(lista1, 0, dir, i);
}

void mergesort_merge_c(item_list_confronto *lista2, int esq, int meio, int dir, int h)
{
    int i, j, k;
    int aTam = meio - esq + 1;
    int bTam = dir - meio;

    item_list_confronto *a = (item_list_confronto *)malloc(sizeof(item_list_confronto) * aTam);
    item_list_confronto *b = (item_list_confronto *)malloc(sizeof(item_list_confronto) * bTam);

    for (i = 0; i < aTam; i++)
        item_confr_cpy(lista2, a, i + esq, i);

    for (i = 0; i < bTam; i++)
        item_confr_cpy(lista2, b, (i + meio + 1), i);

    for (i = 0, j = 0, k = esq; k <= dir; k++)
    {
        if (i == aTam)
            item_confr_cpy(b, lista2, j++, k);

        else if (j == bTam)
            item_confr_cpy(a, lista2, i++, k);

        else

            switch (h)
            {
            case 0:
                if (a[i].confrontos >= b[j].confrontos)
                    item_confr_cpy(a, lista2, i++, k);
                else
                    item_confr_cpy(b, lista2, j++, k);
                break;

            case 1:
                if (strcmp(a[i].nome_a, b[j].nome_a) < 0)
                    item_confr_cpy(a, lista2, i++, k);
                else
                    item_confr_cpy(b, lista2, j++, k);
                break;

            case 2:
                if (strcmp(a[i].nome_b, b[j].nome_b) > 0)
                    item_confr_cpy(a, lista2, i++, k);
                else
                    item_confr_cpy(b, lista2, j++, k);
                break;

            default:
                return;
            }
    }
    free(a);
    free(b);
}

void mergesort_ordena_c(item_list_confronto *lista2, int esq, int dir, int h)
{
    if (esq == dir)
        return;
    int meio = (esq + dir) / 2;
    mergesort_ordena_c(lista2, esq, meio, h);
    mergesort_ordena_c(lista2, meio + 1, dir, h);
    mergesort_merge_c(lista2, esq, meio, dir, h);
}

void mergesort_ordena_confronto(item_list_confronto *lista2, int esq, int dir)
{
    int i;
    for (i = 2; i >= 0; i--)
        mergesort_ordena_c(lista2, 0, dir, i);
}

void exporta_lista(FILE *saida, item_list_player *lista1, item_list_confronto *lista2, int tamanho_lista1, int tamanho_lista2)
{
    int i;
    fprintf(saida, "Ranking,P,J,V,E,D,GM,GS,SG,AP\n");
    for (i = 0; i < tamanho_lista1; i++)
    {
        fprintf(saida, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%.2f \n", lista1[i].nome, lista1[i].pontos, lista1[i].jogos, lista1[i].vitorias, lista1[i].empates, lista1[i].derrotas, lista1[i].gols, lista1[i].gols_sofridos, lista1[i].saldo, lista1[i].aproveitamento);
    }

    fprintf(saida, "\nConfrontos\n");
    for (i = 0; i < tamanho_lista2; i++)
    {
        fprintf(saida, "%s,%s,%d\n", lista2[i].nome_a, lista2[i].nome_b, lista2[i].confrontos);
    }
}

void inOrder_aproveitamento(node *leaf)
{
    if (leaf != NULL)
    {
        float j, k;
        inOrder_aproveitamento(leaf->left);

        j = leaf->info.pontos;
        j = j * 100;

        k = leaf->info.jogos;
        k = k * 3;

        if (k != 0)
            leaf->info.aproveitamento = j / k;

        inOrder_aproveitamento(leaf->right);
    }
}

void inOrder_treeTolist(node *leaf, item_list_player *lista1, int *i)
{
    if (leaf != NULL)
    {
        inOrder_treeTolist(leaf->left, lista1, i);
        strcpy(lista1[*i].nome, leaf->info.nome);
        lista1[*i].pontos = leaf->info.pontos;
        lista1[*i].saldo = leaf->info.saldo;
        lista1[*i].gols = leaf->info.gols;
        lista1[*i].gols_sofridos = leaf->info.gols_sofridos;
        lista1[*i].jogos = leaf->info.jogos;
        lista1[*i].vitorias = leaf->info.vitorias;
        lista1[*i].empates = leaf->info.empates;
        lista1[*i].derrotas = leaf->info.derrotas;
        lista1[*i].aproveitamento = leaf->info.aproveitamento;
        (*i)++;
        inOrder_treeTolist(leaf->right, lista1, i);
    }
}

void inOrder_treeTolist_confronto(nodec *leaf, item_list_confronto *lista2, int *i)
{
    if (leaf != NULL)
    {
        inOrder_treeTolist_confronto(leaf->left, lista2, i);
        lista2[*i].confrontos = leaf->info.confrontos;
        strcpy(lista2[*i].nome_a, leaf->info.nome_a);
        strcpy(lista2[*i].nome_b, leaf->info.nome_b);
        (*i)++;
        inOrder_treeTolist_confronto(leaf->right, lista2, i);
    }
}

void insert_tree(item_list_player h, node **leaf)
{
    if (*leaf == NULL)
    {
        *leaf = (node *)malloc(sizeof(node));

        (*leaf)->info.pontos = h.pontos;
        strcpy((*leaf)->info.nome, h.nome);
        (*leaf)->info.saldo = h.saldo;
        (*leaf)->info.gols = h.gols;
        (*leaf)->info.gols_sofridos = h.gols_sofridos;
        (*leaf)->info.jogos = h.jogos;
        (*leaf)->info.vitorias = h.vitorias;
        (*leaf)->info.empates = h.empates;
        (*leaf)->info.derrotas = h.derrotas;
        (*leaf)->info.aproveitamento = h.aproveitamento;

        (*leaf)->left = 0;
        (*leaf)->right = 0;
    }

    else if (strcmp(h.nome, (*leaf)->info.nome) < 0)
    {
        insert_tree(h, &(*leaf)->left);
    }
    else if (strcmp(h.nome, (*leaf)->info.nome) > 0)
    {
        insert_tree(h, &(*leaf)->right);
    }
}

void insert_tree_confronto(char *key_a, char *key_b, nodec **leaf)
{
    if (*leaf == NULL)
    {

        *leaf = (nodec *)malloc(sizeof(nodec));

        strcpy((*leaf)->info.nome_a, key_a);
        strcpy((*leaf)->info.nome_b, key_b);
        (*leaf)->info.confrontos = 1;

        (*leaf)->left = 0;
        (*leaf)->right = 0;
    }

    else
    {
        char aux1[200];
        strcpy(aux1, key_a);
        strcat(aux1, key_b);

        char aux2[200];
        strcpy(aux2, (*leaf)->info.nome_a);
        strcat(aux2, (*leaf)->info.nome_b);

        if (strcmp(aux1, aux2) < 0)
        {
            insert_tree_confronto(key_a, key_b, &(*leaf)->left);
        }
        else if (strcmp(aux1, aux2) > 0)
        {
            insert_tree_confronto(key_a, key_b, &(*leaf)->right);
        }
    }
}

node *search_tree(char *key, node *leaf)
{
    if (leaf != NULL)
    {
        if ((strcmp(key, leaf->info.nome)) == 0)
        {
            return leaf;
        }
        else if ((strcmp(key, leaf->info.nome)) < 0)
        {
            return search_tree(key, leaf->left);
        }
        else if ((strcmp(key, leaf->info.nome)) > 0)
        {
            return search_tree(key, leaf->right);
        }
    }
    else
        return NULL;
}

nodec *search_tree_confronto(char *key_a, char *key_b, nodec *leaf)
{
    if (leaf != NULL)
    {
        char aux1[200];
        strcpy(aux1, key_a);
        strcat(aux1, key_b);

        char aux2[200];
        strcpy(aux2, leaf->info.nome_a);
        strcat(aux2, leaf->info.nome_b);

        if ((strcmp(aux1, aux2)) == 0)
        {
            return leaf;
        }
        else if ((strcmp(aux1, aux2)) < 0)
        {
            return search_tree_confronto(key_a, key_b, leaf->left);
        }
        else if ((strcmp(aux1, aux2)) > 0)
        {
            return search_tree_confronto(key_a, key_b, leaf->right);
        }
    }
    else
        return NULL;
}

void change_tree(item_list_player key, node *leaf)
{

    if (leaf == NULL)
        printf("Esta vazio a folha");

    else
    {
        leaf->info.pontos += key.pontos;
        leaf->info.saldo += key.saldo;
        leaf->info.gols += key.gols;
        leaf->info.gols_sofridos += key.gols_sofridos;
        leaf->info.jogos += key.jogos;
        leaf->info.vitorias += key.vitorias;
        leaf->info.empates += key.empates;
        leaf->info.derrotas += key.derrotas;
        leaf->info.aproveitamento += key.aproveitamento;
    }
}

int lista(int c, int d, FILE *arquivo, item_list_player *lista1)
{
    int pontoA, pontoB, aux4, i = 0, h, contador = 0;
    int A, B;
    float data;
    char aux1[100];
    char aux2[100];
    char aux3[200]; // auxiliar lixo;
    fscanf(arquivo, "%s", &aux3);

    while ((fscanf(arquivo, "%f,%[^,],%[^,],%d,%d", &data, &aux1, &aux2, &pontoA, &pontoB)) > 0)
    {
        fgets(&aux3, ",%s", arquivo);
        aux4 = data / 10000;
        A = B = 0;

        if (strncmp(aux1, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux1, "St. Vincent and the Grenadine");
        if (strncmp(aux2, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux2, "St. Vincent and the Grenadine");

        if ((aux4 >= c) && (aux4 <= d) && ((strncmp(",FIFA World Cup", aux3, 14)) == 0))
        {
            if (pontoA > pontoB)
                A = 3;
            if (pontoB > pontoA)
                B = 3;
            if (pontoA == pontoB)
                A = B = 1;

            h = pesquisa_lista(lista1, aux1, contador);
            if (h == -1)
            {
                contador++;
                strcpy(lista1[i].nome, aux1);
                lista1[i].pontos = lista1[i].pontos + A;
                lista1[i].saldo = lista1[i].saldo + (pontoA - pontoB);
                lista1[i].gols = lista1[i].gols + pontoA;
                if (A == 3)
                    lista1[i].vitorias++;
                if (A == 1)
                    lista1[i].empates++;
                if (B == 3)
                    lista1[i].derrotas++;
                lista1[i].jogos++;
                lista1[i].gols_sofridos += pontoB;
                i++;
            }

            else
            {

                lista1[h].pontos = lista1[h].pontos + A;
                lista1[h].saldo = lista1[h].saldo + (pontoA - pontoB);
                lista1[h].gols = lista1[h].gols + pontoA;
                if (A == 3)
                    lista1[h].vitorias++;
                if (A == 1)
                    lista1[h].empates++;
                if (B == 3)
                    lista1[h].derrotas++;
                lista1[h].jogos++;
                lista1[h].gols_sofridos += pontoB;
            }

            h = pesquisa_lista(lista1, aux2, contador);
            if (h == -1)
            {
                contador++;
                strcpy(lista1[i].nome, aux2);
                lista1[i].pontos = lista1[i].pontos + B;
                lista1[i].saldo = lista1[i].saldo + (pontoB - pontoA);
                lista1[i].gols = lista1[i].gols + pontoB;
                if (B == 3)
                    lista1[i].vitorias++;
                if (B == 1)
                    lista1[i].empates++;
                if (A == 3)
                    lista1[i].derrotas++;
                lista1[i].jogos++;
                lista1[i].gols_sofridos += pontoA;
                i++;
            }

            else
            {

                lista1[h].pontos = lista1[h].pontos + B;
                lista1[h].saldo = lista1[h].saldo + (pontoB - pontoA);
                lista1[h].gols = lista1[h].gols + pontoB;
                if (B == 3)
                    lista1[h].vitorias++;
                if (B == 1)
                    lista1[h].empates++;
                if (A == 3)
                    lista1[h].derrotas++;
                lista1[h].jogos++;
                lista1[h].gols_sofridos += pontoA;
            }
        }
    }

    aproveitamento(lista1, contador);
    mergesort_ordena_lista(lista1, 0, contador - 1);
    return contador;
}

int lista_confronto(int c, int d, FILE *arquivo, item_list_confronto *lista2)
{
    int pontoA, pontoB, aux4, i = 0, h, contador = 0;
    float data, j;
    char aux1[200];
    char aux2[30];
    char aux3[200]; // auxiliar lixo;
    fscanf(arquivo, "%s", &aux3);

    while ((fscanf(arquivo, "%f,%[^,],%[^,],%d,%d", &data, &aux1, &aux2, &pontoA, &pontoB)) > 0)
    {
        fgets(&aux3, ",%s", arquivo);
        aux4 = data / 10000;

        if (strncmp(aux1, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux1, "St. Vincent and the Grenadine");
        if (strncmp(aux2, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux2, "St. Vincent and the Grenadine");

        if ((aux4 >= c) && (aux4 <= d))
        {

            h = pesquisa_lista_confronto(lista2, aux1, aux2, contador);

            if (h == -1)
            {
                contador++;
                j = strcmp(aux1, aux2);

                if (j < 0)
                {
                    strcpy(lista2[i].nome_a, aux1);
                    strcpy(lista2[i].nome_b, aux2);
                }

                else
                {
                    strcpy(lista2[i].nome_a, aux2);
                    strcpy(lista2[i].nome_b, aux1);
                }

                lista2[i++].confrontos++;
            }

            else
            {
                lista2[h].confrontos++;
            }
        }
    }

    mergesort_ordena_confronto(lista2, 0, contador - 1);
    return contador;
}

int arvore(int c, int d, FILE *arquivo, node *root, item_list_player *lista1)
{
    int pontoA, pontoB, aux4, contador = 0;
    int *x = (int *)malloc(sizeof(int));
    int A, B;
    float data;
    char aux1[100];
    char aux2[100];
    char aux3[200]; // auxiliar lixo;
    fscanf(arquivo, "%s", &aux3);
    node *aux5;

    item_list_player aux6;
    aux6.aproveitamento = 0.0;
    aux6.derrotas = aux6.empates = aux6.gols = aux6.gols_sofridos = aux6.jogos = aux6.pontos = aux6.saldo = aux6.vitorias = 0;

    while ((fscanf(arquivo, "%f,%[^,],%[^,],%d,%d", &data, &aux1, &aux2, &pontoA, &pontoB)) > 0)
    {
        fgets(&aux3, ",%s", arquivo);
        aux4 = data / 10000;
        A = B = 0;

        if (strncmp(aux1, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux1, "St. Vincent and the Grenadine");
        if (strncmp(aux2, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux2, "St. Vincent and the Grenadine");

        if ((aux4 >= c) && (aux4 <= d) && ((strncmp(",FIFA World Cup", aux3, 14)) == 0))
        {
            if (pontoA > pontoB)
                A = 3;
            if (pontoB > pontoA)
                B = 3;
            if (pontoA == pontoB)
                A = B = 1;

            strcpy(aux6.nome, aux1);
            aux6.pontos = A;
            aux6.saldo = (pontoA - pontoB);
            aux6.gols = pontoA;
            if (A == 3)
                aux6.vitorias++;
            if (A == 1)
                aux6.empates++;
            if (B == 3)
                aux6.derrotas++;
            aux6.jogos++;
            aux6.gols_sofridos += pontoB;

            aux5 = search_tree(aux1, root);
            if (aux5 == NULL)
            {
                contador++;
                insert_tree(aux6, &root);
                aux6.aproveitamento = 0.0;
                aux6.derrotas = aux6.empates = aux6.gols = aux6.gols_sofridos = aux6.jogos = aux6.pontos = aux6.saldo = aux6.vitorias = 0;
            }
            else
            {
                change_tree(aux6, aux5);
                aux6.aproveitamento = 0.0;
                aux6.derrotas = aux6.empates = aux6.gols = aux6.gols_sofridos = aux6.jogos = aux6.pontos = aux6.saldo = aux6.vitorias = 0;
            }

            strcpy(aux6.nome, aux2);
            aux6.pontos = B;
            aux6.saldo = (pontoB - pontoA);
            aux6.gols = pontoB;
            if (B == 3)
                aux6.vitorias++;
            if (B == 1)
                aux6.empates++;
            if (A == 3)
                aux6.derrotas++;
            aux6.jogos++;
            aux6.gols_sofridos += pontoA;

            aux5 = search_tree(aux2, root);
            if (aux5 == NULL)
            {
                contador++;
                insert_tree(aux6, &root);
                aux6.aproveitamento = 0.0;
                aux6.derrotas = aux6.empates = aux6.gols = aux6.gols_sofridos = aux6.jogos = aux6.pontos = aux6.saldo = aux6.vitorias = 0;
            }
            else
            {
                change_tree(aux6, aux5);
                aux6.aproveitamento = 0.0;
                aux6.derrotas = aux6.empates = aux6.gols = aux6.gols_sofridos = aux6.jogos = aux6.pontos = aux6.saldo = aux6.vitorias = 0;
            }
        }
    }

    inOrder_aproveitamento(root);
    inOrder_treeTolist(root, lista1, x);
    mergesort_ordena_lista(lista1, 0, contador - 1);
    free(x);
    return contador;
}

int arvore_confronto(int c, int d, FILE *arquivo, nodec *rootc, item_list_confronto *lista2)
{
    int pontoA, pontoB, aux4, contador = 0, j;
    int *x = (int *)malloc(sizeof(int));
    float data;
    char aux1[100];
    char aux2[100];
    char aux3[200]; // auxiliar lixo;
    fscanf(arquivo, "%s", &aux3);
    nodec *aux5 = NULL;

    while ((fscanf(arquivo, "%f,%[^,],%[^,],%d,%d", &data, &aux1, &aux2, &pontoA, &pontoB)) > 0)
    {
        fgets(&aux3, ",%s", arquivo);
        aux4 = data / 10000;

        if (strncmp(aux1, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux1, "St. Vincent and the Grenadine");
        if (strncmp(aux2, "St. Vincent and the Grenadines", 18) == 0)
            strcpy(aux2, "St. Vincent and the Grenadine");

        if ((aux4 >= c) && (aux4 <= d))
        {
            j = strcmp(aux1, aux2);
            if (j > 0)
            {
                aux5 = search_tree_confronto(aux2, aux1, rootc);
            }

            else
            {
                aux5 = search_tree_confronto(aux1, aux2, rootc);
            }

            if (aux5 != NULL)
                aux5->info.confrontos++;

            if (aux5 == NULL)
            {
                if (j > 0)
                {
                    contador++;
                    insert_tree_confronto(aux2, aux1, &rootc);
                }
                if (j < 0)
                {
                    contador++;
                    insert_tree_confronto(aux1, aux2, &rootc);
                }
            }
        }
    }

    inOrder_treeTolist_confronto(rootc, lista2, x);
    mergesort_ordena_confronto(lista2, 0, contador);
    free(x);
    return contador;
}
