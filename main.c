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
int strlen2(char[]);
int adiciona_aeroportos();
void altera_capacidade_maxima();
void adiciona_voo_ida_volta(); 
void adiciona_rota();
void remove_voo();
void remove_voo_ida_volta();
void numero_voos();
void aeroporto_mais_voos();
int aeroporto_mais_conectado();
int voo_mais_popular();
int encerra_aeroporto();
int reabre_aeroporto();
int emitir_listagem();
int sair_do_programa();
int le_id(char[]);
int leid2(char[]);
int adiciona_rota(); 
int imprime_valores();
void adiciona_voo_aux(int); 

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
																				if (result == 1 || result == 3) {
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
												case 'F':
																adiciona_voo_ida_volta()
																				break;
												case 'G':
															  adciona_rota();
																break;
												case 'R':
																remove_voo();
																break;
												case 'S':
																remove_voo_ida_volta();
																break;
												case 'N':
																numero_voos();
																break;
												case 'P':
																aeroporto_mais_voos();
																break;
												case 'Q':
																aeroporto_mais_conectado();
																break;
												case 'V':
																voo_mais_popular();
																break;
												case 'C':
																Encerra_aeroporto();
																break;
												case 'O':
																reabre_aeroporto();
																break;
												case 'L':
																emitir_listagem();
																break;
												case 'X':
																sair_do_programa();
																break;
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
int le_id(char i[]){
				char d = '\0';
				int k = 0;
#if DEBUG
				printf("caracter espaco: %c\n",getchar()); /* le o espaco */
#endif
				for(; k < 3; k++){
								i[k] = getchar();
								if(i[k] > 'Z' || i[k] < 'A'){
												return 1;
								}
				}
				i[3] = '\0';
				if((d = getchar()) != ' ' || strlen(i) != 3) { /* le o espaço */
								return 2;
				}
				return 0;
}
int le_id2(char j[]){
				int k = 0;
				char j[4] = "\0";
				for(; k < 3; k++){
								j[k] = getchar();
								if(j[k] > 'Z' || j[k] < 'A'){
												return 1;
								}
				}
				if(strlen(j) != 3){
								return 1;
				}
				return 0;
}
int verifica_id(char p[]){
				int k = 0;
				if(validade == 0){
								for(k = 0; k < MAX_AIRPORT; k++){
												if(airport[k].id = p){
																return 0;
												}
												else {
																return 3;}
								}
				}}
int ocupacao_aeroporto(char o[]){
				for(k = 0; k < MAX_AIRPORT; k++){
								if(airport[k].id = p){
												for(linhas = 0; linhas < MAX_AIRPORT; linhas++){
																for(colunas = 0, colunas < MAX_AIRPORT; colunas++){
																				ocupacao += matriz[k][colunas];
																}
																ocupacao += matriz[linhas][k];}
												ocupacao -= matriz[k][k];
												return ocupacao;}
								else{
												return -1
								}
				}}

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
 *		 1 or 3  on failure invalid id
 *		 2 on failure if capacity is bigger than max
 *		   unsigned int or less then zero
 *
 */
int adiciona_aeroportos() {
				int k = 0, validade = 0;
				char i[4] = "\0";
				validade = le_id(i)
								if(validade == 0){
												strcpy(airport[contador_aeroportos].id, i);
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
								else {
												return 3;}
}
/*
 * Esta função altera a capacidade maxima de um aeroporto
 *
 * On success: altera a capacidade do aeroporto
 * On failure print: 
 *   		   "Capacidade de <ID> inalterada"
 *
 */
void altera_capacidade_maxima() { 
				int validade = 0;
				char i[4] = "\0";
				validade = le_id(i);
				if(validade == 1){
								printf("*Capacidade de %s inalterada\n", airport[j].id);
				}
				if(validade == 2){
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
																				break;
																}	
																else{
																				printf("*Capacidade de %s inalterada\n", airport[j].id);
																}}
												else{
																printf("*Capacidade de %s inalterada\n", airport[j].id);
												}
								}
								else {
												printf("*Capacidade de %s inalterada\n", airport[j].id);
								}
				}
}

/* Estas funções adicionam o voo de ida e volta (no caso da primeira), adicionam de ida (no caso da segunda), removem o voo de ida (no caso da terceira), removem de ida e volta (no caso da quarta)  
 * 			vetor i --> primeiro id
 *      vetor j --> segundo id
 * 		on success: modified matriz[][]
 * 		on failure: "*Impossivel adicionar voo RT <ID1> <ID2>"	
 */		
void adiciona_voo_ida_volta(){
				adiciona_voo_aux(3);
}
void adiciona_rota(){
				adiciona_voo_aux(2);
}
void remove_voo(){
				adiciona_voo_aux(1);
}
void remove_voo_ida_volta(){
				adiciona_voo_aux(0)
}
adiciona_voo_aux(int test) {
	int validade_1_id = 0, validade_2_id = 0, existe_1_id = 0, existe_2_id = 0, ocupacao_1_id = 0, ocupacao_2_id, k = 0;
	char i[4] = "\0", j[4] = "\0";
	validade_1_id = le_id(i);
	validade_2_id = le_id2(j);
	if(validade_1_id == 0 && validade_2_id == 0){
		existe_1_id = verifica_id(i);
		existe_2_id = verifica_id(j);
		if(existe_1_id == 0 && existe_2_id == 0){
			ocupacao_1_id = ocupacao_aeroporto(i);
			ocupacao_2_id = ocupacao_aeroporto(j);
			if(ocupacao_1_id != -1 && ocupacao_2_id != -1){
				for(k = 0; k < MAX_AIRPORT; k++){ 
					if(strcmp(airport[k].id, i) == 0 && 
							airport[k].state == 1 &&
							ocupacao_1_id + 2 <= airport[k].capacity){
						for(v = 0; v < MAX_AIRPORT; v++);{
							if(strcmp(airport[v].id, j) == 0 && 
									airport[v].state == 1 &&
									ocupacao_2_id + 2 <= airport[v].capacity){
											if(test == 3 || test == 2){ matriz[k][v] += 1;}
											if(test == 3){ matriz[v][k] += 1;}
											if(test == 0 || test == 1){ matriz[k][v] -= 1;}
											if(test == 0){ matriz[v][k] -= 1;}
							}else{
								printf("*Impossivel adicionar voo RT %s %s", i, j);
							}
						} /* END OF FOR */
					}else{
						printf("*Impossivel adicionar voo RT %s %s", i, j);
					}
				} /* END OF FOR */
			}else{
				printf("*Impossivel adicionar voo RT %s %s", i, j);
			} 
		}else{
			printf("*Impossivel adicionar voo RT %s %s", i, j);
		}
	}else{
		printf("*Impossivel adicionar voo RT %s %s", i, j);
	}
}
/*
 * Esta função indica o numero de voos entre dois aoreportos
 * On success:
 *   					printf("Voos entre cidades id_1:id_2:Noutgoing:Nincoming")
 * On failure:
 * 						printf("*Aeroporto <id> inexistente")
 */
void numero_voos(){
		int validade_1_id = 0, validade_2_id = 0, existe_1_id = 0, existe_2_id = 0, ocupacao_1_id = 0, ocupacao_2_id, k = 0;
	char i[4] = "\0", j[4] = "\0";
	validade_1_id = le_id(i);
	validade_2_id = le_id2(j);
	if(validade_1_id == 0){
		if(validade_2_id == 0){
			existe_1_id = verifica_id(i);
			existe_2_id = verifica_id(j);
			if(existe_1_id == 0){
				if(existe_2_id == 0){
					for(k = 0; k < MAX_AIRPORT; k++){ 
						if(strcmp(airport[k].id, i) == 0 && 
								airport[k].state == 1){
							for(v = 0; v < MAX_AIRPORT; v++);{
								if(strcmp(airport[v].id, j) == 0 && 
									airport[v].state == 1){
									printf("Voos entre cidades %s:%s:%d:%d", i,j, matriz[k][v], matriz[v][k]);		
								}else{
									printf("*Aeroporto %s inexistente", j);		
								}
							} /* END OF FOR */
						}else{
							printf("*Aeroporto %s inexistente", i);
						}
					} /* END OF FOR */
				}else{
				printf("*Aeroporto %s inexistente", j);
				} 
			}else{
				printf("*Aeroporto %s inexistente", i);
			}
		}else{
			printf("*Aeroporto %s inexistente", j);
		}
	}else{
		printf("*Aeroporto %s inexistente", i);
	}
}
/* Esta função retorna o nome do aeroporto(id) com maior numero de voos que chegam e partem 
 *
 *
 *
 */
void aeroporto_mais_voos(){
	int k = 0, j = 0, i_valor_maximo = 0, l = 0, vetor_de_totais[MAX_AIRPORT], soma_temporaria = 0, soma_permanente = 0, ida_temporaria = 0, ida_permanente = 0, vinda_temporaria = 0, vinda_permanente = 0;
	for(k = 0, soma_temporaria = 0; k < MAX_AIRPORT; k++, soma_temporaria = 0){
		for(l = 0; l < MAX_AIRPORT; l++){
			soma_temporaria += matriz[k][l] + matriz[l][k];
			ida_temporaria = matriz[k][l];
			vinda_permanente = matriz[l][k];
			if(soma_permanente < soma_temporaria){
				soma_permanente = soma_temporaria;
				ida_permanente = ida_temporaria;
				vinda_permanente = vinda_temporaria;	 
		}
		vetor_de_totais[k] = soma;
	}
	for(j = 0; j < MAX_AIRPORT; j++){
		 if(vetor_de_totais[j] > vetor_de_totais[i_valor_maximo]){
			i_valor_maximo = j;
		 }
	}		
	printf("Aeroporto com mais rotas %s:%d:%d", airport[i_valor_maximo].id, ida_permanente, vinda_permanente); 
}
void aeroporto_mais_conectado(){
	int k = 0, j = 0, i_valor_maximo = 0, l = 0, vetor_de_totais[MAX_AIRPORT], soma_temporaria = 0, soma_permanente = 0, ida_temporaria = 0, ida_permanente = 0, vinda_temporaria = 0, vinda_permanente = 0;
	for(linhas = 0, indice_temporario = 0; linhas < MAX_AIRPORT; linhas++, indice_temporario++){
		for(colunas = 0; colunas < MAX_AIRPORT; colunas++){
			if((matriz[linhas][colunas] > 0 && matriz[colunas][linhas] > 0) || (matriz[linhas][colunas] > 0 && matriz[linhas][colunas] < 0) || (matriz[linhas][colunas] < 0 && matriz[linhas][colunas] > 0)){
				soma_temporaria	+= 1; 
		  }
			if(soma_temporaria > soma_permanente){
				soma_permanente = soma_temporaria;
				indice_permanente = indice_temporario;
			
		vetor_de_totais[k] = soma;
	}
	for(j = 0; j < MAX_AIRPORT; j++){
		 if(vetor_de_totais[j] > vetor_de_totais[i_valor_maximo]){
			i_valor_maximo = j;
		 }
	}		
	printf("Aeroporto com mais rotas %s:%d:%d", airport[i_valor_maximo].id, ida_permanente, vinda_permanente); 
}

