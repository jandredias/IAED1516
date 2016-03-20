#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_AIRPORT 1000
#include <limits.h>

#define DEBUG 0
/****************************************************************************
 *
 * STRUCTS
 *
 ****************************************************************************/

typedef struct {
	char id[4];
	unsigned int capacity;
	int state;
} AIRPORT;

/****************************************************************************
 *
 *  GLOBAL VARIABLES
 *
 ****************************************************************************/
AIRPORT airport[MAX_AIRPORT];
int matriz[MAX_AIRPORT][MAX_AIRPORT];
int contador_aeroportos = 0;
/****************************************************************************
*
*  HEADER
* 
*****************************************************************************/
void init();
int strlen2(char c[]);
int adiciona_aeroportos();
int altera_capacidade_maxima();
int imprime_valores();

/****************************************************************************
*
*  MAIN
*
****************************************************************************/
int main() {
	char command;
	int result;
	init();
	do {
		#if DEBUG
		printf("Estou a ler o comando\n");
		#endif
		command = getchar();
	
		#if DEBUG
		printf("Já li comando: %c\n",command);
		#endif
		
		switch (command) {
		case 'A':
			result = adiciona_aeroportos();
			if (result != 0) {
				if (result == 1) {
					printf("There was an error: invalid Id.\n");
				}
				if (result == 2) {
					printf("There was an error: Invalid capacity.\n");
					exit(1);
				}
			}
			break;
	        case 'I':
			altera_capacidade_maxima();
			break;
	/*	case 'F':
			adiciona_airoportos();
			break;
		case 'G':
			adiciona_airoportos();
			break;
		case 'R':
			adiciona_airoportos();
			break;
		case 'S':
			adiciona_airoportos();
			break;
		case 'N':
			adiciona_airoportos();
			break;
		case 'P':
			adiciona_airoportos();
			break;
		case 'Q':
			adiciona_airoportos();
			break;
		case 'V':
			adiciona_airoportos();
			break;
		case 'C':
			adiciona_airoportos();
			break;
		case 'O':
			adiciona_airoportos();
			break;
		case 'L':
			adiciona_airoportos();
			break;
		case 'X':
			adiciona_airoportos();
			break;*/
		default:
			printf("Command not found:%c\n", command);
		}
		getchar(); /* le o  \n */
	}
	while (command != 'X');
	return 0;
}

/*****************************************************************************
*
*  AUXILIARY FUNCTIONS
*
*****************************************************************************/
void init(){
	
	int linhas, colunas;
	contador_aeroportos = 0; /*duvida*/
	for(linhas = 0; linhas < MAX_AIRPORT; linhas++){
		for(colunas = 0; colunas < MAX_AIRPORT; colunas++){
			matriz[linhas][colunas] = 0;
		}
	}
	for(colunas = 0; colunas < MAX_AIRPORT; colunas++){
		airport[colunas].id[0] = '\0';
		airport[colunas].capacity = 0;
		airport[colunas].state = 0;
	}
}
int strlen2(char c[]){
		  int index = 0;
		  while(c[index] != '\0'){
				  index++;
	}
		  return index; /*meti isto pq n sei ate que ponto podes usar a biblioteca da linha1 */
}
void imprime_vetores(){
	int i;
	printf("LISTA DE AEROPORTOS\n");	
	printf("===================\n");	
	for(i = 0; i < contador_aeroportos; i++){
		printf("Aeroporto %d:\n", i);
		printf("ID:       %s\n", airport[i].id);
		printf("CAPACITY: %d\n", airport[i].capacity);
		printf("STATE:    %d\n", airport[i].state);
		printf("\n");
	}
	printf("\n===================\n");
}

/***************************************************************************
*
*   FUNCTIONS
*
***************************************************************************/
/*
 * Esta funcao adiciona um aeroporto ao vetor de aeroportos
 * Incrementa tambem o contador global de aeroportos
 *
 * return: 0 on success
 *		 1 on failure invalid id
 *		 2 on failure if capacity is bigger than max
 *		   unsigned int or less then zero
 *
 */
int adiciona_aeroportos() {
	int k = 0;
	scanf("%s", airport[contador_aeroportos].id);
	scanf("%u", &airport[contador_aeroportos].capacity);
	for(k = 0; k < 3; k++){
		if(strlen2(airport[contador_aeroportos].id) != 3 || airport[contador_aeroportos].id[k] > 'Z' || airport[contador_aeroportos].id[k] < 'A'){
			return 1;
		}
	} 
  	if(airport[contador_aeroportos].capacity <= 0 ||
		airport[contador_aeroportos].capacity > UINT_MAX){
		return 2;
	}
	contador_aeroportos++;
	#if DEBUG
	imprime_vetores();
	#endif
		return 0;
}
/*
 * Esta função altera a capacidade maxima de um aeroporto
 *
 * On success: altera a capacidade do aeroporto
 * On failure return: 
 *   		1 or 2 invalid id
 * 		3 id not found
 * 		4 invalid capacity
 * 		5 airport closed
 *
 */
int altera_capacidade_maxima() { /*falta o caso do aerogaitas estar fechado*/
	char i[4], d = '\0';
	int k = 0, capacidade_inserida = 0, nova_capacidade = 0, j = 0;
	#if DEBUG
	printf("caracter espaco: %c\n",getchar()); /* le o espaco */
	#endif
	for(; k < 3; k++){
		i[k] = getchar();
		if(i[k] > 'Z' || i[k] < 'A'){
			#if DEBUG
			printf("caracter lido: %c", i[k]);
			#endif
			return 1;
			printf("*Capacidade de %s inalterada\n", airport[j].id);
			#if DEBUG
			imprime_vetores();
			#endif
		}
	} 
	i[3] = '\0';
	if((d = getchar()) != ' '){
		#if DEBUG
		printf("%c", d);
		#endif
		return 2;
		printf("*Capacidade de %s inalterada\n", airport[j].id);
	}
	scanf("%d", &capacidade_inserida);
	for(j = 0; j < contador_aeroportos; j++){
		if(strcmp(i, airport[j].id) == 0){
			if(airport[j].state == 1){
				nova_capacidade = airport[j].capacity + capacidade_inserida;
				if(nova_capacidade > 0){
					airport[j].capacity = nova_capacidade;
					#if DEBUG
					imprime_vetores();
					#endif
					return 0;
				}else{
					return 4;
                                	printf("*Capacidade de %s inalterada\n", airport[j].id);

				}}else
				  printf("*Capacidade de %s inalterada\n", airport[j].id);
				  return 5;
		}
	}
	return 3;
        printf("*Capacidade de %s inalterada\n", airport[j].id);

}		

	


