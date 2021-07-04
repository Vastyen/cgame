#funcion que busca la condicion maxima para poder iniciar el algoritmo, del array de condiciones entregado
#selecciona el mayor con respecto a la profundidad(posicion) entregada
#retorna un array con el numero de la condicion, el largo de las condiciones seleccionadas, y el indice
#en la lista de posiciones donde se encuentra esta misma.
def buscarCondicionMax(condiciones,posicion):
	i=0
	maxCond=[]
	while i<len(condiciones):
		maxCond.append(len(condiciones[i]))
		i=i+1
	mayorCond=max(maxCond)
	i=0
	numeroSeguir=[]
	print("maxCond ->",maxCond)
	print("mayorCond ->",mayorCond)
	while i<len(condiciones):
		if len(condiciones[i])==mayorCond:
			numeroSeguir.append(condiciones[i][posicion])
		i=i+1

	numeroCond=max(numeroSeguir)
	i=0
	while i<len(condiciones):
		if len(condiciones[i])==mayorCond:
			if (numeroCond in condiciones[i])==True:
				indiceColumna=i
		i=i+1
	return [numeroCond,mayorCond,indiceColumna]
#funcion que posiciona una fila con respecto a los parametros obtenidos, tiene como entrada, el array de columnas
#el array de filas, el indice que seleccionará con que columna se trabajara, el array de condiciones, el largo que 
#se tomaran del array de columnas con respecto a la condicion, el indice de la columna donde se pondra el numero seleccionado
#en la fila, y por ultimo un iterador, nos retorna un array de arrays con parte de la matriz, con respecto a los datos que le entregamos, y el iterador.
def posicionamiento(columnas, filas, indice,condiciones,largo,indiceColumna,k):
	martrizRetorno=[]
	matrizFinal=[]
	columnaTrabajar=columnas[indice]
	#Muchos de los prints que estan aqui son a modo de debugging
	###############
	print(filas)
	print(indice,"no cambio")
	print(columnaTrabajar,"columnaTrabajar")
	#se crea otro iterador ya que el iterador k entregado, se ira aumentando a medida que se avance en la matriz
	#por lo que cada vez que se invoca la funcion posicionamiento, el iterador j parte de 0
	j=0
	print(k,"K antes while")
	print(largo,"largo antes while ")
	#############
	while k<largo:
		print(k,"<----- kPosicionamiento")
		#se busca el numero con el cual tiene que coincidir en la columna con respecto a las
		#condiciones entregadas.
		numeroCoincidir=columnaTrabajar[j]
		############################
		print(numeroCoincidir,"<--- trabajando con numero")
		

		#########################

		#esta parte esta en modo de prueba, ya que creo que la necesito para cuando tenga que posicionar 
		#fila con mas de un numero el cual debe coincidir
		cantidadApariciones=0
		i=0
		while i<len(filas[k]):
			if numeroCoincidir==filas[k][i]:
				cantidadApariciones=cantidadApariciones+1
			i=i+1
		print(cantidadApariciones,"<-- cantidadApariciones")
		#####################################
		
		#se busca el indice de la condicion en nuestra fila (ahora lo llamaremos pivote), 
		#y luego insertamos esta condicion en el indice de la lista
		#con respecto al indice de la columna, esto para empezar a formar
		#la primera fila de la matriz
		poiscionNumeroFila=filas[k].index(numeroCoincidir)
		martrizRetorno.insert(indiceColumna,numeroCoincidir)
		

		print(filas[k],"<-- trabajando fila ")


		print(martrizRetorno,"martrizRetorno")
		#en este punto, se comienza a integrar los numeros que estan por la parte izquierda de nuestro
		#pivote, y se introducen dentro del array
		print("---------------------------------------")
		i=len(filas[k][0:poiscionNumeroFila])-1
		print("test")
		if poiscionNumeroFila>0:
			print(poiscionNumeroFila,"poiscionNumeroFila")
			print(i,"i<---")
			
			while i<poiscionNumeroFila:
				print(filas[k][i],"<--- filas[k][i-1]")
				martrizRetorno.insert(i-1,filas[k][i])
				i=i+1

		
		print(martrizRetorno,"martrizRetorno")
		#luego, buscamos los numeros que esten en la derecha de nuestro pivote, para insertarlos en 
		#la matriz
		print("---------------------------------")
		i=poiscionNumeroFila+1
		
		print(poiscionNumeroFila,"poiscionNumeroFila22222")
		print(i,"i<---")

		if poiscionNumeroFila!=(len(filas[k])-1):
			while i<len(filas[k]):
				print(filas[k][i],"<--- filas[k][i-1]")
				martrizRetorno.insert(i,filas[k][i])
				i=i+1
		#aqui, buscamos las posiciones que no tengan numeros desde donde empieza la matriz,
		#hasta donde esta el primer numero del array creado
		i=0
		while i<(indiceColumna-len(filas[k][0:poiscionNumeroFila])):
			martrizRetorno.insert(i,0)
			i=i+1

		print(martrizRetorno,"martrizRetorno")
		#se hace el mismo proceso pero para el lado derecho de nuestro array introducido en la matriz
		#se rellena con 0 hasta terminar el largo de las columnas.
		print("---------------------------------------")
		


		i=0
		maximo=len(columnas)-len(martrizRetorno)
		print(maximo,"maximo <--")
		while i<maximo:
			print(i,"i while ")
			martrizRetorno.append(0)
			i=i+1
		print(martrizRetorno,"martrizRetorno")
		print("---------------------------------------")
		#finalmente, pasamos el array creado a otro que se exportara
		#y se vacia el array con el que se estaba trabajando
		matrizFinal.append(martrizRetorno)
		print(matrizFinal,"matrizFinal")
		i=0
		martrizRetorno=[]
		print(martrizRetorno,'martrizRetorno')



		input("aqui caigo")
		print("##################################################")


		j=j+1
		k=k+1
	return [matrizFinal,k]
		



#esta funcion es inicializadora de la creacion de la matriz, tiene como entrada las filas, las columnas y las condiciones obtenidas
#desde nuestro archivo

def crearMatriz(filas,columnas,condiciones):
	matriz=[]
	
	posicion=0
	i=0
	#invocamos la funcion que busca la condicion maxima para poder obtener 
	#el numero del largo de la mayor condicion
	condMax=buscarCondicionMax(condiciones,posicion)
	k=0
	largoInicial=0
	#se crea un ciclo para empezar a invocar la funcion creadora
	#de matrices
	while i < condMax[1]:
		print("""


			---------INICIO WHILE------------ 


			""")

		print(k,"<---- k")
		#inicializamos la funcion que busca las condiciones
		siguienteBusq=buscarCondicionMax(condiciones,i)
		####################################
		#buscamos el indice para obtener la columna a trabajar
		j=0
		while j<len(condiciones):
			if len(condiciones[j])==siguienteBusq[1]:
				if condiciones[j][i]==siguienteBusq[0]:
					indice=j		
			j=j+1
	
		print("heey")
		print(indice,"indice")
		input("enter")
		print(siguienteBusq[0],"<-- largo!!!!")
		print(largoInicial,"<----largo inicial ACA!!!")
		#guardamos el largo con respecto al largo anterior con el inicial
		largo=largoInicial+siguienteBusq[0]
		print(largo,"<-- largo MODIFICADO")
		posicionamientoMatriz=posicionamiento(columnas,filas,indice,condiciones,largo,siguienteBusq[2],k)
		
		matriz.append(posicionamientoMatriz[0])
		print(matriz,"<--- matriz ")
		print(len(matriz),"<----largoMatriz")
		#rescatamos el iterador entregado en la funcion de posicionamiento
		k=posicionamientoMatriz[1]
		#guardamos el largo obtenido en la invocacion anterior
		largoInicial=largo-1
		i=i+1

	#imprimimos la funcion obtenida
	print("-----------------------------------------")
	print(""" 


			ESPACIOS 



		""")
	print(matriz)
	print(len(matriz),"<-- largo Matriz fuera")
	i=0
	while i<condMax[1]:
		j=0
		while j<len(matriz[i]):
			print(matriz[i][j])
			j=j+1
		i=i+1
	

#estos datos suponen la entrada obtenida por la entrada de archivos
filas=[[1,2,1,1],[2,1],[1,2],[1,1,1,2,1],[1,1],[1,2,1],[1],[1,2,2],[1,3,3,2],[2,2]]
columnas=[[0],[0],[1,1,1],[2,2,2,1,1,2,1],[1,1,1,2,1,2,3,2],[1,1,1,1,3,2],[2,1,2],[1],[0],[0]]
condiciones=[[0],[0],[1,1,1],[4,1,2],[2,1,5],[1,3,2],[2,1],[1],[0],[0]]
#invocamos la funcion
crearMatriz(filas,columnas,condiciones)

