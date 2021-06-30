#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include"title.h"
#include"scrClean.h"
//funcion que nos entrega el tamanio de la matriz, retorna el tamanio.
int matrixSize(){
	FILE *dataFile;
	char numero[3];
	dataFile = fopen("Entrada.in","r");
	fgets(numero,3,dataFile);
	int numeroInicial=atoi(numero);
	printf("el numero es: %d\n",numeroInicial);
	return numeroInicial;
}
	
//funcion que abre la entrada 1

/*
Estoy intentado capturar la entrada en 2 arrays distintos de tamanio de la matriz
una vez capturados los arrays, puedo empezar a crear la salida 1, para ello a partir del tamanio 
de la matriz, se puede ajustar las columnas y las filas*/
char openFileOne(char filas[], char columnas[],int numeroInicial){
	FILE *dataFile;
	const unsigned MAX_LENGHT=256;
	int index;
	char datos[MAX_LENGHT];
	dataFile = fopen("Entrada.in","r");

	int i=0;
	//en este ciclo, mostramos la entrada hasta la posicion 
	//maxima de las filas
	//Falta traspasar cada str a una posicion de un array
	// o de plano, empezar a crear una funcion que arme ya la matriz, y luego 
	// la exporte a un .out
	while(i<=numeroInicial){
		fgets(datos,MAX_LENGHT,dataFile);
		printf("%s",datos);
		i++;
	}
	printf("-----------------------------");
	//una vez terminadas las filas, se empiezan a imprimir los datos de 
	//las columnas
	while(fgets(datos,MAX_LENGHT,dataFile)){
		printf("%s",datos);
	}

	fclose(dataFile);
	printf("\n");
}

int main(){
	int opt;
	//invocación desde title.h
	printSpider();
	//al seleccionar la OPT1 se despliega la funcion que 
	//abre los archivos
	scanf("%d",&opt);
	while(opt<1 || opt>4){
		printf("INGRESE UNA OPCIÓN CORRECTA!: ");
		scanf("%d",&opt);
	}
	scrClean();
	if (opt==1){
		int tamanio=matrixSize();
		char filas[tamanio];
		char columnas[tamanio];
		openFileOne(filas,columnas,tamanio);
	}
	printf("TEST TERMINADO CON EXITO!\n");	

	return 0;
}