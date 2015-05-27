#include <string.h>
#include <stdio.h>
#define TAMANHO_LISTA 1000

struct node {
  char simbolo[80];
  int pos;
  int val;
  struct node *proximo;
};

struct node lista[TAMANHO_LISTA];
struct node raiz;
struct node bloco_nulo;

void inicializa_lista()
{
	int i;
	struct node *proximo;
	for(i=0;i<TAMANHO_LISTA;i++)
	{
		lista[i].pos=i;
		lista[i].val=-1;
		//memset(lista[i].simbolo, '\0', 80);
		proximo = &(lista[i+1]);
		lista[i].proximo=proximo;
	}
}

int busca(char *nome)
{
	int i;
	for (i=0;i<TAMANHO_LISTA;i++)
	{
		if (strcmp(lista[i].simbolo, nome)==0)
		{
			return i;
		}
	}
	return -1;
}

int insere(char* nome)
{
	struct node *condutor;
	
	if(busca(nome)>-1)
	{
		return busca(nome);
	}

	condutor = &(lista[0]);
	
	while (condutor->val != -1)
	{
		condutor = condutor->proximo;
	}
	strcpy(condutor->simbolo,nome);
	condutor->val=0;
	return condutor->pos;
}

void print_simbolos_lista()
{
	struct node *condutor;
	condutor = &(lista[0]);
	while(condutor->val != -1)
	{
		fprintf(stdout, "\nPos %d, Simbolo: %s", condutor->pos, condutor->simbolo);
		condutor = condutor->proximo;
	}
}


