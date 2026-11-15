// Actividad Colaborativa 2 - Gestion de la memoria - Ejercicio 2
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

template <typename T> // Template "T" es un tipo comodín que se elige al crear la lista que acepta distintos tipos (Punto, int...)
class ListaDePunteros { // Definición de la clase ListaDePunteros
private: // Atributos privados, solo accesibles desde la clase ListaDePunteros
    T** elementos; // Puntero a puntero: apunta a un array del heap en el que cada posición es un puntero a un objeto de tipo T
    int cantidad;  // Número de punteros que hay guardados en el array
    int capacidad; // Número máximo de punteros que caben en el array

public: // Sección pública de la clase, accesible desde fuera de la clase, por ejemplo desde la función main
    ListaDePunteros(int capacidad) { // Constructor que crea la lista con la capacidad indicada
        this->capacidad = capacidad;   // this->capacidad es el atributo; capacidad es el parámetro
        cantidad = 0;                  // La lista empieza vacía
        elementos = new T*[capacidad]; // Reservamos memoria en el heap para el array de punteros (no para los objetos)
    }

    ~ListaDePunteros() { // Destructor: se ejecuta automáticamente cuando la lista deja de existir
        for (int i = 0; i < cantidad; i++) { // Recorremos los punteros que siguen guardados en la lista
            delete elementos[i];             // Liberamos cada objeto al que apuntan, porque la lista es su dueña
        }
        delete[] elementos; // Después liberamos el array de punteros (primero los objetos, si no perderíamos sus direcciones)
    }

    bool agregar(T* elemento) { // Metodo que agrega al final el puntero a un objeto creado con new
        if (cantidad == capacidad) { // Comprobamos si la lista está llena
            return false;            // Si lo está, no se puede agregar y devolvemos false
        }
        elementos[cantidad] = elemento; // Guardamos la dirección del objeto en la primera posición libre (el objeto no se copia)
        cantidad++;                     // Aumentamos el número de punteros guardados
        return true;                    // Devolvemos true porque se ha agregado correctamente
    }

    T* extraer() { // Método que extrae el último puntero de la lista y lo devuelve
        if (cantidad == 0) { // Comprobamos si la lista está vacía
            return nullptr;  // Si lo está, devolvemos nullptr para indicar que no hay nada que extraer
        }
        cantidad--;                  // Reducimos el número de punteros: el último deja de pertenecer a la lista
        return elementos[cantidad]; // Devolvemos el puntero; a partir de ahora quien lo extrae debe liberar el objeto
    }
};

class Punto { // Clase de ejemplo para comprobar que la lista funciona con punteros a objetos de cualquier clase
private: // Atributos privados, solo accesibles desde la clase Punto
    int x; // Coordenada x del punto
    int y; // Coordenada y del punto

public: // Sección pública de la clase Punto
    Punto(int x, int y) { // Constructor que inicializa las coordenadas del punto
        this->x = x; // Guardamos el parámetro x en el atributo x
        this->y = y; // Guardamos el parámetro y en el atributo y
    }

    void mostrar() const { // Método const que muestra el punto por pantalla sin modificarlo
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    ListaDePunteros<Punto> lista(3); // Creamos en el stack una lista de punteros a Punto con capacidad para 3 elementos

    lista.agregar(new Punto(1, 2)); // Creamos el punto (1, 2) en el heap y agregamos su dirección a la lista
    lista.agregar(new Punto(3, 4)); // Creamos el punto (3, 4) en el heap y agregamos su dirección a la lista
    lista.agregar(new Punto(5, 6)); // Creamos el punto (5, 6) en el heap y agregamos su dirección a la lista

    Punto* punto = lista.extraer(); // Extraemos el primer puntero de la lista (el último que se agregó)
    while (punto != nullptr) { // Repetimos mientras la lista devuelva un puntero válido (no esté vacía)
        std::cout << "Extraido: ";
        punto->mostrar(); // Mostramos el punto usando el operador -> porque punto es un puntero
        std::cout << "\n";
        delete punto;            // Liberamos el objeto extraído: ya no pertenece a la lista, así que lo liberamos nosotros
        punto = lista.extraer(); // Extraemos el siguiente puntero
    }

    

    return 0; // Finalizamos la ejecución del programa; la lista se destruye y su destructor libera la memoria que quede
}
