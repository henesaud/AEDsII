// By Hene S. S.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 60000

typedef struct
{
    char nome[30];
    int pontos, saldo, gols, jogos, vitorias, empates, derrotas, gols_sofridos;
    float aproveitamento;
    int c;

} item_list_player;

typedef struct
{
    char nome_a[30];
    char nome_b[30];
    char nome_c[30];
    int confrontos;
    int c;

} item_list_confronto;

typedef struct
{
    item_list_player info;
    struct node *left;
    struct node *right;

} node;

typedef struct
{
    item_list_confronto info;
    struct node *left;
    struct node *right;

} nodec;

float getTime();
int lista(int c, int d, FILE *arquivo, item_list_player *lista1);
int lista_confronto(int c, int d, FILE *arquivo, item_list_confronto *lista2);
void aproveitamento(item_list_player *lista1, int tamanho);
void item_list_cpy(item_list_player *src, item_list_player *dest, int a, int b);
void mergesort_merge_l(item_list_player *lista1, int esq, int meio, int dir, int h);
void mergesort_ordena_l(item_list_player *lista1, int esq, int dir, int h);
void mergesort_ordena_lista(item_list_player *lista1, int esq, int dir);
void mergesort_ordena_c(item_list_confronto *lista2, int esq, int dir, int h);
void mergesort_ordena_confronto(item_list_confronto *lista2, int esq, int dir);
void insert_tree(item_list_player h, node **leaf);
node *search_tree(char *key, node *leaf);
int arvore(int c, int d, FILE *arquivo, node *root, item_list_player *lista1);
int arvore_confronto(int c, int d, FILE *arquivo, nodec *rootc, item_list_confronto *lista2);
void change_tree(item_list_player key, node *leaf);
void inOrder_aproveitamento(node *leaf);
void inOrder_treeTolist(node *leaf, item_list_player *lista1, int *i);
void insert_tree_confronto(char *key_a, char *key_b, nodec **leaf);
void inOrder_treeTolist_confronto(nodec *leaf, item_list_confronto *lista2, int *i);
int pesquisa_lista(item_list_player *lista1, char *nome, int tamanho);
int pesquisa_lista_confronto(item_list_confronto *lista2, char *nome1, char *nome2, int tamanho);
void exporta_lista(FILE *saida, item_list_player *lista1, item_list_confronto *lista2, int tamanho_lista1, int tamanho_lista2);
int hash(int c, int d, FILE *arquivo, item_list_player *lista1, item_list_player *lista3);
int hash_confronto(int c, int d, FILE *arquivo, item_list_confronto *lista2, item_list_confronto *lista4);
void insere_hash_player(item_list_player *lista1, item_list_player key, int *contador);
void insere_hash_confronto(item_list_confronto *lista2, item_list_confronto key, char *nome, int *contador);
int gera_indice(char *nome);
