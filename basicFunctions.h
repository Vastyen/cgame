//Inicializamos basicFunctions
#ifndef _BASICFUNCTIONS


//maximaCondicion, busca la condicion mayor entre los array de condiciones
int maximaCondicion(int condiciones[][3], int largo, int *indice){
	int max=0;
	for (int i = 0; i < largo; ++i)
	{
		if (condiciones[i][0]>max){
			max=condiciones[i][0];
			*indice=i;
		}
	}
	return max;


}


#endif