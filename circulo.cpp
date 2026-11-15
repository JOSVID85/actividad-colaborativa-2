// Actividad Colaborativa 2 - Punteros complejos - Ejercicio 2
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

const double PI = 3.14159265358979; // Definición de la constante PI (no se modifica)

class Circulo { // Definición de la clase Circulo
private:
    double radio; // Variable privada que almacena el radio del círculo solo accesible desde la clase Circulo

public: // Sección pública de la clase Circulo, accesible desde fuera de la clase por ejempñlo, desde la función main.
    Circulo(double radio) { // Constructor que inicializa el radio del círculo
        this->radio = radio;
    }

    double area() const { // Método que calcula el área del círculo
        return PI * radio * radio;
    }

    double circunferencia() const { // Método que calcula la circunferencia del círculo
        return 2 * PI * radio;
    }
};

int main() {
    double radio; // Variable que almacena el radio del círculo en el stack

    std::cout << "Introduce el radio del circulo: "; // Solicitamos al usuario que introduzca el radio del círculo
    std::cin >> radio; //   Leemos el valor del radio desde la entrada estándar y lo almacenamos en la variable radio

    if (radio <= 0) { // Comprobamos si el radio es menor o igual a 0, en cuyo caso mostramos un mensaje de error y finalizamos el programa
        std::cout << "El radio debe ser mayor que 0.\n";
        return 1;
    }

    Circulo* circulo = new Circulo(radio); // Creamos un objeto Circulo en el heap y almacenamos su dirección de memoria en el puntero circulo

    std::cout << "Area: " << circulo->area() << "\n"; // Imprimimos el área del círculo utilizando el método area() del objeto Circulo al que apunta el puntero circulo
    std::cout << "Circunferencia: " << circulo->circunferencia() << "\n"; // Imprimimos la circunferencia del círculo utilizando el método circunferencia() del objeto Circulo al que apunta el puntero circulo

    delete circulo; // Liberamos la memoria reservada para el objeto Circulo en el heap
    circulo = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero circulo

    return 0;// Finalizamos la ejecución del programa
}
