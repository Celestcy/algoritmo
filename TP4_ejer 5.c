#include <stdio.h>
#include <conio.h>
#define indice 10

main()
{
      int vec[indice], ban1=0, ban2=0, bus1, bus2,i;
      
    
      printf("--------------------------\n\n\n");
      for(i=0;i<indice;i++)
      {
          printf("Ingrese el numero %i de 10: \n",i+1);
          scanf("%i",&vec[i]);
      }
      system ("CLS");
      printf("Ingrese el primer valor a buscar\n");
      scanf("%i",&bus1);
      printf("Ingrese el segundo valor a buscar\n");
      scanf("%i",&bus2);
      system("CLS");
      for(i=0;i<indice;i++)
      {
         //primera busqueda
         if(vec[i]==bus1)
         {
           ban1=1;
         }
                  //segunda busqueda
         if(vec[i]==bus2)
         {
           ban2=1;
         }
      }
      
      if(ban1==1)
      {
        printf("El numero %i se encuentra entre los anteriores\n", bus1);
      }
      else   
      {
        printf("El numero %i no se encuentra entre los anteriores\n",bus1);
      }
      
      if(ban2==1)
      {
        printf("El numero %i se encuentra entre los anteriores\n",bus2);
      }
      else   
      {
        printf("El numero %i no se encuentra entre los anteriores\n",bus2);
      }
      
   getch();
   
}
