#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"title.h"
#include"scrClean.h"

//funcion que nos entrega el tamanio de la matriz, retorna el tamanio.
int matrixSize(char nombreArchivo[]){
	FILE *dataFile;
	char numero[3];
	dataFile = fopen(nombreArchivo,"r");
	fgets(numero,3,dataFile);
	int numeroInicial=atoi(numero);
	printf("el numero es: %d\n",numeroInicial);
	return numeroInicial;
}

//funcion que captura la matriz del formato 2 de entrada, la trabaja sobre 
// un doble puntero para crear una matriz bidimensional, retorna la matriz	
int **matrizObt(int **matriz, int tamanio, char nombreArchivo[]){
	int num;
	char dato;
	char charNum[255];
	FILE *dataFile;
	dataFile = fopen(nombreArchivo,"r");

	matriz=(int **)calloc(tamanio,sizeof(int *));
	for (int i = 0; i < tamanio; ++i){
		matriz[i]=(int *)calloc(tamanio,sizeof(int));}

	int i=0;
	int j=0,k=0;
	while (feof(dataFile) == 0) {
 		fgets(charNum,100,dataFile);
 		if (i>0){
	 		j=0;
	 		for (int i = 0; i < tamanio*2; ++i){	
	 			dato=charNum[i];
	 			
	 			if (dato!=' '){
	 				num = (int) charNum[i]-48;
	 				if (num>=0){
	 					matriz[k][j]=num;
	 					j=j+1;}
	 				
	 				}	
	 			
	 		}
	 			k=k+1;}
	 	i=i+1;}
 	    return matriz;




}
int main (){
	//creacion de los archivos a trabajar.
	char nombreArchivo[]="matrizEntrada2.in";
	int tamMatriz;
	int **matriz, i;
	int **matrizSalida;


	//invocacion de tamanio matriz y la matriz obtenida.
	tamMatriz=matrixSize(nombreArchivo);
	matrizSalida=matrizObt(matriz,tamMatriz,nombreArchivo);
	printf("\n");
 	for (int i = 0; i < tamMatriz; ++i)
 	    {
 	    	for (int j = 0; j < tamMatriz; ++j)
 	    	{
 	    		printf(" %d ",matrizSalida[i][j]);
 	    	}
 	    	printf("\n");
 	    }

	



}