// Actividad Colaborativa 2 - Gestion de la memoria - Ejercicio 4 (con extra: tamano dinamico)
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

template <typename T> // Plantilla: T es un tipo comodín que se elige al crear la cola (int, char, Punto...)
class Cola { // Definición de la clase Cola: el primer elemento que entra es el primero que sale
private: // Atributos privados, solo accesibles desde la clase Cola
    T* elementos;  // Puntero al array de elementos de tipo T reservado en el heap
    int cantidad;  // Número de elementos que hay en la cola
    int capacidad; // Número máximo de elementos que caben en el array

    void redimensionar(int nuevaCapacidad) { // Método privado: cambia el tamaño del array (sirve para ampliar y para encoger)
        T* nuevo = new T[nuevaCapacidad];        // Reservamos memoria en el heap para un array con la nueva capacidad
        for (int i = 0; i < cantidad; i++) {     // Recorremos los elementos que hay en la cola
            nuevo[i] = elementos[i];             // Copiamos cada elemento del array viejo al nuevo
        }
        delete[] elementos;         // Liberamos la memoria del array viejo
        elementos = nuevo;          // El puntero elementos pasa a apuntar al array nuevo
        capacidad = nuevaCapacidad; // Actualizamos la capacidad
    }

public: // Sección pública de la clase Cola, accesible desde fuera de la clase, por ejemplo desde la función main
    Cola(int capacidad) { // Constructor que crea la cola con la capacidad inicial indicada
        this->capacidad = capacidad;  // this->capacidad es el atributo; capacidad es el parámetro
        cantidad = 0;                 // La cola empieza vacía
        elementos = new T[capacidad]; // Reservamos memoria en el heap para el array de elementos
    }

    ~Cola() { // Destructor: se ejecuta automáticamente cuando la cola deja de existir
        delete[] elementos; // Liberamos la memoria reservada para el array (delete[] porque se reservó con new[])
    }

    void agregar(const T& elemento) { // Método que agrega un elemento al final de la cola; lo recibe por referencia constante (sin copiarlo y sin modificarlo)
        if (cantidad == capacidad) {         // Comprobamos si la cola está llena
            redimensionar(capacidad * 2);    // Si lo está, duplicamos el tamaño del array: por eso agregar nunca falla y devuelve void
        }
        elementos[cantidad] = elemento; // Guardamos el elemento al final, en la primera posición libre
        cantidad++;                     // Aumentamos el número de elementos de la cola
    }

    bool quitar(T& salida) { // Método que quita el primer elemento de la cola; lo devuelve a través de la referencia salida
        if (cantidad == 0) { // Comprobamos si la cola está vacía
            return false;    // Si lo está, no hay nada que quitar y devolvemos false
        }
        salida = elementos[0]; // Copiamos el primer elemento (el que lleva más tiempo en la cola) en salida
        for (int i = 1; i < cantidad; i++) {  // Recorremos el resto de elementos
            elementos[i - 1] = elementos[i];  // Desplazamos cada elemento una posición hacia delante
        }
        cantidad--;  // Reducimos el número de elementos de la cola

        // Si la cola baja a un cuarto de su capacidad, reducimos el array a la mitad para liberar memoria.
        // Se encoge al llegar a un cuarto (y no a la mitad) para que, si se alterna agregar y quitar,
        // la cola no esté ampliándose y encogiéndose continuamente.
        if (cantidad > 0 && cantidad == capacidad / 4) {
            redimensionar(capacidad / 2);
        }
        return true; // Devolvemos true porque se ha quitado correctamente
    }

    int getCapacidad() const { // Getter: método const que devuelve la capacidad actual del array
        return capacidad;
    }
};

int main() {
    Cola<int> cola(2); // Creamos en el stack una cola de enteros con capacidad inicial para 2 elementos

    for (int i = 1; i <= 5; i++) { // Agregamos 5 elementos: 10, 20, 30, 40 y 50
        cola.agregar(i * 10);      // Al agregar el 30 y el 50 la cola está llena y se amplía sola (de 2 a 4 y de 4 a 8)
        std::cout << "Agregado: " << i * 10 << "  (capacidad " << cola.getCapacidad() << ")\n"; // Imprimimos el elemento agregado y la capacidad actual
    }

    int valor; // Variable en el stack donde se guardará cada elemento quitado
    while (cola.quitar(valor)) { // Quitamos elementos mientras la cola no esté vacía (quitar devuelve true)
        // Imprimimos el elemento quitado (salen en el mismo orden en que entraron) y la capacidad actual
        std::cout << "Quitado: " << valor << "   (capacidad " << cola.getCapacidad() << ")\n";
    }

    return 0; // Finalizamos la ejecución del programa; la cola se destruye y su destructor libera la memoria
}
