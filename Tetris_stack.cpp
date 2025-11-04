#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdbool.h> 

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

#define MaxNome 1
#define max 5

typedef struct  
{
	char nome [MaxNome];
	int id;
}Pecas; 

typedef struct
{
	Pecas p [max];
	int inicio;
	int fim;
	int quantidade;
}filas_pecas;


/*
	Funções Simples
*/
void LimparBuffer();
void LimparTela();

/*
	Para verificação de fila
*/
void iniciar_fila(filas_pecas * fila);
void filaVazia(filas_pecas * fila, int *resultado);
void filaCheia(filas_pecas * fila, int *resultado);

/*
	Menus
*/
void MenuPrincipal(int * opcao);



int main() {
    // ?? Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.

    // ?? Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // ?? Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha



	//Começo do código
	int opcao;
	
	do
	{
		MenuPrincipal(&opcao);
		switch(opcao)
		{
			case 1:
			{
				
				break;
			}
			case 2:
			{
				break;
			}
			case 0:
			{
				printf("\n\nVoce esta saindo do programa\n");
                printf("Digite ENTER para continuar..."); 
                getchar();
				break;
			}
			default:
			{
				printf("\n\nValor invalido! Voce sera mandado de volta ao menu principal\n");
                printf("Digite ENTER para continuar..."); 
                getchar();
                
                LimparTela();
				break;
			}
		}
	}while(opcao != 0);
	






	

    return 0;
}


//LimparBuffer()
//Limpa o buffer
void LimparBuffer()
{
	int c;
    while((c=getchar()) != '\n' && c != EOF); 
}

//LimparTela()
//Limpa a tela ao executar algo
void LimparTela()
{
	int i;
	for (i = 0; i < 50; i++)
	{
		printf("\n");
	}
}



//iniciar_fila()
//Inicia a fila
void iniciar_fila(filas_pecas * fila)
{
	fila->inicio = 0;
	fila->fim = 0;
	fila->quantidade = 0;
}



//filaVazia()
//Para verificar se a fila esta vazia 
void filaVazia(filas_pecas * fila, int *resultado)
{
	if (fila->quantidade == 0)
	{
		printf("Aviso: Fila Vazia!!\n");
		printf("Digite ENTER para continuar..."); 
        getchar();
        resultado = 0;
	}
}




//filaCheia()
//Para verificar se a fila esta cheia 
void filaCheia(filas_pecas * fila, int *resultado)
{
	if (fila->quantidade == max)
	{
		printf("Aviso: Fila Cheia!!\n");
		printf("Digite ENTER para continuar..."); 
        getchar();
        resultado = 0;
	}
}


//MenuPrincipal()
//Exibe o menu principal e pega a escolha desejada
void MenuPrincipal(int * opcao)
{
	printf("======================================================");
	printf("\n                    MENU PRINCIPAL                    \n");
	printf("======================================================");
	printf("\n1. Jogar Peca(dequeue)\n");
	printf("2. Inserir nova Peca(enqueue)\n");
	printf("0. Sair\n\n");
	
	printf("Escolha a opcao desejada: ");
	scanf("%d", opcao);
	LimparBuffer();
}




