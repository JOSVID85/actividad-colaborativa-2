// Actividad Colaborativa 2 - Punteros complejos - Ejercicio 1
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

class Rectangulo { // Definición de la clase Rectangulo
private:            // Variables privadas en el stack que almacenan la longitud y el ancho del rectángulo, solo accesibles desde la clase Rectangulo
    double longitud;
    double ancho;

public:
    Rectangulo(double longitud, double ancho) { // Constructor que inicializa las variables privadas con los valores proporcionados
        this->longitud = longitud; 
        this->ancho = ancho;
    }

    double area() const { // metodo que calcula el área del rectángulo
        return longitud * ancho; // Retorna el área del rectángulo calculada como longitud * ancho
    }

    double perimetro() const { // metodo que calcula el perímetro del rectángulo
        return 2 * (longitud + ancho); // Retorna el perímetro del rectángulo calculado como 2 * (longitud + ancho)
    }
};

int main() {
    double largo; // Variable que almacena la longitud del rectángulo en el stack
    double ancho; // Variable que almacena el ancho del rectángulo en el stack

    std::cout << "Introduce el largo del rectangulo: "; // Solicitamos al usuario que introduzca la longitud del rectángulo
    std::cin >> largo; // Leemos el valor de la longitud desde la entrada estándar y lo almacenamos en la variable largo
    std::cout << "Introduce el ancho del rectangulo: ";
    std::cin >> ancho;

    if (largo <= 0 || ancho <= 0) { // Comprobamos si la longitud o el ancho son menores o iguales a 0, en cuyo caso mostramos un mensaje de error y finalizamos el programa
        std::cout << "El largo y el ancho deben ser mayores que 0.\n";
        return 1;
    }

    Rectangulo* rectangulo = new Rectangulo(largo, ancho); // Creamos un objeto Rectangulo en el heap y almacenamos su dirección de memoria en el puntero rectangulo

    std::cout << "Area: " << rectangulo->area() << "\n"; // Imprimimos el área del rectángulo utilizando el método area() del objeto Rectangulo al que apunta el puntero rectangulo
    std::cout << "Perimetro: " << rectangulo->perimetro() << "\n"; // Imprimimos el perímetro del rectángulo utilizando el método perimetro() del objeto Rectangulo al que apunta el puntero rectangulo

    delete rectangulo; // Liberamos la memoria reservada para el objeto Rectangulo en el heap
    rectangulo = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero rectangulo

    return 0; // Finalizamos la ejecución del programa
}
