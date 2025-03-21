#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcalcularCosto(char tipo, char marca[], int talla, int stocks[3][3]);
void funventas(int stocks[3][3], int* totalRecaudado, int* ventaMasAlta, int* clienteVentaMasAlta);
void mostrarStock(int stocks[3][3], char tipos[3][10], char marcas[3][10]);
void informeFinal(int totalRecaudado, int ventaMasAlta, int clienteVentaMasAlta, int zapatillasPumaMayor40);
int numerocliente();

int main() {
    int stocks[3][3], i, j, numcliente;
    char marcas[3][10] = {"Nike", "Puma", "Adidas"};
    char tipos[3][10] = {"Zapatilla", "Botines", "Otros"};
    int opcion, totalRecaudado = 0, ventaMasAlta = 0, clienteVentaMasAlta = 0;
    int zapatillasPumaMayor40 = 0;  

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            stocks[i][j] = 50;  
        }
    }

    
    do {
        printf("\t\tMenu principal");
        printf("\n\n1- Venta");
        printf("\n\n2- Revisar stock");
        printf("\n\n3- Informar");
        printf("\n\nSeleccione opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion) {
            case 1:
                funventas(stocks, &totalRecaudado, &ventaMasAlta, &clienteVentaMasAlta);
				numcliente = numerocliente();
				printf("Su número de cliente es: %d\n", numcliente);
                break;
            case 2:
                mostrarStock(stocks, tipos, marcas); 
                break;
            case 3:
                informeFinal(totalRecaudado, ventaMasAlta, clienteVentaMasAlta, zapatillasPumaMayor40);
                break;
        }
    } while (opcion != 4);

    return 0;
}


int funcalcularcosto(char tipo, char marca[], int talla, int stocks[3][3], int* zapatillasPumaMayor40) {
    int costo = 0;

    if (tipo == 'Z') {
        if (strcmp(marca, "Nike") == 0) stocks[0][0] = stocks[0][0] - 1;
        if (strcmp(marca, "Puma") == 0) stocks[0][1] = stocks[0][1] - 1;
        if (strcmp(marca, "Adidas") == 0) stocks[0][2] = stocks[0][2] - 1;

        if (strcmp(marca, "Nike") == 0 || strcmp(marca, "Adidas") == 0) {
            costo = (talla > 40) ? 90000 : 70000;
        } else if (strcmp(marca, "Puma") == 0) {
            costo = (talla > 40) ? 60000 : 45000;
            if (talla > 40) {
                (*zapatillasPumaMayor40)++;  
            }
        }
    } else if (tipo == 'B') {
        if (strcmp(marca, "Nike") == 0) stocks[1][0] = stocks[1][0] - 1;
        if (strcmp(marca, "Puma") == 0) stocks[1][1] = stocks[1][1] - 1;
        if (strcmp(marca, "Adidas") == 0) stocks[1][2] = stocks[1][2] - 1;

        costo = talla * 2000;
    } else if (tipo == 'O') {
        if (strcmp(marca, "Nike") == 0) stocks[2][0] = stocks[2][0] - 1;
        if (strcmp(marca, "Puma") == 0) stocks[2][1] = stocks[2][1] - 1;
        if (strcmp(marca, "Adidas") == 0) stocks[2][2] = stocks[2][2] - 1;

        if (strcmp(marca, "Nike") == 0 || strcmp(marca, "Adidas") == 0) {
            costo = talla * 1000;
        } else if (strcmp(marca, "Puma") == 0) {
            costo = talla * 500;
        }
    }

    return costo;
}


void funventas(int stocks[3][3], int* totalRecaudado, int* ventaMasAlta, int* clienteVentaMasAlta) {
    char tipocal, marca[10];
    int talla = 0, costo = 0, numcliente;
    static int cantidadVentas = 0;
    static int zapatillasPumaMayor40 = 0;

    printf("Tipo de calzado solicitado: Z (zapatillas), B (botines para futbol), O (otros): ");
    scanf(" %c", &tipocal);
    printf("\nMarca del calzado (Nike, Adidas, Puma): ");
    scanf("%s", marca);
    printf("\nTalla del calzado: ");
    scanf("%d", &talla);
    int stockIndex = -1;  
    if (tipocal == 'Z') stockIndex = 0;  
    else if (tipocal == 'B') stockIndex = 1;  
    else if (tipocal == 'O') stockIndex = 2;  

    int marcaIndex = -1; 
    if (strcmp(marca, "Nike") == 0) marcaIndex = 0;
    else if (strcmp(marca, "Puma") == 0) marcaIndex = 1;
    else if (strcmp(marca, "Adidas") == 0) marcaIndex = 2;

    
    if (stockIndex != -1 && marcaIndex != -1 && stocks[stockIndex][marcaIndex] > 0) {
        costo = funcalcularcosto(tipocal, marca, talla, stocks, &zapatillasPumaMayor40);
        printf("\nEl costo es: %d\n", costo);

        (*totalRecaudado) += costo;

        if (costo > *ventaMasAlta) {
            *ventaMasAlta = costo;
            *clienteVentaMasAlta = numcliente;
        }

        if (tipocal == 'Z') {
            printf("Tipo de calzado vendido: Zapatilla\n");
        } else if (tipocal == 'B') {
            printf("Tipo de calzado vendido: Botines\n");
        } else if (tipocal == 'O') {
            printf("Tipo de calzado vendido: Otros\n");
        }

        cantidadVentas++;
        printf("\nVentas realizadas hasta el momento: %d\n", cantidadVentas);
    } else {
        printf("No hay stock disponible para el calzado solicitado.\n");
    }
}



void mostrarStock(int stocks[3][3], char tipos[3][10], char marcas[3][10]) {
    int i, j;
    printf("\nStock actual:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Tipo: %s - Marca: %s - Stock: %d\n", tipos[i], marcas[j], stocks[i][j]);
        }
    }
    printf("\n");
}


int numerocliente() {
    static int numcliente = 0;
    numcliente++;
    return numcliente;
}


void informeFinal(int totalRecaudado, int ventaMasAlta, int clienteVentaMasAlta, int zapatillasPumaMayor40) {
    printf("\nINFORME DEL DÍA\n");
    printf("Cantidad de zapatillas Puma con talle mayor a 40 vendidas: %d\n", zapatillasPumaMayor40);
    printf("Total recaudado: %d\n", totalRecaudado);
    printf("Venta más alta: %d (Cliente número: %d)\n", ventaMasAlta, clienteVentaMasAlta);
}

