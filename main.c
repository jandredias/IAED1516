#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_AIRPORT 1000
#include <limits.h>

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
int contador_aeroportos;


/****************************************************************************
*
*  MAIN
*
****************************************************************************/
int main() {
	char command;
	int result, a;
	init();
	do{
	command = getchar();
	switch (command){
	case 'A':
    result = adiciona_aeroportos();
    if(a != 0){
      if(a == 1)
        printf("There was an error: invalid Id.\n");
      if(a == 2)
        printf("There was an error: Invalid capacity\n");
      exit(1);
    }
    break;
	case 'I': adiciona_airoportos(); break;
	case 'F': adiciona_airoportos(); break;
	case 'G': adiciona_airoportos(); break;
	case 'R': adiciona_airoportos(); break;
	case 'R': adiciona_airoportos(); break;
	case 'S': adiciona_airoportos(); break;
	case 'N': adiciona_airoportos(); break;
	case 'P': adiciona_airoportos(); break;
	case 'Q': adiciona_airoportos(); break;
	case 'V': adiciona_airoportos(); break;
	case 'C': adiciona_airoportos(); break;
	case 'O': adiciona_airoportos(); break;
	case 'L': adiciona_airoportos(); break;
	case 'X': adiciona_airoportos(); break;
	default puts("Command not found");
  }while(command != 'X');
	
  return 0;

}
/*****************************************************************************
*
*  AUXILIARY FUNCTIONS
*****************************************************************************/
void init(){
	
	contador_aeroportos = 0;
	int linhas, colunas;

	for(linhas = 0; linhas < MAX_AIRPORT; linhas++){
		for(colunas = 0; colunas < MAX_AIRPORT; colunas++){
			colunas[linhas][colunas] = 0;
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
          while(c[index] != "\0"){
                  index++;
    }
          return index; /*meti isto pq n sei ate que ponto podes usar a biblioteca da linha1 */
]>}

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
 *         1 on failure invalid id
 *         2 on failure if capacity is bigger than max
 *           unsigned int or less then zero
 *
 */
int adiciona_airoportos {
	scanf("%s", airport[contador_aeroportos].id);
	scanf("%d", airport[contador_aeroportos].capacity);
	contador_aeroportos++ 
	if(strlen2(airport[contador_aeroportos].id) != 3)
		return 1; 
  else if(airport[contador_aeroportos].capacity <= 0 ||
          airport[contador_aeroportos].capacity > UNIT_MAX)
		return 2; 
	else
		return 0;
}


 
