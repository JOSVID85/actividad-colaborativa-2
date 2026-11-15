// Actividad Colaborativa 2 - Punteros simples - Ejercicio 1
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

int main() {
    int* puntero = new int; // creamos un puntero que apunta la memoria reservada para un entero
    *puntero = 25; //asignamos un valor a dicho entero a través del puntero (desreferenciando el puntero)

    std::cout << "Valor del entero: " << *puntero << "\n"; //sacamos por pantalla el 
                                                            //valor de la variable a la que apunta el puntero desreferenciado
    std::cout << "Direccion a la que apunta el puntero: " << puntero << "\n"; //imprimimos por pantalla la dirección de memoria 
   // donde reside el valor en el heap

    delete puntero; //liberamos la memoria
    puntero = nullptr; // el puntero ya no apunta a memoria liberada (evitamos un puntero colgante)

    return 0;
}
