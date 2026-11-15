// Actividad Colaborativa 2 - Punteros simples - Ejercicio 5
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

int main() {
    int* a = new int;// Reservamos memoria para un entero en el heap
    int* b = new int; // Reservamos memoria para un entero en el heap

    std::cout << "Introduce el primer valor: "; // Solicitamos al usuario que introduzca el primer valor
    std::cin >> *a; // Leemos el primer valor desde la entrada estándar y lo almacenamos en la dirección de memoria a la que apunta el puntero a
    std::cout << "Introduce el segundo valor: "; // Solicitamos al usuario que introduzca el segundo valor
    std::cin >> *b; // Leemos el segundo valor desde la entrada estándar y lo almacenamos en la dirección de memoria a la que apunta el puntero b

    std::cout << "Antes del intercambio:   a = " << *a << ", b = " << *b << "\n"; // Imprimimos los valores de a y b antes del intercambio

    int temporal = *a; // Creamos una variable temporal en el stackl para almacenar el valor de a antes del intercambio
    *a = *b;  // Guardamos en la dirección a la que apunta a el valor al que apunta b
    *b = temporal; // Asignamos el valor almacenado en la variable temporal a 
    //la dirección de memoria a la que apunta el puntero b

    std::cout << "Despues del intercambio: a = " << *a << ", b = " << *b << "\n"; // Imprimimos los valores de a y b después del intercambio

    delete a; // Liberamos la memoria reservada para el entero en el heap
    delete b; // Liberamos la memoria reservada para el entero en el heap
    a = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero
    b = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero

return 0; // Finalizamos la ejecución del programa
}
