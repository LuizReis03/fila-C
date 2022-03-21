#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
	
//CRIA ESTRUTURA DE UMA FILA
struct Fila{
	
	int primeiro;
	int ultimo;
	int nItens;
	int capacidade;
	float *dados;
	
};

//FUN플O PARA CRIA UMA FILA
void criaFila (struct Fila *f, int c){
	f -> primeiro = 0;
	f -> ultimo = -1;
	f -> nItens = 0;
	f -> capacidade = c;
	f -> nItens = 0;
	f -> dados = (float*) malloc (f->capacidade * sizeof(float));
}

//FUN플O PARA INSERIR NA FILA
void inserir(struct Fila *f, int valor){
	if(f->ulitmo == f->capacidade-1){
		f->ultimo = -1;
	}
	
	f -> ultimo ++;
	f -> primeiro = valor;
	f -> dados[f->ultimo] = valor; //FAZ UMA ALOCA플O DINAMICA FAZENDO COM QUE O ULTIMO PASSE A TER UM NOVO VALOR
	f -> nItens++; /*INCREMENTA MAIS UM ITEM*/
	
}

//FUN플O DE RETIRAR NA FILA
int retirar(struct Fila *f){
	int temporario = f-> dados[f->primeiro++]; //VALOR TEMPORARIO QUE INCREMENTA UM NOVO VALOR AO PRIMEIRO
	
	if(f-> primeiro == f-> capacidade){ //INDEPENDENTE DO TAMANHO DA CAPACIDADE PRIMEIRO SEMPRE VAI SER 0
		f-> primeiro = 0;
	}
	
	f-> nItens--; //TIRA UM ITEM DA LISTA	
	return temporario;
}

//VERIFICA SE A FILA EST� VAZIA
int estaVazia(struct Fila *f){ 
	//SE FOR VAZIA RETORNA 0
	return(f->nItens==0);
}

//VERIFICA SE A FILA EST� CHEIA
int estaCheia(struct Fila *f){ 
	//SE FOR CHEIA RETORNA CAPACIDADE
	return(f-> nItens == f->capacidade);
}

int listarFila(struct Fila *f){
	int cont = 0;
	int i= f->primeiro;
	for(cont, i; cont < f->nItens; cont++){
		cout << f->dados[i++];
		
		if (i == f->capacidade){
			i=0;
		}
	}
	cout << "\n\n";
}

int main() {
	struct Fila novaFila;
	int capacidade = 0;
	int opcao = 0;
	float valor = 0.0;
	
	cout << "Digite a capacidade da fila: ";
	cin >> capacidade;
	capacidade = capacidade +1;
	criaFila (&novaFila, capacidade);
	
	
	while (1){
		cout << "\n1)Inserir\n";
		cout << "2)Remover\n";
		cout << "3)Mostrar a fila\n";
		cout << "4)Sair\n";
		cout << "\nDigite a opcao desejada: ";
		cin >> opcao;
		
		switch(opcao){
			//empilha
			case 1: 
				if (estaCheia(&novaFila) == 1){
					cout << "\nA fila esta cheia!\n";
				}else{
					cout << "Digite o valor: ";
					cin >> valor;
					empilha(&novaFila, valor);
				}
				break;
			//desempilha
			case 2:
				if (verificaPilhaVazia(&novaFila) == 1){
					cout << "\nA pilha esta vazia!\n";
				}else{
					valor = desempilha(&novaFila);
					cout << "\nFoi desempilhado!\n";
				}
				break;
			//mostra o topo da lista
			case 3:
				if (verificaPilhaVazia(&novaFila) == 1){
					cout << "\nA fila esta vazia!\n";
				}else{
					valor = listarFila(&novaFila);
					cout << "\nListagem da fila: " << valor << "\n";
				}
				break;
			//sai do loop
			case 4:
				exit(0);
				break;
		}
		
	}
	
}
