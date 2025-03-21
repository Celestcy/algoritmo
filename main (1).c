#include <stdio.h>
#include <stdlib.h>


void main()
{
	float lts,ml[50][7]={0.0};
	int i,j,sur,dia;
	printf("Ingresar el num. surtidor ");
	scanf("%d",&sur);
	while(sur!=0)
	{
		printf("Ingrese el dia de la semana (1-7)");
		scanf("%d",&dia);
		printf("Ingrese lts ");
		scanf("%f",&lts);
		ml[sur-1][dia-1]=ml[sur-1][dia-1]+lts;
		printf("Ingresar el num. surtidor ");
	    scanf("%d",&sur);	
	}
	
	for(i=0;i<50;i++)
	{
		for(j=0;j<7;j++)
		{
			printf("[%6.2f]",ml[i][j]);
			
	    }
	    printf("\n");
	}	
}
