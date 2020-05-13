//Integrantes:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define limite 2147483647

int factorial_n_iterativo(int n);
int factorial_n_recursivo(int n);
int calcular_tamano(int n,int *tam_resultado);
void factorial_2 (int n,int tam_resultado,int resultado[(tam_resultado)]);

void main(){
	int n;
	printf("\nIngrese el valor de n: \n"); scanf("%i",&n);
	printf("\nEl factorial de %i es : %i\n", n,factorial_n_iterativo(n));
	printf("\nEl factorial de %i es : %i\n", n,factorial_n_recursivo(n));
	
	int tam_resultado = 0;
	
	calcular_tamano(n,&tam_resultado);
	
	int resultado[tam_resultado];
	printf("\nTam resultado vale = %i \n",tam_resultado);
	
	
	factorial_2 (n,tam_resultado,resultado);
	
}

int factorial_n_iterativo(int n){
	int factorial=n,aux;
	n--;
	while(n>=1){
		aux=factorial;
		factorial=factorial*n;
		if(aux>factorial){
			return 0;
		}
		n--;
	}
		return factorial;	
}

int factorial_n_recursivo(int n){
	if(n==1){
		return 1;	
	}
	else{
		return n*factorial_n_recursivo(n-1);
	}
}

int calcular_tamano(int n,int *tam_resultado){
	int	aux = (factorial_n_iterativo(n));
		
	while(aux>=1){
		aux = aux/10;
		(*tam_resultado)++;
	}
	return (*tam_resultado);
}

void factorial_2 (int n,int tam_resultado,int resultado[(tam_resultado)]){
	int aux = (factorial_n_iterativo(n)),tope=tam_resultado,i=0,j=0;
	
	while(tam_resultado != 0){
		int divisor = pow(10,tam_resultado-1);
		printf("\nEl divisor es = %i,Aux tiene el valor de = %i \n",divisor,aux);
		resultado[j] = aux/divisor;
		aux = aux-(resultado[j]*divisor);
		tam_resultado--;	
		j++;
	}
	
	printf("\n\n");
	while(i<tope){
		printf(" %i ",resultado[i]);
		i++;
	}
	printf("\n\n");
}
