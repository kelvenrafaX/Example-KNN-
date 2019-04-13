#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
	struct result {
		float valor;
		char classe[3];
	};
	
	struct result resultado[12];
	
	int c1[3][2];
	int c2[3][2];
	int c3[3][2];
	int c4[3][2];
	
	float c1r[3][1];
	float c2r[3][1];
	float c3r[3][1];
	float c4r[3][1];
	
	int k;
	int vet[2] = {2,3};
	// float resultado[12];
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			c1[i][j] = rand() % 10;
			c2[i][j] = rand() % 10;
			c3[i][j] = rand() % 10;
			c4[i][j] = rand() % 10;
		}
	}
	
	printf(" === Vetores === \n");
	for(int i = 0; i < 3; i++){
		printf("\n C1 [%d] = {%d,%d} ", i,c1[i][0],c1[i][1]);
		printf("| C2 [%d] = {%d,%d} ", i,c2[i][0],c2[i][1]);
		printf("| C3 [%d] = {%d,%d} ", i,c3[i][0],c3[i][1]);
		printf("| C4 [%d] = {%d,%d} \n", i,c4[i][0],c4[i][1]);
	}
	
	printf("\n Vetor de Observacao: {%d,%d} \n", vet[0],vet[1]);
	
	printf("\n Defina o valor para K: \n");
	scanf("%d", &k);
	
	// Evitando erros
	c1r[0][0] = 0;
	c1r[1][0] = 0;
	c1r[2][0] = 0;
	
	c2r[0][0] = 0;
	c2r[1][0] = 0;
	c2r[2][0] = 0;
	
	c3r[0][0] = 0;
	c3r[1][0] = 0;
	c3r[2][0] = 0;
	
	c4r[0][0] = 0;
	c4r[1][0] = 0;
	c4r[2][0] = 0;
	
	// Calculando as diferenças e suas potências	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			c1r[i][0] += pow((c1[i][j] - vet[j]),2);
			c2r[i][0] += pow((c2[i][j] - vet[j]),2);
			c3r[i][0] += pow((c3[i][j] - vet[j]),2);
			c4r[i][0] += pow((c4[i][j] - vet[j]),2);
		}
	}
		
	// Armazenando as raizes
	for(int i = 0; i < 3; i++){
		c1r[i][0] = sqrt(c1r[i][0]);
		c2r[i][0] = sqrt(c2r[i][0]);
		c3r[i][0] = sqrt(c3r[i][0]);
		c4r[i][0] = sqrt(c4r[i][0]);
	}
	
	// Atribuindo os valoes em um único Vetor
	for(int i = 0; i < 3; i++){
		resultado[i].valor = c1r[i][0];
		strcpy(resultado[i].classe , "C1");
		
		resultado[i+3].valor =c2r[i][0]; 
		strcpy(resultado[i+3].classe , "C2");
		
		resultado[i+6].valor =c3r[i][0];
		strcpy(resultado[i+6].classe , "C3");
		
		resultado[i+9].valor =c4r[i][0]; 
		strcpy(resultado[i+9].classe , "C4");
	}
	
	// Ordenando o vetor dos resultados
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			if(resultado[i].valor < resultado[j].valor){
				float aux = resultado[i].valor;
				resultado[i].valor = resultado[j].valor;
				resultado[j].valor = aux;
				
				char auxC[3];
				strcpy(auxC, resultado[i].classe);
				strcpy(resultado[i].classe , resultado[j].classe);
				strcpy(resultado[j].classe , auxC);
			}
		}
	}
	
	printf("\n === Distancias === \n");
	
	// Distâncias Euclidianas das Classes
	for(int i = 0; i < 3; i++){
		printf("\n C1 - Vetor %d = %0.2f     ", i+1,c1r[i][0]);
		printf("| C2 - Vetor %d = %0.2f     ", i+1,c2r[i][0]);
		printf("| C3 - Vetor %d = %0.2f     ", i+1,c3r[i][0]);
		printf("| C4 - Vetor %d = %0.2f     \n", i+1,c4r[i][0]);
	}
	
	printf("\n");
	
	int freqC1 = 0;
	int freqC2 = 0;
	int freqC3 = 0;
	int freqC4 = 0;
	
	printf("\n === As %d primeiras distancias === \n", k);
	
	for(int i = 0; i < k; i++){
		printf("Classe %s => %0.2f | ", resultado[i].classe, resultado[i].valor);
		
		if( strcmp(resultado[i].classe, "C1") == 0 ){
			freqC1 ++;
		} else if(strcmp(resultado[i].classe, "C2") == 0){
			freqC2 ++;
		} else if(strcmp(resultado[i].classe, "C3") == 0){
			freqC3 ++;
		} else if(strcmp(resultado[i].classe, "C4") == 0){
			freqC4 ++;
		}
	}
	
	printf("\n \n === Frequencias === \n \n ");
	printf("\n C1 === %d \n ",freqC1);
	printf("\n C2 === %d \n ",freqC2);
	printf("\n C3 === %d \n ",freqC3);
	printf("\n C4 === %d \n ",freqC4);

	return 0;
}
