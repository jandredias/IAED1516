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
					printf("There was an error: Invalid capacity\n");
					exit(1);
				}
			}
			break;
	        case 'I':
			altera_capacidade_maxima();
			break;
		case 'F':
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
			break;
		default:
			puts("Command not found");*/
		}
	}
	while (command != 'X');
	return 0;
}

/*****************************************************************************
*
*  AUXILIARY FUNCTIONS
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
	scanf("%s", airport[contador_aeroportos].id);
	scanf("%u", &airport[contador_aeroportos].capacity);
	if(strlen2(airport[contador_aeroportos].id) != 3)
		return 1; 
  	else if(airport[contador_aeroportos].capacity <= 0 ||
		airport[contador_aeroportos].capacity > UINT_MAX)
		return 2;

	contador_aeroportos++;
		return 0;
}
int altera_capacidade_maxima() {
	char i[3];
	int d = 0, k = 0, nova
	for(k; k < 3; k++){
		i[k] = getchar();
	if((d = getchar()) != '\0' || d != '\t' || d != '\n')
		/*criar o erro*/
	
	

 
