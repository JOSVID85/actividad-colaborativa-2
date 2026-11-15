// Actividad Colaborativa 2 - Punteros simples - Ejercicio 4
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

int main() {
    int tamano; // Variable para almacenar el tamaño del array de N elementos en el stack

    std::cout << "Introduce el tamano del array: "; // Solicitamos al usuario que introduzca el tamaño del array
    std::cin >> tamano; // Leemos el tamaño del array desde la entrada estándar

    if (tamano <= 0) { // Verificamos que el tamaño del array sea mayor que 0.
        std::cout << "El tamano debe ser mayor que 0.\n"; // Si no lo es, mostramos un mensaje de error y 
        // finalizamos la ejecución del programa
        return 1; // Finalizamos la ejecución del programa con un código de error
    }

    int* array = new int[tamano]; // Reservamos memoria para un array de enteros en el heap

    for (int i = 0; i < tamano; i++) { // Iteramos sobre el array para solicitar al usuario que introduzca los valores de cada elemento
        std::cout << "Valor del elemento " << i << ": "; // Solicitamos al usuario que introduzca el valor del elemento i
        std::cin >> array[i]; // Leemos el valor del elemento i desde la entrada estándar y lo almacenamos en el array
    }

    int* suma = new int(0);// Reservamos memoria para un entero en el heap y lo inicializamos a 0 para almacenar la suma de los elementos del array

    for (int i = 0; i < tamano; i++) {// Iteramos sobre el array para calcular la suma de sus elementos
        *suma += array[i]; // Sumamos el valor del elemento i al valor almacenado en la dirección de memoria a la que apunta el puntero
    }

    std::cout << "La suma de los elementos es: " << *suma << "\n"; // Imprimimos el resultado de la suma desreferenciando el puntero
    std::cout << "Guardada en la direccion: " << suma << "\n"; // Imprimimos la dirección de memoria donde se encuentra la suma

    delete[] array; // Liberamos la memoria reservada para el array de enteros en el heap
    delete suma; // Liberamos la memoria reservada para el entero en el heap
    array = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero
    suma = nullptr;

    return 0; // Finalizamos la ejecución del programa
}
