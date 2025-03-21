#include <stdio.h>
#include <stdlib.h>

void carga (float *,int,float);
float media(float *);
int mayor(float *);
void main()
{
	int i,dia,opc;
	float potencia,potencias[7]={0.0};
	do
	{
		system("cls");
		printf("1 - Carga de datos.");
		printf("\n2 - Potencia media.");
		printf("\n3 - Dia de mayor potencia.");
		printf("\n4 - Dias mayor a potencia media.");
		printf("\n5 - Salir");
		printf("\n\nSu Opcion : ");
		scanf("%d",&opc);
		switch(opc)
		{
			case 1:
				system("cls");
				printf("Dia de la semana : ");
				scanf("%d",&dia);
				printf("Potencia consumida : ");
				scanf("%f",&potencia);
				carga(potencias,dia,potencia);
				break;
			case 2:
				printf("La potencia media es : %.2f \n",media(potencias));
				system("pause");
				break;
			case 3:
				printf("Dia de mayor potencia : %d\n",mayor(potencias));
				system("pause");
				break;
			case 4:
				for(i=0;i<7;i++)
				{
					if (potencias[i]>=media(potencias))
					{
						printf("Dia %d supera con potencia %.2f\n",i+1,potencias[i]);
					}
				}
				system("pause");
				break;
			case 5:
				break;
		}
	}while (opc!=5);
}

void carga(float *potencias,int dia,float potencia)
{
	*(potencias+dia-1)=*(potencias+dia-1)+potencia;
}

float media(float * potencias)
{
	int i,cant=0;
	float suma=0.0;
	for(i=0;i<7;i++)
	{
		suma=*(potencias+i)+suma;
		cant++;
	}
	return (suma/cant);
}

int mayor(float *potencias)
{
	int i,dmayor=0;
	float pmayor=0.0;
	for (i=0;i<7;i++)
	{
		if(pmayor<*(potencias+i))
		{
			dmayor=i+1;
			pmayor=*(potencias+i);
		}
	}
	return (dmayor);
}

