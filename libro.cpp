// Actividad Colaborativa 2 - Punteros complejos - Ejercicio 5
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>
#include <string> // Librería para usar std::string (texto)

class Libro { // Definición de la clase Libro
private: // Atributos privados, solo accesibles desde la clase Libro
    std::string titulo; // Atributo que almacena el título del libro
    std::string autor;  // Atributo que almacena el autor del libro

public: // Sección pública de la clase Libro, accesible desde fuera de la clase, por ejemplo desde la función main
    Libro(const std::string& titulo, const std::string& autor) { // Constructor que inicializa el título y el autor del libro
        setTitulo(titulo); // Usamos el setter para guardar el título en el atributo
        setAutor(autor);   // Usamos el setter para guardar el autor en el atributo
    }

    std::string getTitulo() const { // Getter: método const que devuelve el título sin modificar el libro
        return titulo;
    }

    std::string getAutor() const { // Getter: método const que devuelve el autor sin modificar el libro
        return autor;
    }

    void setTitulo(const std::string& nuevoTitulo) { // Setter: método que cambia el título (no es const porque modifica el libro)
        titulo = nuevoTitulo; // Guardamos el nuevo título en el atributo
    }

    void setAutor(const std::string& nuevoAutor) { // Setter: método que cambia el autor (no es const porque modifica el libro)
        autor = nuevoAutor; // Guardamos el nuevo autor en el atributo
    }
};

int main() {
    std::string titulo; // Variable en el stack que almacena el título introducido por el usuario
    std::string autor;  // Variable en el stack que almacena el autor introducido por el usuario

    std::cout << "Introduce el titulo del libro: "; // Solicitamos al usuario que introduzca el título
    std::getline(std::cin, titulo); // Leemos la línea completa (con espacios) desde la entrada estándar
    std::cout << "Introduce el autor del libro: ";  // Solicitamos al usuario que introduzca el autor
    std::getline(std::cin, autor);  // Leemos la línea completa (con espacios) desde la entrada estándar

    Libro* libro = new Libro(titulo, autor); // Creamos un objeto Libro en el heap y guardamos su dirección en el puntero libro

    std::cout << "\nTitulo: " << libro->getTitulo() << "\n"; // Imprimimos por pantalla el título usando el getter a través del puntero
    std::cout << "Autor: " << libro->getAutor() << "\n\n";   // Imprimimos por pantalla el autor usando el getter a través del puntero

    std::cout << "Introduce el nuevo titulo: "; // Solicitamos al usuario un nuevo título
    std::getline(std::cin, titulo);
    std::cout << "Introduce el nuevo autor: ";  // Solicitamos al usuario un nuevo autor
    std::getline(std::cin, autor);

    libro->setTitulo(titulo); // Cambiamos el título del libro usando el setter
    libro->setAutor(autor);   // Cambiamos el autor del libro usando el setter

    std::cout << "\nTras modificar los atributos:\n";
    std::cout << "Titulo: " << libro->getTitulo() << "\n"; // Imprimimos por pantalla el nuevo título
    std::cout << "Autor: " << libro->getAutor() << "\n";   // Imprimimos por pantalla el nuevo autor

    delete libro; // Liberamos la memoria reservada para el objeto Libro en el heap
    libro = nullptr; // Evitamos un puntero colgante al asignar nullptr al puntero libro

    return 0; // Finalizamos la ejecución del programa
}
