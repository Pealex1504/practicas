#include <stdio.h>
// La funcion intercambia los valores de dos variables enteras usando punteros.
// El parametro a es puntero a la primera variable.
// El parametro b es puntero a la segunda variable.
void swap(int *a, int *b) {
	int temp = *a; // Se declara una variable entera temporal "temp" y se le asigna el valor al que apunta 'a'.
	*a = *b; // Se asigna el valor al que apunta 'b' al lugar de memoria al que apunta 'a'.
	*b = temp; // Se asigna el valor de la variable temporal "temp" al lugar de memoria al que apunta 'b'.
}
int longitudCadena ( char * cadena);
void invertirArreglo (int *arr , int size);
int cuentaPares (int *arr , int size);

void main(){

}
