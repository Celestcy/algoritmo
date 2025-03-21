#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TAM 4

int primo(int);
 main()
{
   int mat[TAM][TAM], mat1[TAM][TAM], matr[TAM][TAM]={0};
       int i,j, k,max,pri;
	   float suma=0;
       float promedio;
    
    for (i=0;i<TAM;i++)
      {
       for (j=0;j<TAM;j++)
    	{
    		printf("\n Ingrese el valor %d %d de la matriz: ", i, j);
    		scanf("%d",&mat[i][j]);  
    	}
     }
     
     printf("\n Matriz base:");
      for (i=0;i<TAM;i++)
      {
       for (j=0;j<TAM;j++)
    	{
    		printf("\n Elemento %d  %d es  %d ", i,j, mat[i][j]);
    	}
    	printf(" \n");
     }
    	
    ////////////////
    printf("La diagonal principal es: ");
    printf("\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (i == j)
                printf("%d \t\n", mat[i][j]);

        }
    }
    for ( i = 0; i < TAM; i++) {
        for ( j = 0; j < TAM; j++) {
            if (i == j)
                suma = suma + mat[i][j];
                     }
    }
    
    promedio = suma / TAM;

    printf("\n");

    printf("El promedio de la diagonal principal es: %f ",promedio);
    
    //////////////////////////////
	////////////////
	suma=0;
    printf("La diagonal secundaria es: ");
    printf("\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if ((i+j) == (TAM-1))
                printf("%d \t\n", mat[i][j]);

        }
    }
    for ( i = 0; i < TAM; i++) {
        for ( j = 0; j < TAM; j++) {
            if ((i+j) == (TAM-1))
                suma = suma + mat[i][j];
                     }
    }
    
    promedio = suma / TAM;

    printf("\n");

    printf("El promedio de la diagonal secundaria es: %f ",promedio);
    
    //////////////////////////////
	
	
		
    printf("\n Armo la  matriz transpuesta:");	
    
     for (i=0;i<TAM;i++)
      {  
       for (j=0;j<TAM;j++)
    	{
    	  mat1[j][i]=mat[i][j];  // Al ememento mat1 j i le asigno el elemento mat i j 
    	}		
       }
       
     printf("\n Matriz transpuesta:");
       for (i=0;i<TAM;i++)
      {
       for (j=0;j<TAM;j++)
    	{
    		printf("\n Elemento %d  %d  es  %d ", i, j, mat1[i][j]);
    	}
    	printf(" \n");
     }
     
        printf("\n Matriz multiplicacion al inicio:");
       for (i=0;i<TAM;i++)
      {
       for (j=0;j<TAM;j++)
    	{
    		printf("\n Elemento %d  %d  es  %d ", i, j, matr[i][j]);
    	}
    	printf(" \n");
     }
     
for (i = 0; i < TAM; i++) {

for ( j = 0; j < TAM; j++) {

for ( k = 0; k < TAM; k++) {

matr[i][j] = matr[i][j] + mat[i][k] * mat1[k][j];

}

}

}
   
   
     printf("\n Matriz multiplicacion final:");
       for (i=0;i<TAM;i++)
      {
       for (j=0;j<TAM;j++)
    	{
    		printf("\n Elemento %d  %d  es  %d ", i, j, matr[i][j]);
    	}
    	printf(" \n");
     }
    getch();
    
    
    printf("\n Numeros Primos:");
      for (i=0;i<TAM;i++)
      {
       for (j=0;j<TAM;j++)
    	{
    		pri=primo(mat[i][j]);
    		if (pri>=1 && pri<=2)
    			printf("el numero %d es primo\n",mat[i][j]);
    	}
    	printf(" \n");
     }
    
}

int primo(int num1)
{
	int i;
	int a=0;
	for(i=1;i<=num1;i++)
	{	
    if(num1%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
    	a++;
	}

return a;
}

