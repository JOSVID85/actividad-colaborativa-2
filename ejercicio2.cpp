// Actividad Colaborativa 2 - Punteros simples - Ejercicio 2
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

int main() {
    int* puntero = new int; // creamos un puntero que apunta la memoria reservada para un entero en el heap.

    std::cout << "Introduce un numero entero: ";//pedimos al usuario que introduzca un valor para el entero al que apunta el puntero
    std::cin >> *puntero; //leemos el valor introducido por el usuario y lo almacenamos en la dirección de memoria a la que apunta el puntero

    std::cout << "Valor del entero: " << *puntero << "\n"; //Imprimimos por pantalla el valor del entero al que apunta el puntero desreferenciado
    std::cout << "Direccion a la que apunta el puntero: " << puntero << "\n"; //Imprimimos por pantalla la dirección de memoria donde reside el valor

    delete puntero; //liberamos la memoria reservada para el entero en el heap
    puntero = nullptr;//el puntero ya no apunta a memoria liberada (evitamos un puntero colgante).

    return 0;// finalizamos la ejecución del programa
}
