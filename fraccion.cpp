// Actividad Colaborativa 2 - Punteros complejos - Ejercicio 3
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

class Fraccion { // Definicion de la clase Fraccion
private: // Atributos privados: solo accesibles desde dentro de la clase Fraccion
    int numerador;   // Numero de arriba de la fraccion
    int denominador; // Numero de abajo de la fraccion (nunca vale 0 y siempre es positivo)

public: // Seccion publica accesible desde fuera de la clase, por ejemplo desde main
    Fraccion(int numerador, int denominador) { // Constructor que inicializa la fraccion
        if (denominador == 0) { // Una fraccion no puede tener denominador 0 (seria dividir entre cero)
            std::cout << "Error: el denominador no puede ser 0. Se usa 1.\n";
            denominador = 1; // Usamos 1 para que la fraccion sea valida
        }
        // Cambiar el signo arriba y abajo no cambia el valor de la fraccion (1/-2 = -1/2),
        // pero asi el signo negativo siempre queda en el numerador
        if (denominador < 0) {
            numerador = -numerador;     // Cambiamos el signo del numerador
            denominador = -denominador; // Cambiamos el signo del denominador (queda positivo)
        }
        this->numerador = numerador;     // this->numerador es el atributo; numerador es el parametro
        this->denominador = denominador; // Guardamos el denominador ya comprobado en el atributo
    }

    // Los cuatro metodos siguientes operan esta fraccion con otra y devuelven una NUEVA fraccion con el resultado.
    //  - otra: nombre del parametro; es la fraccion que se pasa entre parentesis (en main, f2).
    //  - & (referencia): otra es un alias de la fraccion original, no una copia (no se gasta memoria en copiarla).
    //  - const en el parametro: dentro del metodo no se puede modificar otra, solo leerla.
    //  - const al final: el metodo tampoco modifica esta fraccion (f1), solo calcula.
    //  - numerador y denominador son los de esta fraccion; otra.numerador y otra.denominador, los de la otra.
    //    Se usa punto (otra.) porque otra es un objeto, no un puntero.

    Fraccion sumar(const Fraccion& otra) const { // a/b + c/d = (a*d + c*b) / (b*d)
        return Fraccion(numerador * otra.denominador + otra.numerador * denominador,
                        denominador * otra.denominador);
    }

    Fraccion restar(const Fraccion& otra) const { // a/b - c/d = (a*d - c*b) / (b*d)
        return Fraccion(numerador * otra.denominador - otra.numerador * denominador,
                        denominador * otra.denominador);
    }

    Fraccion multiplicar(const Fraccion& otra) const { // a/b * c/d = (a*c) / (b*d)
        return Fraccion(numerador * otra.numerador, denominador * otra.denominador);
    }

    // a/b / c/d = (a*d) / (b*c), multiplicando en cruz.
    // Si la otra fraccion vale 0, el denominador del resultado seria 0 y el constructor lo corrige.
    Fraccion dividir(const Fraccion& otra) const {
        return Fraccion(numerador * otra.denominador, denominador * otra.numerador);
    }

    void mostrar() const { // Metodo const que muestra la fraccion por pantalla en formato numerador/denominador
        std::cout << numerador << "/" << denominador;
    }
};

int main() {
    int num1, den1, num2, den2; // Variables en el stack para los numeradores y denominadores introducidos

    std::cout << "Primera fraccion\n";
    std::cout << "  Numerador: ";   // Solicitamos al usuario el numerador de la primera fraccion
    std::cin >> num1;               // Leemos el numerador desde la entrada estandar
    std::cout << "  Denominador: "; // Solicitamos al usuario el denominador de la primera fraccion
    std::cin >> den1;               // Leemos el denominador desde la entrada estandar

    std::cout << "Segunda fraccion\n";
    std::cout << "  Numerador: ";   // Solicitamos al usuario el numerador de la segunda fraccion
    std::cin >> num2;
    std::cout << "  Denominador: "; // Solicitamos al usuario el denominador de la segunda fraccion
    std::cin >> den2;
    std::cout << "\n";

    // Comprobamos los denominadores antes de reservar memoria: si alguno es 0, la fraccion no existe
    if (den1 == 0 || den2 == 0) {
        std::cout << "El denominador no puede ser 0.\n";
        return 1; // Finalizamos el programa con un codigo de error
    }

    Fraccion* f1 = new Fraccion(num1, den1); // Creamos la primera fraccion en el heap y guardamos su direccion en el puntero f1
    Fraccion* f2 = new Fraccion(num2, den2); // Creamos la segunda fraccion en el heap y guardamos su direccion en el puntero f2

    // Mostramos las dos fracciones llamando al metodo mostrar() a traves de los punteros (operador ->)
    std::cout << "f1 = "; f1->mostrar();
    std::cout << "   f2 = "; f2->mostrar();
    std::cout << "\n\n";

    // En cada operacion:
    //  - *f2 desreferencia el puntero para pasar el objeto Fraccion (el metodo espera una fraccion, no un puntero)
    //  - f1->sumar(...) llama al metodo de f1 a traves del puntero y devuelve una NUEVA fraccion temporal
    //  - .mostrar() se llama con punto porque el resultado es un objeto, no un puntero
    //  - la fraccion temporal se destruye sola al terminar la linea (no esta en el heap, no hay que liberarla)
    std::cout << "Suma:           "; f1->sumar(*f2).mostrar();       std::cout << "\n";
    std::cout << "Resta:          "; f1->restar(*f2).mostrar();      std::cout << "\n";
    std::cout << "Multiplicacion: "; f1->multiplicar(*f2).mostrar(); std::cout << "\n";
    std::cout << "Division:       ";
    if (num2 == 0) { // Si la segunda fraccion vale 0, no se puede dividir entre ella (seria dividir entre cero)
        std::cout << "no se puede dividir entre 0";
    } else {
        f1->dividir(*f2).mostrar();
    }
    std::cout << "\n";

    delete f1; // Liberamos la memoria reservada en el heap para la fraccion f1
    delete f2; // Liberamos la memoria reservada en el heap para la fraccion f2
    f1 = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero f1
    f2 = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero f2

    return 0; // Finalizamos la ejecucion del programa
}
