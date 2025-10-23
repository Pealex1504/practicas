#include <stdio.h> 
#include <stdlib.h> 

void main() { 
    float *calificaciones = NULL; // Puntero a float para almacenar las calificaciones dinámicamente.
    int total_calificaciones = 0; // Contador del número total de calificaciones ingresadas hasta el momento.
    int opcion = 0; // Variable para almacenar la opción del menú seleccionada por el usuario.
    int n_nuevas_calificaciones = 0; // Variable para almacenar cuántas calificaciones nuevas desea ingresar el usuario en una sesión.
    char respuesta_mas_calificaciones = 'n'; // Carácter para guardar la respuesta del usuario ('s'/'n') sobre si desea agregar más calificaciones.
    float cal_ingresada = 0.0; // Variable temporal para almacenar la calificación que se está ingresando.
    float suma = 0.0; // Variable para acumular la suma de todas las calificaciones ingresadas.
    float promedio = 0.0; // Variable para almacenar el promedio calculado.

    printf("=== Calculadora de Promedio Dinámica ===\n\n"); 

    while (opcion != 2) { 
        printf("1) Ingresar calificaciones\n"); 
        printf("2) Salir\n"); 
        printf("Seleccione una opcion: "); 

        // Validación de la entrada del menú principal.
        if (scanf("%i", &opcion) != 1 || (opcion != 1 && opcion != 2)) {
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu (1 o 2):\n"); 
            while (getchar() != '\n'); // Limpia el búfer de entrada para descartar caracteres no deseados.
            opcion = 0; // Restablece la opción a 0 para forzar la repetición del bucle.
            printf("\n"); // Salto de línea para formato.
            continue; // Salta al inicio de la siguiente iteración del bucle.
        }

        switch (opcion) {
            case 1:
                do { // Bucle: se repite si el usuario elige agregar "más" calificaciones ('s')
                    n_nuevas_calificaciones = 0; // Reinicia el contador de nuevas calificaciones para esta ronda

                    // Pide al usuario la cantidad de calificaciones a ingresar, ajustando el mensaje
                    printf("\n¿Cuántas calificaciones %s desea ingresar? ", (total_calificaciones == 0 ? "" : "más")); 

                    // Validación para asegurar que el usuario ingrese un número entero positivo para la cantidad.
                    while (scanf("%i", &n_nuevas_calificaciones) != 1 || n_nuevas_calificaciones <= 0) {
                        printf("=== Entrada inválida ===\nPor favor, ingrese un número entero positivo para la cantidad: "); 
                        while (getchar() != '\n'); 
                    }

                    int total_anterior = total_calificaciones; // Guarda el total anterior de calificaciones.
                    total_calificaciones += n_nuevas_calificaciones; // Actualiza el total de calificaciones.

                    float *temp = NULL; // Puntero temporal para una asignación de memoria segura.

                    if (total_anterior == 0) {
                        temp = (float *)malloc(total_calificaciones * sizeof(float)); // Primera asignación: usa malloc.
                    } else {
                        temp = (float *)realloc(calificaciones, total_calificaciones * sizeof(float)); // Reasignación: usa realloc para expandir.
                    }

                    if (temp == NULL) { // Comprueba si la asignación/reasignación de memoria falló.
                        printf("\n*** Error: No se pudo asignar/re-asignar memoria dinámica. Deteniendo ingreso. ***\n"); 
                        total_calificaciones = total_anterior; 
                        respuesta_mas_calificaciones = 'n'; 
                        continue; 
                    }

                    calificaciones = temp; // Si fue exitoso, el puntero principal apunta a la nueva memoria.

                    // Bucle para leer y almacenar cada una de las nuevas calificaciones.
                    for (int i = 0; i < n_nuevas_calificaciones; i++) {
                        do { // Bucle para la validación de la calificación (debe ser un número entre 0.0 y 10.0).
                            printf("Ingrese la calificación %i: ", total_anterior + i + 1); 
                            if (scanf("%f", &cal_ingresada) != 1) { 
                                printf("=== Entrada inválida ===\nPor favor, ingrese un número para la calificación.\n"); 
                                while (getchar() != '\n'); 
                                cal_ingresada = -1.0; // Asigna un valor inválido para forzar la repetición del bucle.
                            } else if (cal_ingresada < 0.0 || cal_ingresada > 10.0) { // Verifica el rango [0, 10].
                                printf("=== Calificación inválida ===\nLa calificación debe estar entre 0 y 10.\n"); 
                            }
                        } while (cal_ingresada < 0.0 || cal_ingresada > 10.0); // Repite hasta obtener una calificación válida.

                        // Almacena la calificación validada en la posición correcta del arreglo dinámico.
                        calificaciones[total_anterior + i] = cal_ingresada;
                    }

                    suma = 0.0; // Reinicia la suma para el recálculo.
                    // Bucle para calcular la suma de *todas* las calificaciones (incluyendo las nuevas).
                    for (int i = 0; i < total_calificaciones; i++) {
                        suma += calificaciones[i];
                    }
                    promedio = suma / total_calificaciones; 

                    printf("\nPromedio: %.2f\n", promedio); 
                    if (promedio >= 7.0) { 
                        printf("Estado: APROBADO\n"); 
                    } else {
                        printf("Estado: REPROBADO\n"); 
                    }

                    respuesta_mas_calificaciones = 'x'; // Inicializa la respuesta con un valor inválido.

                    do { // Bucle para pedir la respuesta sobre si desea agregar más calificaciones.
                        printf("¿Desea agregar más calificaciones? (s/n) ");
                        while (getchar() != '\n'); 
                                                
                        if (scanf(" %c", &respuesta_mas_calificaciones) != 1) { // Lee la respuesta. El espacio antes de %c consume cualquier espacio/salto de línea pendiente.
                            respuesta_mas_calificaciones = 'x'; // Si falla la lectura, la marca como inválida.
                        }

                        if (respuesta_mas_calificaciones >= 'A' && respuesta_mas_calificaciones <= 'Z') {
                            respuesta_mas_calificaciones += ('a' - 'A'); // Convierte la respuesta a minúscula (si se ingresó mayúscula).
                        }

                        if (respuesta_mas_calificaciones != 's' && respuesta_mas_calificaciones != 'n') {
                            printf("=== Respuesta inválida ===\nPor favor, ingrese estrictamente 's' o 'n'.\n"); // Mensaje de error si la respuesta no es 's' ni 'n'.
                        }
                    } while (respuesta_mas_calificaciones != 's' && respuesta_mas_calificaciones != 'n'); // Repite hasta obtener 's' o 'n'.

                } while (respuesta_mas_calificaciones == 's'); // Continúa el ingreso de calificaciones si la respuesta es 's'.

                break; // Sale del switch para el caso 1.

            case 2: 
                if (calificaciones != NULL) { // Comprueba si se asignó memoria dinámicamente
                    free(calificaciones); // Libera la memoria asignada al array de calificaciones
                    calificaciones = NULL; // Establece el puntero a NULL después de liberarlo 
                }
                
                printf("\n¡Memoria liberada! Hasta luego.\n"); 
                break; 
            
            default:
                break; 
        }
        printf("\n"); // Salto de línea después de cada ciclo del menú
    }
}