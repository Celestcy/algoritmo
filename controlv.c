#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 50

void cargar(float *,int *,int *,int *,float,int,int,int,int);
void informe(float *,int *, int *,int *,int);
void main()
{
	int hora,minutos,cod,op,pos=0;
	int vhora[tam]={0},vminutos[tam]={0},vcod[tam]={0};
	float velocidad,vvelocidad[tam]={0.0};
	
	do
	{
		system("cls");
		printf(" 1- Ingresar y cargar vectores con datos de simulacion");
		printf("\n 2- Emitir reportes");
		printf("\n 3- Salir");
		printf("\n\n Elija una opcion: ");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				system("cls");
				printf("Ingrese velocidad: ");
				scanf("%f",&velocidad);
				printf("\n Ingrese hora: ");
				scanf("%d",&hora);
				printf("\n Ingrese minutos: ");
				scanf("%d",&minutos);
				printf("\n Ingrese codigo de camion 1-3: ");
				scanf("%d",&cod);
				cargar(vvelocidad,vhora,vminutos,vcod,velocidad,hora,minutos,cod,pos);
				pos++;
				break;
			case 2:
				system("cls");
				informe(vvelocidad,vhora,vminutos,vcod,pos);
				break;
			case 3:
				break;
			
		}		
		
	}while(op!=3);
}

void cargar(float *vvelocidad,int *vhora,int *vminutos,int *vcod,float velocidad,int hora,int minutos,int cod,int pos)
{
	*(vvelocidad+pos)=velocidad;
	*(vhora+pos)=hora;
	*(vminutos+pos)=minutos;
	*(vcod+pos)=cod;	
}

void informe(float *vvelocidad,int *vhora, int *vminutos,int *vcod,int pos)
{
	float max;
	int i;
	for (i=0;i<pos;i++)
 	{
        if (*(vcod + i) == 2) 
		{
            if (*(vvelocidad + i) > max) 
			{
                max = *(vvelocidad + i); 
            }
        }
        
       	printf("\n Datos del camion 2:");
		printf("\n Hora: %d",*(vhora+i));
		printf("\n Minutos: %d",*(vminutos+i));
		printf("\n Maxima velocidad registrada: %.2f\n",max);
		system("pause");
    }	
}
	

