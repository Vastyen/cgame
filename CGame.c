#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"title.h"
#include"scrClean.h"


int main(){
	int opt;
	//invocación desde title.h
	printSpider();
	//Falta implementar forma de que no caiga
	// al momento de ingresar tipo de dato incorrecto
	scanf("%d",&opt);
	while(opt<1 || opt>4){
		printf("INGRESE UNA OPCIÓN CORRECTA!: ");
		scanf("%d",&opt);
	}
	scrClean();
	printf("TEST TERMINADO CON EXITO!\n");	

	return 0;
}