// Actividad Colaborativa 2 - Punteros complejos - Ejercicio 4
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>
#include <string> // Librería para usar std::string (texto)

class Persona { // Definición de la clase Persona
private: // Atributos privados, solo accesibles desde la clase Persona
    std::string nombre; // Atributo que almacena el nombre de la persona
    int edad;           // Atributo que almacena la edad de la persona

public: // Sección pública de la clase Persona, accesible desde fuera de la clase, por ejemplo desde la función main
    Persona(const std::string& nombre, int edad) { // Constructor que inicializa el nombre y la edad de la persona
        setNombre(nombre); // Usamos el setter para guardar el nombre en el atributo
        setEdad(edad);     // Usamos el setter para guardar la edad (así también se comprueba que no sea negativa)
    }

    std::string getNombre() const { // Getter: método const que devuelve el nombre sin modificar la persona
        return nombre;
    }

    int getEdad() const { // Getter: método const que devuelve la edad sin modificar la persona
        return edad;
    }

    void setNombre(const std::string& nuevoNombre) { // Setter: método que cambia el nombre (no es const porque modifica la persona)
        nombre = nuevoNombre; // Guardamos el nuevo nombre en el atributo
    }

    void setEdad(int nuevaEdad) { // Setter: método que cambia la edad (no es const porque modifica la persona)
        if (nuevaEdad < 0) { // Comprobamos que la edad no sea negativa; si lo es, guardamos 0
            nuevaEdad = 0;
        }
        edad = nuevaEdad; // Guardamos la nueva edad en el atributo
    }
};

int main() {
    std::string nombre; // Variable en el stack que almacena el nombre introducido por el usuario
    int edad;           // Variable en el stack que almacena la edad introducida por el usuario

    std::cout << "Introduce el nombre: "; // Solicitamos al usuario que introduzca el nombre
    std::getline(std::cin, nombre);       // Leemos la línea completa (con espacios) desde la entrada estándar
    std::cout << "Introduce la edad: ";   // Solicitamos al usuario que introduzca la edad
    std::cin >> edad;                     // Leemos la edad (un número) desde la entrada estándar
    std::cin.ignore(1000, '\n');          // Descartamos el salto de línea que deja cin >> para que el siguiente getline funcione

    Persona* persona = new Persona(nombre, edad); // Creamos un objeto Persona en el heap y guardamos su dirección en el puntero persona

    std::cout << "\nNombre: " << persona->getNombre() << "\n"; // Imprimimos por pantalla el nombre usando el getter a través del puntero
    std::cout << "Edad: " << persona->getEdad() << "\n\n";     // Imprimimos por pantalla la edad usando el getter a través del puntero

    std::cout << "Introduce el nuevo nombre: "; // Solicitamos al usuario un nuevo nombre
    std::getline(std::cin, nombre);
    std::cout << "Introduce la nueva edad: ";   // Solicitamos al usuario una nueva edad
    std::cin >> edad;

    persona->setNombre(nombre); // Cambiamos el nombre de la persona usando el setter
    persona->setEdad(edad);     // Cambiamos la edad de la persona usando el setter

    std::cout << "\nTras modificar los atributos:\n";
    std::cout << "Nombre: " << persona->getNombre() << "\n"; // Imprimimos por pantalla el nuevo nombre
    std::cout << "Edad: " << persona->getEdad() << "\n";     // Imprimimos por pantalla la nueva edad

    delete persona; // Liberamos la memoria reservada para el objeto Persona en el heap
    persona = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero persona

    return 0; // Finalizamos la ejecución del programa
}
