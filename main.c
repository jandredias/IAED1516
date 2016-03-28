#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_AIRPORT 1000
#include <limits.h>

#define DEBUG 1
/****************************************************************************
 *
 * STRUCTS
 *
 ****************************************************************************/
typedef struct {
	char id[4];
	int capacity;
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
void imprime_vetores();
int  le_id(char i[]);
int  le_id2(char j[]);
int  verifica_id(char p[]);
int  ocupacao_aeroporto(char o[]);
int  voos_partida(char id[]);
int  voos_chegada(char id[]);
int  total_de_voos();
void erro_auxiliar(int test, char i[], char j[]);
void imprime_matriz();
void adiciona_aeroportos();
void altera_capacidade_maxima();
void adiciona_voo_ida_volta();
void adiciona_rota();
void remove_voo();
void remove_voo_ida_volta();
void adiciona_voo_aux(int test);
void numero_voos();
void aeroporto_mais_voos();
void aeroporto_mais_conectado();
void voo_mais_popular();
void encerra_aeroporto();
void reabre_aeroporto();
void emitir_listagem();
void ordem_entrada();
void ordem_alfabetica();
void distribuicao();
void sair_do_programa();
/****************************************************************************
 *
 *  MAIN
 *
 ****************************************************************************/
int main() {
	char command;
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
				adiciona_aeroportos();
				break;
			case 'I':
				altera_capacidade_maxima();
				break;
			case 'F':
				adiciona_voo_ida_volta();
				break;
			case 'G':
				adiciona_rota();
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
				encerra_aeroporto();
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
			default:;
				/*printf("Command not found:%c\n", command);*/
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
	getchar(); /*le o espaço depois do comando*/
	for(k = 0; k < 3; k++){
		i[k] = getchar();
		if(i[k] > 'Z' || i[k] < 'A'){
			return 1;
		}
	}
	i[3] = '\0';
	if((d = getchar()) != ' ') { /* le o espaço depois do id */
		return 2;
	}
	return 0;
}
int le_id2(char j[]){
	int k = 0;
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
	for(k = 0; k < contador_aeroportos; k++){
		if(strcmp(airport[k].id, p) == 0){
			return 0;
		}
	}
	return 3;
}
int ocupacao_aeroporto(char o[]){
	int k = 0, linhas = 0, colunas = 0, ocupacao = 0;
	for(k = 0; k < contador_aeroportos; k++){
		if(strcmp(airport[k].id, o) == 0){
			for(linhas = 0; linhas < contador_aeroportos; linhas++){
				for(colunas = 0; colunas < contador_aeroportos; colunas++){
					ocupacao += matriz[k][colunas];
				}
				ocupacao += matriz[linhas][k];
			}
			return ocupacao;
		}	
	}
	return -1;
}
int voos_partida(char id[]){
	int k = 0, colunas = 0, soma = 0;
	for(k = 0; k < contador_aeroportos; k++){
		if(strcmp(airport[k].id, id)){
			for(colunas = 0; colunas < contador_aeroportos; colunas++){
				soma += matriz[k][colunas];
			}
		}
	}
	return soma;
}
int voos_chegada(char id[]){
	int k = 0, linhas = 0, soma = 0;
	for(k = 0; k < contador_aeroportos; k++){
		if(strcmp(airport[k].id, id)){
			for(linhas = 0; linhas < contador_aeroportos; linhas++){
				soma += matriz[linhas][k];
			}
		}
	}
	return soma;
}
int total_de_voos(){
	int linhas = 0, colunas = 0, soma = 0;
	for(linhas = 0; linhas < contador_aeroportos; linhas++){
		for(colunas = 0; colunas < contador_aeroportos; colunas++){
			soma += matriz[linhas][colunas];
		}
	}
	return soma;
}
void erro_auxiliar(int test, char i[], char j[]){
	if(test == 3){
		printf("*Impossivel adicionar voo RT %s %s\n", i, j);
	}
	if(test==2){
		printf("*Impossivel remover voo %s %s\n", i, j);
	}
	if(test == 1){
		printf("*Impossivel remover voo %s %s\n", i, j);
	}
	if(test == 0){
		printf("*Impossivel remover voo RT %s %s\n", i, j);
	}	
}	
void imprime_matriz(){
	int linhas = 0, colunas = 0;
	for(linhas = 0;linhas < contador_aeroportos; linhas++){
		for(colunas = 0; colunas < contador_aeroportos; colunas++){
			printf("%d ", matriz[linhas][colunas]);
		}
		printf("\n");
	}
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
 *		 1 or 3  on failure invalid id
 *		 2 on failure if capacity is bigger than max
 *		   unsigned int or less then zero
 *
 */
void adiciona_aeroportos() {
	int k = 0;
	char i[4] = "\0";
	if(le_id(i) == 0){
		strcpy(airport[contador_aeroportos].id, i);
		scanf("%d", &airport[contador_aeroportos].capacity);
		for(k = 0; k < 3; k++){
			if(strlen(airport[contador_aeroportos].id) != 3 || airport[contador_aeroportos].id[k] > 'Z' || airport[contador_aeroportos].id[k] < 'A'){
				/*printf("There was an error: invalid id\n");*/
			}
		} 
		if(airport[contador_aeroportos].capacity <= 0){
			/*printf("There was an error: invalid capacity\n");*/
		}
		airport[contador_aeroportos].state = 1;
		contador_aeroportos++;
#if DEBUG
		imprime_vetores();
#endif
	}
	else {
		/*printf("There was an error: invalid id\n");*/				
	}
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
	int validade = 0, j = 0, capacidade_inserida = 0;
	char i[4] = "\0";
	validade = le_id(i);
	if(validade == 0){
		scanf("%d", &capacidade_inserida);
		for(j = 0; j < contador_aeroportos; j++){
			if((strcmp(i, airport[j].id) == 0)){
				if((airport[j].state == 1) && ((airport[j].capacity + capacidade_inserida) > 0)){
					airport[j].capacity += capacidade_inserida;
				}else{
					printf("*Capacidade %s inalterada\n",airport[j].id);
				}
			}
		}
#if DEBUG
		imprime_vetores();
#endif
	}else{
		/*printf("There was an error: Invalid id") */
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
	adiciona_voo_aux(0);
}
void adiciona_voo_aux(int test) {
	int validade_1_id = 0, validade_2_id = 0, existe_1_id = 0, existe_2_id = 0, ocupacao_1_id = 0, ocupacao_2_id, k = 0, v = 0;
	char i[4] = "\0", j[4] = "\0";
	validade_1_id = le_id(i);
	validade_2_id = le_id2(j);
	if(validade_1_id == 0 && validade_2_id == 0){
		existe_1_id = verifica_id(i);
		existe_2_id = verifica_id(j);
		if(existe_1_id == 0 && existe_2_id == 0){
			ocupacao_1_id = ocupacao_aeroporto(i);
			ocupacao_2_id = ocupacao_aeroporto(j);
			for(k = 0; k < contador_aeroportos; k++){
				for(v = 0; v < contador_aeroportos; v++){ 
					if((strcmp(airport[k].id, i) == 0) && (strcmp(airport[v].id, j) == 0) ){
						if(airport[k].state == 1 || airport[v].state == 1){
							if(test == 3){
								if((ocupacao_1_id + 2 <= airport[k].capacity) && (ocupacao_2_id + 2 <= airport[v].capacity)){
									matriz[k][v] += 1;
									matriz[v][k] += 1;
								}
								else{
									erro_auxiliar(test,i,j);
								}
								break;		
							}		
							if(test == 2){
								if((ocupacao_1_id + 1 <= airport[k].capacity) && (ocupacao_2_id + 1 <= airport[v].capacity)){
									matriz[k][v] += 1;
								}
								else{
									erro_auxiliar(test,i,j);
								}	
								break;
							}
							if(test == 1){
								if(matriz[k][v] > 0){ 
									matriz[k][v] -= 1;
								}
								else{
									erro_auxiliar(test,i,j);
								}	
								break;
							}	
							if(test == 0){
								if((matriz[k][v] > 0) && (matriz[v][k])){
									matriz[k][v] -= 1;
									matriz[v][k] -= 1;
								}
								else{
									erro_auxiliar(test,i,j);
								}
								break;
							}
							break; 
						}	
						else{
							erro_auxiliar(test,i,j);
						}	
					}/*este if nao falha, apenas está aqui para "salvar" os indices*/	
				}/*END OF FOR*/
			}/*END OF FOR*/
		}
	}else{
		erro_auxiliar(test,i,j);
	}/*
	    }else{
	    erro_auxiliar(test,i,j);
	    }	este else não faz parte das veriicaçoes obrigatorias*/
#if DEBUG
imprime_matriz();
#endif
}		

/*
 * Esta função indica o numero de voos entre dois aoreportos
 * On success:
 *   					printf("Voos entre cidades id_1:id_2:Noutgoing:Nincoming")
 * On failure:
 * 						printf("*Aeroporto <id> inexistente")
 *						or
 *						printf("There was an error: invalid id")
 */
void numero_voos(){
	int k = 0, v = 0;
	char i[4] = "\0", j[4] = "\0";
	if((le_id(i) == 0) && (le_id2(j) == 0)){/*verifica se a sequencia de letras introduzidas esta correta*/
		if((verifica_id(i) == 0) && (verifica_id(j) == 0)){/*verifica se estes ids sao conhecidos(se os aeroportos ja foram introduzidos)*/ 
			for(k = 0; k < contador_aeroportos; k++){
				if((strcmp(airport[k].id, i) == 0) && (airport[k].state == 1)){
					for(v = 0; v < contador_aeroportos; v++){
						if((strcmp(airport[v].id, j) == 0) && (airport[v].state == 1)){
							printf("Voos entre cidades %s:%s:%d:%d\n", i,j, matriz[k][v], matriz[v][k]);
						}
					}
				}
			}
		}
		else{
			if((verifica_id(i) == 0) && (verifica_id(j) == 3)){
				printf("*Aeroporto %s inexistente\n", j);
			}
			if((verifica_id(i) == 3) && (verifica_id(j) == 0)){
				printf("*Aeroporto %s inexistente\n", i);
			}
			else{
				printf("*Aeroporto %s inexistente\n", i);
				printf("*Aeroporto %s inexistente\n", j);
			}
		}
	}
	else{
		printf("There was an error: Invalid id\n");
	}
}
/* Esta função retorna o nome do aeroporto(id) com maior numero de voos que chegam e partem 
 *
 *
 *
 */
void aeroporto_mais_voos(){
	int k = 0, indice = 0, l = 0, soma_temporaria = 0, soma_permanente = 0, ida = 0, vinda = 0;
	for(k = 0, soma_temporaria = 0, ida = 0, vinda = 0; k < contador_aeroportos; k++, soma_temporaria = 0){/*este for percorre as linhas*/
		for(l = 0; l < contador_aeroportos; l++){/*este for percorre as colunas, e é aqui que se cria a variavel temporaria referente a cada um dos aeroportos*/
			soma_temporaria += matriz[k][l] + matriz[l][k];
		}
		if(soma_permanente < soma_temporaria){/*é este if que vai permitir saber qual o aeroportos tem mais voos*/
			ida = matriz[k][l];
			vinda = matriz[l][k];
			indice = k;	 
		}
	}		
	printf("Aeroporto com mais rotas %s:%d:%d\n", airport[indice].id, ida, vinda); 
}
/* Esta função verifica qual dos aeroportos possui mais ligações com os restantes.
 *		
 * 
 * 
 */
void aeroporto_mais_conectado(){
	int linhas = 0, colunas = 0, soma_temporaria = 0, soma_permanente = 0, indice = 0;
	for(linhas = 0, indice = 0, soma_temporaria = 0; linhas < contador_aeroportos; linhas++, soma_temporaria = 0){
		for(colunas = 0; colunas < contador_aeroportos; colunas++){
			if((matriz[linhas][colunas] > 0 && matriz[colunas][linhas] > 0) || (matriz[linhas][colunas] > 0 && matriz[linhas][colunas] < 0) || (matriz[linhas][colunas] < 0 && matriz[linhas][colunas] > 0)){ /*contabiliza para quantos lados diferentes ou de quantos lados diferentes sao efetuados os voos de/para cada um dos aeroportos*/
				soma_temporaria	+= 1; 
			} 
		}
		if(soma_temporaria > soma_permanente){
			soma_permanente = soma_temporaria;
			indice = linhas;
		}
	}		

	printf("Aeroporto com mais ligacoes %s:%d\n", airport[indice].id, soma_permanente); 
}
/* Esta função indica qual o voo executado mais vezes
 *	
 *
 *
 */
void voo_mais_popular(){
	int valor_temporario = 0, valor_permanente = 0, indice_temporario_linhas = 0, indice_permanente_linhas = 0, indice_temporario_colunas = 0, indice_permanente_colunas = 0,linhas = 0, colunas = 0;
	for(linhas = 0, indice_temporario_linhas = 0; linhas < contador_aeroportos; linhas++, indice_temporario_linhas++){
		for(colunas = 0, indice_temporario_colunas = 0; colunas < contador_aeroportos; colunas++, indice_temporario_colunas++){
			if((valor_temporario = matriz[linhas][colunas]) > valor_permanente){
				valor_permanente = valor_temporario;
				indice_permanente_linhas = indice_temporario_linhas;
				indice_permanente_colunas = indice_temporario_colunas;
			}
		}
	}
	printf("Voo mais popular %s:%s:%d\n", airport[indice_permanente_linhas].id, airport[indice_permanente_colunas].id, valor_permanente);			
}
/* Esta função vai verificar se o aeroporto selecionado existe e em caso afirmativo e caso o seu state seja 1 vai encerra-lo(state a 0)
 *
 *
 *
 */
void encerra_aeroporto(){
	int j = 0, colunas = 0;
	char i[4] = "\0";
	if(le_id(i) == 0){
		for(j = 0; j < contador_aeroportos; j++){
			if(strcmp(i, airport[j].id) == 0){
				if(airport[j].state == 1){
					airport[j].state = 0;
					for(colunas = 0; colunas < contador_aeroportos; colunas++){/*vai colocar a zero a linha e a coluna da matriz onde o aeroporto aparece*/
						matriz[j][colunas] = 0;	
						matriz[colunas][j] = 0;
					}
				}else{/*nada acontece. caso em que o aeroporto ja se encontra encerrado*/
				}	
			}else{
				printf("*Aeroporto %s inexistente\n", i);
			}					
			break;
		}
	}else{
		printf("*Aeroporto %s inexistente\n", i);
	}
}			
/* Esta função vai verificar se o aeroporto selecionado existe e em caso afirmativo e caso o seu state seja 0 vai reabri-lo(state a 1)
 *
 *
 *
 */
void reabre_aeroporto(){
	int j = 0;
	char i[4] = "\0";
	if(le_id(i) == 0){
		for(j = 0; j < contador_aeroportos; j++){
			if(strcmp(i, airport[j].id) == 0){
				if(airport[j].state == 0){
					airport[j].state = 1;
				}else{/*nada acontece. caso em que o aeroporto ja se encontra aberto*/
				}
			}else{
				printf("*Aeroporto %s inexistente\n", i);
			}					
			break;
		}
	}else{
		printf("*Aeroporto %s inexistente\n", i);
	}
}	
/* Esta função vai emitir uma listagem diferente conforme o subcomando inserido:
 *		0-imprime de acordo com a ordem de entrada dos aeroportos no sistema
 *		1-imprime de acordo com a ordem alfabetica dos aeroportos
 *		2-imprime o numero de aeroportos que possuem k voos. o k será sempre maior que zero e menor ou igual à capacidade do aeroporto com maior *		capacidade
 */
void emitir_listagem(){
	int sub_command; 
	getchar(); /*le o espaco*/
	sub_command = getchar();
	switch (sub_command) {
		case '0':
			ordem_entrada();
		case '1':
			ordem_alfabetica();
		case '2':
			distribuicao();
		default:
			printf("Sub command not found:%c\n", sub_command);
	}
}	
void ordem_entrada(){
	int k = 0;
	for(k = 0; k < contador_aeroportos; k++){
		printf("%s:%d:%d:%d\n", airport[k].id, airport[k].capacity, voos_partida(airport[k].id), voos_chegada(airport[k].id));			
	}	
}
void ordem_alfabetica(){
	int a = 0, b = 0, c = 0, indice = 0, valor_string = 0, vetor_ascii_string[contador_aeroportos + 1], valor = 0, contador = 0, k = 0, indice_no_vetor_principal = 0;							
	for(indice = 0; indice  < contador_aeroportos; indice++){/*neste for pega-se em todos os aeroportos que estão no vetor airport e são copiados o vetor_ascii_string sob forma de um numero*/
		a = airport[indice].id[0];
		b = airport[indice].id[1];
		c = airport[indice].id[2];
		valor_string = a + b + c;
		vetor_ascii_string[indice] = valor_string; 
	}
	valor = vetor_ascii_string[0];
	for(contador = contador_aeroportos; contador < 0; contador--){/*com este ciclo garanti-mos que todas os elementos do vetor_ascii_string são usados somente uma vez */
		for(k = 0; k < contador_aeroportos; k++){/*cada vez que este ciclo é percorrido é feito o print do id */
			if(vetor_ascii_string[k] <= valor){/*n existem dois ids iguais logo n existe o caso de os numeros sob os quais eles sao representados serem iguais. ora como os numero mais baixos vao sendo impressos e passam a assumir no vetor a forma de 909090 o menor ou IGUAL cobre o caso de existir o id ZZZ*/
				valor = vetor_ascii_string[k];
				indice_no_vetor_principal = k;
				vetor_ascii_string[k] = 909090; /*o elemento que aparecia primeiro em ordenação lexicografica passa a assumir a forma de ZZZ no vetor_ascii_string e consequentemente passa a ser ignorado*/ 
			}
		}
		printf("%s:%d:%d:%d\n", airport[indice_no_vetor_principal].id, airport[indice_no_vetor_principal].capacity, voos_partida(airport[indice_no_vetor_principal].id), voos_chegada(airport[indice_no_vetor_principal].id)); 	
	}
}
void distribuicao(){
	int k = 0, soma = 0, vetor_somas[contador_aeroportos], p = 0, soma_aeroportos = 0, v = 0, aeroportos_voos = 0, l = 0;
	/* manda para o vetor_somas as somas*/
	for(k = 0, soma = 0; k < contador_aeroportos; k++){
		for(l = 0; l < contador_aeroportos; l++){
			soma += matriz[k][l] + matriz[l][k];
		}
		vetor_somas[p] = soma;
		p++;
	}

	/*o v representa os numeros de voos efetuatos entre dois aeroportos (começa em zero), termina quando tivermos contabilizado todos os aeroportos existentes, a variavel soma_aeroportos serve para sabermos quando atingimos o total de aeroportos, é entao neste altura que deixa de fazer sentido continuar a incrementar o v*/
	for(soma_aeroportos = 0, v = 0; soma_aeroportos == contador_aeroportos; v++){
		for(p = 0; p < contador_aeroportos; p++){
			if(vetor_somas[p] == v){
				aeroportos_voos += 1;/*aeroportos com o mesmo numero de voos*/	
			}
		}
		printf("%d:%d\n", v, aeroportos_voos);
		aeroportos_voos = 0;	

	}
}
/*  Esta função termina o programa e imprime uma mensagem com o total de voos e com o numero de aeroportos
 *
 *
 *
 */
void sair_do_programa(){
	printf("%d:%d\n", total_de_voos(), contador_aeroportos);
}
