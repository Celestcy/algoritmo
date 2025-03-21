#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tam 500

void mostrar(int*,float*,int*,int*);
void cargar(int,int,float,int,int,int*,float*,int*,int*);
int validar(int,int,int*,int*);
void main (){
	setlocale(LC_ALL,"spanish");
	int opc,dni,dia,mesa,vdni[tam]={0},vdia[tam]={0},vmesa[tam]={0};
	float imp,vimp[tam]={0.0};
	do{
	system("cls");
	printf("1 - Registrar una reserva\n");
	printf("2 - Mostrar las reservas del mes\n");
	printf("3 - Salir\n");
	printf("Su opción: ");
	scanf("%d",&opc);
	system("cls");
	switch (opc){
		case 1:
			printf("Dni del contacto: ");
			scanf("%d",&dni);
	        printf("Importe de la seña: ");
	        scanf("%f",&imp);
	        printf("Día del mes: ");
	        scanf("%d",&dia);
	        printf("Número de mesa: ");
	        scanf("%d",&mesa);
	        cargar(validar(dia,mesa,vdia,vmesa),dni,imp,dia,mesa,vdni,vimp,vdia,vmesa);
	        break;
	    case 2:
	    	mostrar(vdni,vimp,vdia,vmesa);
	    	break;
	    case 3:
	    	printf("PROGRAMA FINALIZADO");
	    	break;
	}
    }while (opc!=3);
}
int validar(int dia,int mesa,int*vdia,int*vmesa){
	int pos=0,b=0;
	while (*(vdia+pos)!=0 && pos<tam){
		if (*(vdia+pos)==dia && *(vmesa+pos)==mesa)
		b=1;
		pos++;
	}
	return b;
}
void cargar(int b,int dni,float imp,int dia,int mesa,int*vdni,float*vimp,int*vdia,int*vmesa){
	int pos=0;
	while(*(vdia+pos)!=0 && pos<tam)
	pos++;
	if (b==1){
	system("cls");
	printf("Día y mesa ya reservados\n");
	system("pause");
	}
	else if (pos==tam){
	system("cls");
	printf("No se pueden ingresar más reservas\n");
	system("pause");
	}
	else{
	*(vdni+pos)=dni;
	*(vimp+pos)=imp;
	*(vdia+pos)=dia;
	*(vmesa+pos)=mesa;
	}
}
void mostrar(int*vdni,float*vimp,int*vdia,int*vmesa){
	int pos=0;
	if (*vdia==0){
	printf("No se han ingresado reservas aún\n");
	system("pause");
	}
	while(*(vdia+pos)!=0 && pos<tam){
	system("cls");
	printf("===========================\n");
	printf("    INFORME DE RESERVAS    \n");
	printf("===========================\n");
	printf("Día %d\n",*(vdia+pos));
	printf("Dni del contacto: %d\n",*(vdni+pos));
	printf("Número de mesa: %d\n",*(vmesa+pos));
	printf("Cantidad restante a pagar: $%.2f\n",25000-*(vimp+pos));
	system("pause");
	pos++;
	}
}
