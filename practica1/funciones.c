#include <stdio.h>
// La funcion intercambia los valores de dos variables enteras usando punteros.
// El parametro a es puntero a la primera variable.
// El parametro b es puntero a la segunda variable.
void swap(int *a, int *b) {
	int temp = *a; // Se declara una variable entera temporal "temp" y se le asigna el valor al que apunta 'a'.
	*a = *b; // Se asigna el valor al que apunta 'b' al lugar de memoria al que apunta 'a'.
	*b = temp; // Se asigna el valor de la variable temporal "temp" al lugar de memoria al que apunta 'b'.
}
// La funcion calcula la longitud de una cadena de caracteres.
// El parametro cadena es puntero a la cadena de caracteres.
// Retorna la longitud de la cadena.
int longitudCadena(char *cadena) {
	int tamano = 0; // Se declara una variable entera "tamano" y se inicializa en 0.
	while (*cadena != '\0') { // Se itera a traves de la cadena hasta encontrar el caracter nulo ('\0').
		tamano++;// Se incrementa el contador de tamano.
		cadena++;// Se avanza el puntero al siguiente caracter.
	}
	return tamano; // Retorna el valor final de la longitud de la cadena.
}
//La funcion invierte el orden de un arreglo de enteros.
//El parametro  arr es puntero al inicio del arreglo.
//El parametro size es el tamano del arreglo.
void invertirArreglo(int *arr, int size) {
	int *inicio = arr; // Declara un puntero "inicio" y lo asigna al primer elemento del arreglo.
	int *fin = arr + size - 1; // Declara un puntero "fin" y lo asigna al ultimo elemento del arreglo.
	while (inicio < fin) { // El bucle se ejecuta mientras el puntero "inicio" sea menor que el puntero "fin".
		int temp = *inicio; // Declara una variable entera temporal "temp" y le asigna el valor del elemento de 'inicio'.
		*inicio = *fin; // Se asigna el valor del elemento de 'fin' al lugar de memoria de 'inicio'.
		*fin = temp; // Se asigna el valor de la variable temporal "temp" al lugar de memoria de 'fin'.
		inicio++; // El puntero 'inicio' se mueve hacia adelante.
		fin--; // El puntero 'fin' se mueve hacia atras.
	}
}
// La funcion cuenta la cantidad de numeros pares en un arreglo de enteros.
// El parametro arr es puntero al inicio del arreglo.
// El parametro size es el tamano del arreglo.
// Retorna la cantidad de numeros pares.
int cuentaPares(int *arr, int size) {
	int conteo = 0; // Se declara e inicializa el contador de pares en 0.
	for (int i = 0; i < size; i++) { // Bucle for para iterar a traves de cada elemento del arreglo.
		if (*(arr + i) % 2 == 0) { // Se verifica si el elemento actual es par.
			conteo++; // Si es par, se incrementa el contador.
		}
	}
	return conteo; // Retorna el numero total de pares encontrados.
}
// Funcion principal del programa.
void main() {
    // Prueba de la funcion swap
	printf("Prueba de la funcion swap\n");
	int a = 5, b = 10;
	printf("Valores iniciales: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("Valores despues de swap: a = %d, b = %d\n", a, b);
	
    // Prueba de la funcion swap con valores que pueden ser problematicos
    printf("\nPrueba de la funcion swap con valores problematicos\n");
    int a2 = '\0', b2 = 1;
    printf("Valores iniciales: a = %d, b = %d\n", a2, b2);
    swap(&a2, &b2);
    printf("Valores despues de swap: a = %d, b = %d\n", a2, b2);

    // Prueba de la funcion longitudCadena
	printf("\nPrueba de la funcion longitudCadena\n");
	char cadena[] = "Esto es una prueba";
	int longitud = longitudCadena(cadena);
	printf("La longitud de la cadena '%s' es: %d\n", cadena, longitud);
	
	// Prueba de la funcion longitudCadena con cadena vacia
    printf("\nPrueba de la funcion longitudCadena con cadena vacia\n");
    char cadena_vacia[] = "";
    int longitud_vacia = longitudCadena(cadena_vacia);
    printf("La longitud de la cadena '%s' es: %d\n", cadena_vacia, longitud_vacia);

    // Prueba de la funcion invertirArreglo
	printf("\nPrueba de la funcion invertirArreglo\n");
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Arreglo original: {1, 2, 3, 4, 5}\n");
	invertirArreglo(arr, size);
	printf("Arreglo invertido: {");
	for (int i = 0; i < size; i++) {
		printf("%d%s", arr[i], (i < size - 1) ? ", " : "");
	}
	printf("}\n");
	
	// Prueba de la funcion invertirArreglo con arreglo vacio
    printf("\nPrueba de la funcion invertirArreglo con arreglo vacio\n");
    int arr_vacio[] = {};
    int size_vacio = 0;
    printf("Arreglo original: {}\n");
    invertirArreglo(arr_vacio, size_vacio);
    printf("Arreglo invertido: {}\n");

    // Prueba de la funcion invertirArreglo con un solo elemento
    printf("\nPrueba de la funcion invertirArreglo con un solo elemento\n");
    int arr_uno[] = {99};
    int size_uno = 1;
    printf("Arreglo original: {99}\n");
    invertirArreglo(arr_uno, size_uno);
    printf("Arreglo invertido: {%d}\n", arr_uno[0]);

    // Prueba de la funcion cuentaPares
	printf("\nrueba de la funcion cuentaPares\n");
	int arrPares[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sizePares = sizeof(arrPares) / sizeof(arrPares[0]);
	int numPares = cuentaPares(arrPares, sizePares);
	printf("El arreglo {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} tiene %d numeros pares.\n", numPares);
	
	// Prueba de la funcion cuentaPares sin pares
    printf("\nPrueba de la funcion cuentaPares con arreglo sin pares\n");
    int arr_impares[] = {1, 3, 5, 7, 9};
    int size_impares = sizeof(arr_impares) / sizeof(arr_impares[0]);
    int num_pares_impares = cuentaPares(arr_impares, size_impares);
    printf("El arreglo {1, 3, 5, 7, 9} tiene %d numeros pares.\n", num_pares_impares);
}