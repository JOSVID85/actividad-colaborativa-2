// Actividad Colaborativa 2 - Punteros simples - Ejercicio 3
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

int main() {
    int* puntero = new int; // Reservamos memoria para un entero en el heap y guardamos la dirección en un puntero
    int valor1; // Variable para almacenar el primer valor en el stack
    int valor2; // Variable para almacenar el segundo valor en el stack

    std::cout << "Introduce el primer valor: ";// Solicitamos al usuario que introduzca el primer valor
    std::cin >> valor1;// Leemos el primer valor desde la entrada estándar
    std::cout << "Introduce el segundo valor: ";// Solicitamos al usuario que introduzca el segundo valor
    std::cin >> valor2; // Leemos el segundo valor desde la entrada estándar

    *puntero = valor1 + valor2; // Calculamos la suma de los dos valores y almacenamos el 
    // resultado en la dirección de memoria a la que apunta el puntero

    std::cout << "Resultado de la suma: " << *puntero << "\n"; // Imprimimos el resultado de la suma desreferenciando el puntero
    std::cout << "Guardado en la direccion: " << puntero << "\n"; // Imprimimos la dirección de memoria donde se encuentra el resultado de la suma

    delete puntero; // Liberamos la memoria reservada para el entero en el heap
    puntero = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero

    return 0; // Finalizamos la ejecución del programa
}
