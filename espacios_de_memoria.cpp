// Actividad Colaborativa 2 - Tecnicas RAII - Ejercicio 2
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

template <typename T> // Plantilla: T es el tipo del elemento concreto para el que se reservan los bloques (int, double...)
class EspaciosDeMemoria { // Definición de la clase EspaciosDeMemoria
private: // Atributos privados, solo accesibles desde la clase EspaciosDeMemoria
    char* memoria;    // Puntero a la memoria reservada en el heap (la dirección la decide el sistema, por eso es "aleatoria")
    char* inicio;     // Puntero a la primera dirección alineada dentro de esa memoria, donde empieza el primer bloque
    int tamanoBloque; // Tamaño en bytes de cada bloque, redondeado a un múltiplo de la alineación

public: // Sección pública de la clase, accesible desde fuera de la clase, por ejemplo desde la función main
    EspaciosDeMemoria(int numBloques, int alineacion) { // Constructor: recibe el número de bloques y su alineación, y aloja la memoria (adquiere el recurso)
        // Redondeamos el tamaño del elemento (sizeof(T)) hacia arriba al siguiente múltiplo de la alineación,
        // para que si el primer bloque está alineado, todos los siguientes también lo estén
        tamanoBloque = ((sizeof(T) + alineacion - 1) / alineacion) * alineacion;

        // Reservamos memoria en el heap para todos los bloques más un margen de "alineacion" bytes,
        // porque la dirección que devuelve new puede no estar alineada y tendremos que avanzar hasta una que sí lo esté
        memoria = new char[numBloques * tamanoBloque + alineacion];

        unsigned long long direccion = reinterpret_cast<unsigned long long>(memoria); // Convertimos la dirección en un número para poder hacer cálculos con ella
        unsigned long long alineada = ((direccion + alineacion - 1) / alineacion) * alineacion; // Redondeamos la dirección hacia arriba al siguiente múltiplo de la alineación
        inicio = reinterpret_cast<char*>(alineada); // Convertimos el número de nuevo en un puntero: aquí empieza el primer bloque alineado

        std::cout << "Constructor: reservados " << numBloques << " bloques de "
                  << tamanoBloque << " bytes alineados a " << alineacion << "\n"; // Imprimimos por pantalla que se ha reservado la memoria
    }

    ~EspaciosDeMemoria() { // Destructor: se ejecuta automáticamente cuando el objeto deja de existir y libera la memoria (libera el recurso)
        delete[] memoria; // Liberamos la memoria reservada (la original de new, no la alineada; delete[] porque se reservó con new[])
        std::cout << "Destructor: memoria liberada\n"; // Imprimimos por pantalla que se ha liberado la memoria
    }

    T* bloque(int indice) { // Método que devuelve un puntero al bloque indicado, para poder guardar en él un elemento de tipo T
        return reinterpret_cast<T*>(inicio + indice * tamanoBloque); // Avanzamos desde el inicio tantos bloques como indique el índice
    }
};

int main() {
    EspaciosDeMemoria<int> espacios(4, 64); // Creamos en el stack 4 bloques para enteros alineados a 64 bytes; el constructor aloja la memoria

    for (int i = 0; i < 4; i++) { // Recorremos los 4 bloques
        int* bloque = espacios.bloque(i); // Obtenemos un puntero al bloque i
        *bloque = (i + 1) * 100;          // Guardamos un valor en el bloque desreferenciando el puntero

        unsigned long long direccion = reinterpret_cast<unsigned long long>(bloque); // Convertimos la dirección del bloque en un número
        // Imprimimos el valor, la dirección y el resto de dividir la dirección entre 64:
        // si el resto es 0, la dirección es múltiplo de 64, es decir, el bloque está alineado
        std::cout << "Bloque " << i << ": valor " << *bloque << ", direccion " << bloque
                  << " (direccion % 64 = " << direccion % 64 << ")\n";
    }

    // Finalizamos la ejecución del programa. Al cerrar main, espacios se destruye solo y su destructor libera la memoria.
    // No hacemos delete de los punteros bloque: no se reservaron con new, la memoria pertenece a espacios.
    return 0;
}
