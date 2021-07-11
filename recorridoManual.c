#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"scrClean.h"


/*Funcion que imprime la matriz a partir de cada cambio. Tiene como entrada la matriz, el tamanio de esta
y la seleccion del eje x e y*/
void imprimeMatriz(int matriz[][10], int tamanMatriz, int x, int y){

	printf("-> x es: %d \n", x);
	printf("-> y es: %d \n", y );

	//recorrido filas
	for (int j = 0; j < tamanMatriz; ++j){

		//recorrido columnas
		for (int i = 0; i < tamanMatriz; ++i){
			//seleccion del elemento que busca el usuario
			if (x==j && y==i){
					printf("[%d]", matriz[j][i]);
				}
			else printf(" %d ", matriz[j][i]);

		}


		printf("\n");
	}
}
/*Funcion que toma el ultimo digito de la primera posicion del array,
para saber desde donde partir en la funcion del recorrido. de esta forma, obtiene la posicion
del edificio que esta en la posicion mas superior derecha, tiene como entrada la matriz a trabajar, y retorna 
el indicie*/
int posicionFinal(int matriz[][10]){
	int indiceFinal=0;
	int i =10;
	while(i>0){
		if(matriz[0][i]!=0){
			if (indiceFinal==0)
			{
				indiceFinal=i;
			}
		}
		i=i-1;
	}
	return indiceFinal;
}
/*La funcion atrapado permite buscar en cada posicion nueva si es que se quedara atrapado dentro de 0s
o no, tiene como entrada la matriz, la posicion (x,y), y el tamanio de la matriz, nos retorna 1 si no esta atrapado
y 0 si lo esta*/
int atrapado(int matriz[][10],int x,int y, int tamanMatriz){
	int salida=1;
	if (x==0){
		if (y==0){
			if (matriz[x+1][y]==0 && matriz[x][y+1]==0){
				salida=0;
				return salida;
				}
			}
		else{
			if (matriz[x+1][y]==0 && matriz[x][y+1]==0 && matriz[x][y-1]==0){
				salida=0;
				return salida;

			}
		}
	}


	if (x==(tamanMatriz-1)){
		if (y==(tamanMatriz-1)){
			if (matriz[x-1][y]==0 && matriz[x][y-1]==0){
				salida=0;
				return salida;
				}
		}
		else{
			if (matriz[x-1][y]==0 && matriz[x][y-1]==0 && matriz[x][y+1]==0){
				salida=0;
				return salida;
			}
		}
	}


	if (y==0){
		if (x==0){
			if (matriz[x+1][y]==0 && matriz[x][y+1]==0){
				salida=0;
				return salida;
				}
			}
		else{
			if (matriz[x+1][y]==0 && matriz[x][y+1]==0 && matriz[x][y-1]==0){
				salida=0;
				return salida;
			}
		}
	}




	if (y==(tamanMatriz-1)){
		if (x==(tamanMatriz-1)){
			if (matriz[x-1][y]==0 && matriz[x][y-1]==0){
				salida=0;
				return salida;
				}
		}
		else{
			if (matriz[x-1][y]==0 && matriz[x][y-1]==0 && matriz[x][y+1]==0){
				salida=0;
				return salida;
			}
		}
	}

	if (matriz[x+1][y]==0 && matriz[x-1][y]==0 && matriz[x][y+1]==0 && matriz[x][y-1]==0)
	{
		salida=0;
		return salida;
	}
	else return salida;

}

/*la funcion verificaMatriz nos permite saber si es que la matriz esta en su estado final o no, 
si aun esta incompleta, retorna 0, si la matriz ya esta lista, retorna 1*/
int verificaMatriz(int matriz[][10],int tamanMatriz){
	int matrizLista=0;
	for (int i = 0; i < tamanMatriz; ++i){

		for (int j = 0; j < tamanMatriz; ++j){
			if (matriz[i][j]!=0){
				matrizLista=1;
			}
		}
	}
	return matrizLista;
}


/*La funcion salidaOut nos permite guardar un string dentro de un archivo .out en este caso, tiene como entrada
el puntero del string, y no retorna nada al ser una funcion void*/
void salidaOut(char *buffer){
	FILE * salida;
	salida=fopen("salida2.out","wt");
	fputs(buffer,salida);
	fclose(salida);
	printf("Guardado con exito!\n");
}
/*La funcion recorridoMan es una de las funciones principales, la cual funciona como eje central del recorrido manual, tiene
como entrada la matriz a recorrer y el tamanio de esta, al ser void, no retorna nada.*/
void recorridoMan(int matriz[][10], int tamanMatriz){
	//creamos las posiciones iniciales para el eje x e y.
	int y=posicionFinal(matriz), x=0;
	//Primera posicion, hace referencia a si es la primera jugada en el tablero o no.
	int primeraPosicion=0;
	//Se crea un char array en entrada, para que en caso de que ocurran errores, poder recuperarlos.
	char entrada[255];
	//verifica la salida.
	int sinSalida;
	//verifica si es correcta la matriz.
	int verificacionMatriz;
	//creamos 2 char que nos permitan obtener y guardar las direcciones
	//N S E O
	char *direccion;
	char *buffer;
	//Se inicializa el buffer para poder obtener los datos de posicion.
	buffer=(char*)malloc(4);
	int i=0;
	int exit=0;

	while(exit!=1){

		imprimeMatriz(matriz,tamanMatriz,x,y);
		printf("-muevete con las teclas WASD- selecciona una dirección y luego enter:");
		scanf(" %s",entrada);
		while (strcmp(entrada,"w")!=0 &&strcmp(entrada,"d")!=0 &&strcmp(entrada,"s")!=0 &&strcmp(entrada,"a")!=0 )
		{
			printf("INGRESA UNA ENTRADA VALIDA\n");
			printf("-muevete con las teclas WASD- selecciona una dirección y luego enter:");
			scanf(" %s",entrada);
		}

		if (primeraPosicion==0)
		{
			matriz[x][y]=matriz[x][y]-1;
			primeraPosicion=primeraPosicion+1;
		}

		scrClean();		
		
		//Luego, dependiendo de la entrada del user, se selecciona la posicion, se verifica si es valida
		//de serlo, se guarda en el buffer, se elimina una pasada por la posicion, se cambia a la posicion siguiente
		//y se vuelve a preguntar por la seleccion.
		if (strcmp(entrada,"w")==0){	
			x=x-1;
			y=y;
			if (matriz[x][y]==0){
				printf("HAY UN 0!");
				x=x+1;
				y=y;
			}
			else{
				if(x>=0 && y>=0 && x<tamanMatriz && y<tamanMatriz){
					matriz[x][y]=matriz[x][y]-1;
					direccion="N";
					strcat(buffer,direccion);
					buffer=(char *)realloc(buffer,8+i);
					i=i+1;
					verificacionMatriz=verificaMatriz(matriz,10);
					if (verificacionMatriz==0)
					{
						printf("GANASTE!\n");
						salidaOut(buffer);
						free(buffer);
						exit=1;
					}
					else{
						sinSalida=atrapado(matriz,x,y,10);
						if (sinSalida==0)
						{
							exit=1;
						}
					}
					
					
					
					}
				else{	
					printf("FUERA DE LA MATRIZ! INTENTA NUEVAMENTE\n");
					x=x+1;
					y=y;
				}

		}
	}



		if (strcmp(entrada,"a")==0){	
			x=x;
			y=y-1;
			if (matriz[x][y]==0){
				printf("HAY UN 0!");
				x=x;
				y=y+1;
			}
			else{
				if(x>=0 && y>=0 && x<tamanMatriz && y<tamanMatriz){
					matriz[x][y]=matriz[x][y]-1;
					direccion="E";
					strcat(buffer,direccion);
					buffer=(char *)realloc(buffer,8+i);
					i=i+1;
					verificacionMatriz=verificaMatriz(matriz,10);
					if (verificacionMatriz==0)
					{
						printf("GANASTE!\n");
						salidaOut(buffer);
						free(buffer);
						exit=1;
					}
					else{
						sinSalida=atrapado(matriz,x,y,10);
						if (sinSalida==0)
						{
							exit=1;
						}
					}	}
				else{
					
					printf("FUERA DE LA MATRIZ! INTENTA NUEVAMENTE\n");
					x=x;
					y=y+1;
				}
				
			}
		}
		if (strcmp(entrada,"s")==0){	
			x=x+1;
			y=y;
			if (matriz[x][y]==0){
				printf("HAY UN 0!");
				x=x-1;
				y=y;
			}
			else{
				if(x>=0 && y>=0 && x<tamanMatriz && y<tamanMatriz){
					matriz[x][y]=matriz[x][y]-1;
					direccion="S";
					strcat(buffer,direccion);
					buffer=(char *)realloc(buffer,8+i);
					i=i+1;
					verificacionMatriz=verificaMatriz(matriz,10);
					if (verificacionMatriz==0)
					{
						printf("GANASTE!\n");
						salidaOut(buffer);
						free(buffer);
						exit=1;
					}
					else{
						sinSalida=atrapado(matriz,x,y,10);
						if (sinSalida==0){
							exit=1;
						}}
					}
				else{
					printf("FUERA DE LA MATRIZ! INTENTA NUEVAMENTE\n");
					x=x-1;
					y=y;
				}
				
			}}
		if (strcmp(entrada,"d")==0)
		{	
			x=x;
			y=y+1;
			if (matriz[x][y]==0){
				printf("HAY UN 0!");
				x=x;
				y=y-1;
			}
			else{
				if(x>=0 && y>=0 && x<tamanMatriz && y<tamanMatriz){
					matriz[x][y]=matriz[x][y]-1;
					direccion="O";
					strcat(buffer,direccion);
					buffer=(char *)realloc(buffer,8+i);
					i=i+1;
					verificacionMatriz=verificaMatriz(matriz,10);
					if (verificacionMatriz==0)
					{
						printf("GANASTE!\n");
						salidaOut(buffer);
						free(buffer);
						exit=1;
					}
					else{
						sinSalida=atrapado(matriz,x,y,10);
						if (sinSalida==0)
						{
							exit=1;
						}}
				
			}
				else{
					
					printf("FUERA DE LA MATRIZ! INTENTA NUEVAMENTE\n");
					x=x;
					y=y-1;
				}
				
			}

		}
		


	}
	if (sinSalida==0)
	{
		printf("PERDISTE!!\n");
	}

	
}

int main(){
	//Se inicializa una matriz a modo de prueba, ya que ahora esta dentro del codigo, pero 
	//se debe recoger desde ambos archivos de entradas.
	int matriz[10][10]={{0,0,1,2,1,1,0,0,0,0},{0,0,0,2,1,0,0,0,0,0},{0,0,1,2,0,0,0,0,0,0},
						{0,0,0,1,1,1,2,1,0,0},{0,0,0,0,0,1,1,0,0,0},{0,0,0,1,2,1,0,0,0,0},
						{0,0,0,0,1,0,0,0,0,0},{0,0,1,2,2,0,0,0,0,0},{0,0,0,1,3,3,2,0,0,0},
						{0,0,0,0,2,2,0,0,0,0}};
	//Se invoca la funcion de recorrido manual.
	recorridoMan(matriz,10);
}
