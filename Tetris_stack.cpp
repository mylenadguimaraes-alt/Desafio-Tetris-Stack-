#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdbool.h> 

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

#define capacidade 5
#define capacidade_pilha 3

typedef struct  
{
	char nome;
	int id;
}Pecas; 

typedef struct
{
	Pecas p [capacidade];
	int inicio;
	int fim;
	int quantidade;
}filas_pecas;

typedef struct 
{
	Pecas p [capacidade_pilha];
	int topo;
	int quantidade;
}pilha_pecas;


/*
	Funções Simples
*/
void LimparBuffer();
void LimparTela();

/*
	Funções de fila
*/
void iniciar_fila(filas_pecas * fila);
int filaVazia(filas_pecas *fila);
int filaCheia(filas_pecas *fila);
void enqueue(filas_pecas *fila, Pecas peca, int mostrar) ;
void MostrarFila(filas_pecas * fila);
void dequeue(filas_pecas *fila, Pecas *p, int * inserir, int mostrar);

/*
	Funções para a pilha 
*/
void iniciar_pilha(pilha_pecas * pilha);
int pilhaVazia(pilha_pecas *pilha);
int pilhaCheia(pilha_pecas *pilha);


/*
	Gerar peças
*/
Pecas GerarPeca (Pecas p);


/*
	Menus
*/
void MenuPrincipal(int * opcao);


/* contador global para ids */
int proximoId = 0;



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
	
	//Verifica se pode inserir uma nova peça 
	//após jogar uma peça
	//0 para não e 1 para sim
	int inserir = 0;   
	
	filas_pecas fila;
	Pecas pecas;
	pilha_pecas pilha;
	
	iniciar_fila(&fila);
	iniciar_pilha(&pilha);
	
	
	int i;
	for (i = 0; i < capacidade; ++i) {
        Pecas p = GerarPeca(p);
        enqueue(&fila, p, 0); 
    }
	
	
	do
	{
		MostrarFila(&fila);
		MenuPrincipal(&opcao);


		switch(opcao)
		{
			case 1:
			{
				dequeue(&fila, &pecas, &inserir, 1);
				if (inserir)
				{
					Pecas p = GerarPeca(p);
        			enqueue(&fila, p, 0); 
				}
				LimparTela();
				break;
			}
			case 2:
			{
				Pecas p = GerarPeca(p);
        		enqueue(&fila, p, 1);
        		LimparTela();
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
int filaVazia(filas_pecas *fila) {
    return (fila->quantidade == 0);
}




//filaCheia()
//Para verificar se a fila esta cheia 
int filaCheia(filas_pecas *fila) 
{
    return (fila->quantidade == capacidade);
}



//GererPeca()
//Gera uma peca por vez
Pecas GerarPeca (Pecas p)
{
	const char tipos[] = {'I', 'O', 'T', 'L'};
	
	p.nome = tipos[rand() % (sizeof(tipos) / sizeof(tipos[0]))];
    p.id = proximoId++;
    return p;
}



//MenuPrincipal()
//Exibe o menu principal e pega a escolha desejada
void MenuPrincipal(int * opcao)
{
	printf("======================================================");
	printf("\n                    MENU PRINCIPAL                    \n");
	printf("======================================================");
	printf("\n1. Jogar\n");
	printf("2. Reservar\n");
	printf("3. Usar peca reserva\n");
	printf("0. Sair\n\n");
	
	printf("Escolha a opcao desejada: ");
	scanf("%d", opcao);
	LimparBuffer();
}



//enqueue()
//Insere a peça na fila
void enqueue(filas_pecas *fila, Pecas peca, int mostrar) 
{
	int resultado = filaCheia(fila); // verifica se está cheia
    
    if (resultado) // se for 1 (cheia)
    {
        printf("\nAviso: A fila esta cheia. Nao e possivel inserir uma nova peca.\n");
        printf("Digite ENTER para continuar..."); 
		getchar();
        return;
    }
    
    int pos = (fila->inicio + fila->quantidade) % capacidade;
    fila->p[pos] = peca;
    fila->quantidade++;
    
    if (mostrar){
    	printf("\nPeca inserida com sucesso!\n");
    	printf("Tipo: %c | ID: %d\n", fila->p[pos].nome, fila->p[pos].id);
    	printf("Digite ENTER para continuar...");
    	getchar();  
	}

}


//MostrarFila()
//Mostra a fila armazenada
void MostrarFila(filas_pecas * fila)
{
	int resultado = filaVazia(fila); // verifica se está vazia
	if (resultado)
	{
		printf("\n======================================================\n");
        printf("            Fila de Pecas Futuras (Vazia)            \n");
        printf("======================================================\n");
        printf("                Nenhuma peca disponivel               \n");
        printf("======================================================\n\n");
        return;	
	}
	printf("\n======================================================\n");
    printf("                     Fila de Pecas\n");
    printf("======================================================\n");
    
    // Percorre a fila circularmente e mostra cada peça
    int i;
	for (i = 0; i < fila->quantidade; i++)
    {
        int pos = (fila->inicio + i) % capacidade;
        printf("[%c %d] ", fila->p[pos].nome, fila->p[pos].id);
    }

    printf("\n======================================================\n\n");
}

void dequeue(filas_pecas *fila, Pecas *p, int * inserir, int mostrar)
{
	int resultado = filaVazia(fila); // verifica se está vazia
    
    if (resultado) // se for 1 (vazia)
    {
        printf("\nAviso: A fila esta vazia. Nao e possivel jogar uma peca.\n");
        printf("Digite ENTER para continuar..."); 
		getchar();
		*inserir = 0;
        return;
    }
    *p = fila->p[fila->inicio];            
    fila->inicio = (fila->inicio + 1) % capacidade;    
    fila->quantidade--;
    
    *inserir = 1;
    
    if(mostrar){
		printf("\nPeca jogada com sucesso!\n");
    	printf("Tipo: %c | ID: %d\n", p->nome, p->id);
    	printf("Digite ENTER para continuar...");
    	getchar();  
	}
}

//iniciar_pilha()
//Inicia a pilha 
void iniciar_pilha(pilha_pecas * pilha)
{
	pilha->topo = 0;
	pilha->quantidade = 0;
}



int pilhaVazia(pilha_pecas *pilha)
{
	return (pilha->quantidade == 0);
}


int pilhaCheia(pilha_pecas *pilha)
{
	return (pilha->quantidade == capacidade_pilha);
}






