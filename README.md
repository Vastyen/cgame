### **Algoritmo**
  Sabemos que tenemos n **filas** para e cantidad de edificio 
  También es posible conocer **e** cantidad de **edificios**  
  
  **Hipótesis de Algoritmo**

*   Las posiciones deberán auto-designarse de forma aleatoria mientras se cumpla
      que la cantidad de columnas, menos la cantidad total de edificios, menos
       la cantidad de espacios y en algún momento an, menos la cantidad de aₙ-1.
       Entiendo que an generará una función deberá ser utilizado posteriormente
       para quitar espacios al algoritmo y que pueda randomizar correctamente.

  a₁, a₂, a₃... aₙ += e Cantidad de edificios (a,b, c son la consecutividad y e la suma total).
  k = Cantidad de espacios ya usados. (Rellenar() **-=**)
  n = Cantidad de filas ingresadas.
 
  Para aₙ
    Se podría implementar *recursión*.
	
	
**Ejemplo en pseudo-código**
 
	Intentar {
	limpiarColumnaEscrita(); // Sabemos que estamos utilizando recursión, por lo tanto 
	al momento de intentar de todas formas estaremos llamando
	a la función escribirEnMatriz(); y al momento de que nuestro caso
	base no se cumpla (cuando aₙ logra llamar a la función rellenarAₙ();)
 		
 		   Para a₁{
    		   posInicial = random(){
     	    solo sí n-e-k < n{
           rellenarA(
                escribirEnMatriz();
               )
         }
 		  }
 		 Para a₂{
 	    posInicial = random(){
 	       solo sí n-e-k-rellenarA() <n {
 	              escribirEnMatriz();
              )
		   	}
   		 }
    	Para a₃{
    	  posInicial = random(){
        solo sí n-e-k-rellenarA2() <n {
          rellenarA3(
              escribirEnMatriz();
              )
              }
		    }
		  } Mientras llenar aₙ (o a3 en este caso) no se ejecute;
