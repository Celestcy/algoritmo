#include<stdio.h>
#include<stdlib.h>

/*Eje 4*/

main()
{
	int i,enteros[10],contpares=0,nmin,nmax;
	
	for (i=0;i<10;i++)  // i va de 0 a 9
	{
	    printf("Ingrese valor %d\n",i);
	    scanf("%d", &enteros[i]);
	}
	
	for (i=0;i<10;i++)  // i va de 0 a 9
	{
	    printf("el valor cargado en la posicion %d es %d\n",i,enteros[i]);
	}
	
	
	
	
	nmax=enteros[0];  // Guardar el primer elemento del vector
	nmin=enteros[0];
	
	for(i=0;i<10;i++)  // Recorro el vector y comparo
	{
		
		if(enteros[i]>nmax){
			nmax=enteros[i];
		}
		if(enteros[i]<nmin){
			nmin=enteros[i];
		}
		
		printf("el resto de la division entre %d y 2 es %d \n", enteros[i],enteros[i]%2);
		if(enteros[i]%2==0){
			
			contpares++;
		}		
	}

	printf("----\n");
	printf("Numeros pares:%d \n\n",contpares);
	printf("El valor maximo es:%d \n\n",nmax);
	printf("El valor minimo es:%d \n\n",nmin);
	
	system("pause");
}







