#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"basicFunctions.h"

/*CreaMatriz, busca crear la matriz a partir de las filas, condiciones y columnas entregadas
*/
void creaMatriz(int filas[][10],int columnas[][10],int condiciones[][3]){

	int max;
	int indice=0;
	int largo=0;
	int columnaTrabajar[10];
	int numeroTrabajar=0;
	int cantidadAparicion=0;
	/*maximaCondicion busca entre el array la maxima condicion, y además devuelve el 
	indice de la máxima condición*/
	max=maximaCondicion(condiciones,10,&indice);
	//Primer for para ir columna a columna preguntando con el numero que se debe trabajar
	for (int i = 0; i < 10; ++i)
	{
		columnaTrabajar[i]=columnas[indice][i];
	}
	//mientras sea distinto de 0, se imprmirá la columna a trabajar
	for (int i = 0; i < 10; ++i)
	{	if (columnaTrabajar[i]!=0){
		printf("%d \n",columnaTrabajar[i]);
	}
	}
	//Ahora, siguiendo la logica de la lectura del archivo de testCreacionMatriz.py
	//vamos preguntando por la cantidad de apariciones.
	for (int i = 0; i < max; ++i)
	{
		cantidadAparicion=0;
		numeroTrabajar=columnaTrabajar[i];
		printf("trabajando con %d \n", numeroTrabajar);
		for (int k = 0; k < 10; ++k)
		{
			if (numeroTrabajar==filas[i][k])
			{
				cantidadAparicion++;
			}
			
		}
		printf("%d \n",cantidadAparicion);
	}
	//Esto esta a modo de debugging, muestra el numero mayor y su indice dentro del array
	printf("%d index %d \n",max,indice);




}

/*Representacion basica de las 3 matrices que se deberian trabajar, las filas, las columnas y 
las condiciones soportan hasta 10 elementos, tanto en filas como en condiciones soportan 10 elementos 
dentro de los elementos anteriores, se invoca creaMatriz*/
int main(){

	int filas[10][10]={{1,2,1,1},{2,1},{1,2},{1,1,1,2,1},{1,1},{1,2,1},{1},{1,2,2},{1,3,3,2},{2,2}};
	int columnas[10][10]={{0},{0},{1,1,1},{2,2,2,1,1,2,1},{1,1,1,2,1,2,3,2},{1,1,1,1,3,2},{2,1,2},{1},{0},{0}};
	int condiciones[10][3]={{0},{0},{1,1,1},{4,1,2},{2,1,5},{1,3,2},{2,1},{1},{0},{0}};

	creaMatriz(filas,columnas,condiciones);
	return 0;
}