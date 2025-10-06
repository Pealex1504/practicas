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
int cuentaPares (int *arr , int size);

void main(){

}
