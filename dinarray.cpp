// Actividad Colaborativa 2 - Tecnicas RAII - Ejercicio 3
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>
#include <string> // Librería para usar std::string (texto) en el TAD Producto

template <typename T> // Plantilla: T es un tipo comodín, así Dinarray puede almacenar elementos de cualquier tipo
class Dinarray { // Definición de la clase genérica Dinarray (array dinámico)
private: // Atributos privados, solo accesibles desde la clase Dinarray
    T* elementos; // Puntero al array de elementos de tipo T reservado en el heap
    int tamano;   // Número de elementos que caben en el array

public: // Sección pública de la clase Dinarray, accesible desde fuera de la clase, por ejemplo desde la función main
    Dinarray(int tamano) { // Constructor: aloja los elementos en el heap (adquiere el recurso)
        this->tamano = tamano;         // this->tamano es el atributo; tamano es el parámetro
        elementos = new T[tamano];     // Reservamos memoria en el heap para el array; new ejecuta el constructor de cada elemento
        std::cout << "Constructor: alojados " << tamano << " elementos\n"; // Imprimimos por pantalla que se ha reservado la memoria
    }

    ~Dinarray() { // Destructor: se ejecuta automáticamente cuando el Dinarray deja de existir y libera los elementos (libera el recurso)
        delete[] elementos; // Liberamos la memoria del array (delete[] porque se reservó con new[])
        std::cout << "Destructor: liberados " << tamano << " elementos\n"; // Imprimimos por pantalla que se ha liberado la memoria
    }

    T& elemento(int indice) { // Método que devuelve por referencia el elemento de la posición indicada, para poder leerlo o modificarlo
        return elementos[indice];
    }
};

// ---------- TAD 1: Punto ----------
class Punto { // Tipo abstracto de datos que representa un punto en el plano
private: // Atributos privados, solo accesibles desde la clase Punto
    int x; // Coordenada x del punto
    int y; // Coordenada y del punto

public: // Sección pública de la clase Punto
    Punto(int x = 0, int y = 0) { // Constructor con valores por defecto (necesario para poder crear el array con new T[tamano])
        this->x = x; // Guardamos el parámetro x en el atributo x
        this->y = y; // Guardamos el parámetro y en el atributo y
    }

    void mostrar() const { // Método const que muestra el punto por pantalla sin modificarlo
        std::cout << "(" << x << ", " << y << ")";
    }
};

// ---------- TAD 2: Fecha ----------
class Fecha { // Tipo abstracto de datos que representa una fecha
private: // Atributos privados, solo accesibles desde la clase Fecha
    int dia;  // Día de la fecha
    int mes;  // Mes de la fecha
    int anio; // Año de la fecha

public: // Sección pública de la clase Fecha
    Fecha(int dia = 1, int mes = 1, int anio = 2000) { // Constructor con valores por defecto (necesario para new T[tamano])
        this->dia = dia;   // Guardamos el parámetro dia en el atributo dia
        this->mes = mes;   // Guardamos el parámetro mes en el atributo mes
        this->anio = anio; // Guardamos el parámetro anio en el atributo anio
    }

    void mostrar() const { // Método const que muestra la fecha por pantalla en formato dia/mes/anio
        std::cout << dia << "/" << mes << "/" << anio;
    }
};

// ---------- TAD 3: Producto ----------
class Producto { // Tipo abstracto de datos que representa un producto con nombre y precio
private: // Atributos privados, solo accesibles desde la clase Producto
    std::string nombre; // Nombre del producto
    double precio;      // Precio del producto en euros

public: // Sección pública de la clase Producto
    Producto(const std::string& nombre = "", double precio = 0) { // Constructor con valores por defecto (necesario para new T[tamano])
        this->nombre = nombre; // Guardamos el parámetro nombre en el atributo nombre
        this->precio = precio; // Guardamos el parámetro precio en el atributo precio
    }

    void mostrar() const { // Método const que muestra el producto por pantalla
        std::cout << nombre << " (" << precio << " euros)";
    }
};

int main() {
    // Creamos en el stack tres contenedores Dinarray, cada uno para un TAD diferente.
    // Cada constructor aloja sus elementos en el heap.
    Dinarray<Punto> puntos(3);       // Contenedor de 3 puntos
    Dinarray<Fecha> fechas(2);       // Contenedor de 2 fechas
    Dinarray<Producto> productos(4); // Contenedor de 4 productos

    puntos.elemento(0) = Punto(1, 2); // Guardamos un punto en cada posición del contenedor de puntos
    puntos.elemento(1) = Punto(3, 4);
    puntos.elemento(2) = Punto(5, 6);

    fechas.elemento(0) = Fecha(12, 10, 1492); // Guardamos una fecha en cada posición del contenedor de fechas
    fechas.elemento(1) = Fecha(20, 7, 1969);

    productos.elemento(0) = Producto("Teclado", 25.5); // Guardamos un producto en cada posición del contenedor de productos
    productos.elemento(1) = Producto("Raton", 12.99);
    productos.elemento(2) = Producto("Monitor", 149.9);
    productos.elemento(3) = Producto("Altavoces", 30);

    std::cout << "\nPuntos: "; // Recorremos cada contenedor y mostramos sus elementos por pantalla
    for (int i = 0; i < 3; i++) {
        puntos.elemento(i).mostrar();
        std::cout << " ";
    }

    std::cout << "\nFechas: ";
    for (int i = 0; i < 2; i++) {
        fechas.elemento(i).mostrar();
        std::cout << " ";
    }

    std::cout << "\nProductos: ";
    for (int i = 0; i < 4; i++) {
        productos.elemento(i).mostrar();
        std::cout << " ";
    }
    std::cout << "\n\n";

    // Finalizamos la ejecución del programa. Al cerrar main, los tres contenedores se destruyen solos
    // en orden inverso al de creación (productos, fechas y puntos) y sus destructores liberan la memoria.
    return 0;
}
