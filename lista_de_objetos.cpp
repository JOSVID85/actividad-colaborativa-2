// Actividad Colaborativa 2 - Gestion de la memoria - Ejercicio 1
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

template <typename T> // Plantilla: T es un tipo comodín que se elige al crear la lista (Punto, int...)
class ListaDeObjetos { // Definición de la clase ListaDeObjetos
private: // Atributos privados, solo accesibles desde la clase ListaDeObjetos
    T* elementos;  // Puntero al array de objetos de tipo T reservado en el heap
    int cantidad;  // Número de elementos que hay guardados en el array
    int capacidad; // Número máximo de elementos que caben en el array

public: // Sección pública de la clase, accesible desde fuera de la clase, por ejemplo desde la función main
    ListaDeObjetos(int capacidad) { // Constructor que crea la lista con la capacidad indicada
        this->capacidad = capacidad; // this->capacidad es el atributo; capacidad es el parámetro
        cantidad = 0;                // La lista empieza vacía
        elementos = new T[capacidad]; // Reservamos memoria en el heap para el array de objetos
    }

    ~ListaDeObjetos() { // Destructor: se ejecuta automáticamente cuando la lista deja de existir
        delete[] elementos; // Liberamos la memoria reservada para el array (delete[] porque se reservó con new[])
    }

    bool agregar(const T& elemento) { // Método que agrega un elemento al final; lo recibe por referencia constante (sin copiarlo y sin modificarlo)
        if (cantidad == capacidad) { // Comprobamos si la lista está llena
            return false;            // Si lo está, no se puede agregar y devolvemos false
        }
        elementos[cantidad] = elemento; // Guardamos el elemento en la primera posición libre
        cantidad++;                     // Aumentamos el número de elementos guardados
        return true;                    // Devolvemos true porque se ha agregado correctamente
    }

    bool extraer(T& salida) { // Método que extrae el último elemento; lo devuelve a través de la referencia salida
        if (cantidad == 0) { // Comprobamos si la lista está vacía
            return false;    // Si lo está, no hay nada que extraer y devolvemos false
        }
        cantidad--;                   // Reducimos el número de elementos: el último deja de pertenecer a la lista
        salida = elementos[cantidad]; // Copiamos el último elemento en salida (que es la variable de quien llama)
        return true;                  // Devolvemos true porque se ha extraído correctamente
    }
};

class Punto { // Clase de ejemplo para comprobar que la lista funciona con objetos de cualquier clase
private: // Atributos privados, solo accesibles desde la clase Punto
    int x; // Coordenada x del punto
    int y; // Coordenada y del punto

public: // Sección pública de la clase Punto
    Punto(int x = 0, int y = 0) { // Constructor con valores por defecto (necesario para poder crear el array con new T[capacidad])
        this->x = x; // Guardamos el parámetro x en el atributo x
        this->y = y; // Guardamos el parámetro y en el atributo y
    }

    void mostrar() const { // Método const que muestra el punto por pantalla sin modificarlo
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    ListaDeObjetos<Punto> lista(3); // Creamos en el stack una lista de objetos Punto con capacidad para 3 elementos

    // Array con los 4 puntos que vamos a intentar agregar a una lista con capacidad para 3
    Punto puntos[4] = { Punto(1, 2), Punto(3, 4), Punto(5, 6), Punto(7, 8) };

    for (int i = 0; i < 4; i++) { // Recorremos el array e intentamos agregar cada punto
        if (lista.agregar(puntos[i])) { // agregar devuelve true si ha podido agregarlo
            std::cout << "Agregado: ";
        } else {                        // y false si la lista está llena
            std::cout << "No se puede agregar (lista llena): ";
        }
        puntos[i].mostrar(); // Imprimimos por pantalla el punto que hemos intentado agregar
        std::cout << "\n";
    }
    std::cout << "\n";

    Punto punto; // Variable en el stack donde se guardará cada punto extraído
    while (lista.extraer(punto)) { // Extraemos puntos mientras la lista no esté vacía (extraer devuelve true)
        std::cout << "Extraido: "; // Imprimimos por pantalla el punto extraído
        punto.mostrar();
        std::cout << "\n";
    }

    return 0; // Finalizamos la ejecución del programa; la lista se destruye y su destructor libera la memoria
}
