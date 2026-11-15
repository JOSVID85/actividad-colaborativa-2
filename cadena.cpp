// Actividad Colaborativa 2 - Gestion de la memoria - Ejercicio 3
// Autor: Jose Antonio Vidal Aparicio

#include <iostream>

class Cadena { // Definición de la clase Cadena
private: // Atributos privados, solo accesibles desde la clase Cadena
    char* datos; // Puntero al array de caracteres reservado en el heap donde se guarda el texto

public: // Sección pública de la clase Cadena, accesible desde fuera de la clase, por ejemplo desde la función main
    Cadena(const char* texto) { // Constructor que inicializa el array con la cadena dada (const porque solo la leemos)
        int longitud = 0; // Variable local en el stack para contar los caracteres de la cadena
        while (texto[longitud] != '\0') { // calculamos la longitud de la cadena sin contar el caracter nulo
            longitud++; // Sumamos un caracter más hasta llegar al caracter nulo
        }

        datos = new char[longitud + 1]; // reservamos memoria en el heap para la cadena, incluyendo el caracter nulo
        for (int i = 0; i <= longitud; i++) { // copiamos cada caracter de la cadena, incluyendo el caracter nulo
            datos[i] = texto[i]; // Copiamos el caracter de la posición i en el array reservado
        }

        std::cout << "Constructor: array inicializado con \"" << datos << "\"\n"; // Imprimimos por pantalla el texto guardado en el array
    }

    ~Cadena() { // Destructor: se ejecuta automáticamente cuando la cadena deja de existir
        std::cout << "Destructor: liberada la memoria de \"" << datos << "\"\n"; // Imprimimos el mensaje antes de liberar, porque después ya no se puede leer datos
        delete[] datos; // Liberamos la memoria reservada para el array (delete[] porque se reservó con new[])
    }
};

int main() {
    Cadena saludo("Hola mundo"); // Creamos una cadena en el stack: se ejecuta el constructor, que reserva el array en el heap

    std::cout << "Fin del programa\n"; // Imprimimos por pantalla el final del programa
    return 0; // Finalizamos la ejecución del programa; al cerrar main, saludo se destruye y se ejecuta su destructor
}
