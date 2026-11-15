// Actividad Colaborativa 2 - Tecnicas RAII - Ejercicio 1
// Autor: Jose Antonio Vidal Aparicio
//
// Enunciado: crear una clase Archivo que encapsule un puntero a un archivo. La clase ListaDeObjetos
// debe utilizar esta clase para almacenar una lista de archivos. La clase Archivo debe abrir el archivo
// en su constructor y cerrarlo en su destructor.
//
// Descripción: la clase Archivo aplica la técnica RAII: abre el archivo en su constructor (adquiere el
// recurso) y lo cierra en su destructor (libera el recurso), de modo que el archivo nunca se queda abierto.
// El programa crea tres archivos (archivo1.txt, archivo2.txt y archivo3.txt), escribe en cada uno una
// frase que describe un lenguaje de programación (C++, Java y Python) y los guarda en una ListaDeObjetos.
// Al final los extrae uno a uno y los elimina con delete, lo que ejecuta el destructor y cierra cada archivo.

#include <iostream>
#include <cstdio> // Librería de C para archivos: necesaria para FILE* (el puntero a un archivo que pide el enunciado), fopen y fclose

class Archivo { // Definición de la clase Archivo, que encapsula un puntero a un archivo
private: // Atributos privados, solo accesibles desde la clase Archivo
    FILE* fichero;    // Puntero al archivo abierto. FILE va en mayúsculas porque así se llama el tipo en la librería de C (<cstdio>)
    const char* ruta; // Nombre del archivo, para mostrarlo en los mensajes

public: // Sección pública de la clase Archivo, accesible desde fuera de la clase, por ejemplo desde la función main
    Archivo(const char* ruta) { // Constructor: abre el archivo (adquiere el recurso)
        this->ruta = ruta;               // this->ruta es el atributo; ruta es el parámetro
        fichero = std::fopen(ruta, "w"); // Abrimos el archivo para escribir ("w"); si no existe, se crea. fopen devuelve nullptr si falla
        std::cout << "Abierto: " << ruta << "\n"; // Imprimimos por pantalla que el archivo se ha abierto
    }

    ~Archivo() { // Destructor: se ejecuta automáticamente al destruir el objeto y cierra el archivo (libera el recurso)
        if (fichero != nullptr) {   // Comprobamos que el archivo llegó a abrirse
            std::fclose(fichero);   // Cerramos el archivo
        }
        std::cout << "Cerrado: " << ruta << "\n"; // Imprimimos por pantalla que el archivo se ha cerrado
    }

    void escribir(const char* texto) { // Método que escribe un texto en el archivo
        if (fichero != nullptr) {          // Comprobamos que el archivo está abierto
            std::fputs(texto, fichero);    // Escribimos el texto en el archivo (fputs también es de <cstdio>)
        }
    }
};

template <typename T> // Plantilla: T es un tipo comodín que se elige al crear la lista
class ListaDeObjetos { // Misma clase ListaDeObjetos del ejercicio de gestión de la memoria, que se usa para almacenar los archivos
private: // Atributos privados, solo accesibles desde la clase ListaDeObjetos
    T* elementos;  // Puntero al array de elementos de tipo T reservado en el heap
    int cantidad;  // Número de elementos que hay guardados en el array
    int capacidad; // Número máximo de elementos que caben en el array

public: // Sección pública de la clase, accesible desde fuera de la clase
    ListaDeObjetos(int capacidad) { // Constructor que crea la lista con la capacidad indicada
        this->capacidad = capacidad;  // this->capacidad es el atributo; capacidad es el parámetro
        cantidad = 0;                 // La lista empieza vacía
        elementos = new T[capacidad]; // Reservamos memoria en el heap para el array
    }

    ~ListaDeObjetos() { // Destructor: se ejecuta automáticamente cuando la lista deja de existir
        delete[] elementos; // Liberamos la memoria reservada para el array (delete[] porque se reservó con new[])
    }

    bool agregar(const T& elemento) { // Método que agrega un elemento al final; lo recibe por referencia constante
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

int main() {
    // Creamos en el stack una lista que guarda punteros a Archivo (T = Archivo*) con capacidad para 3 elementos.
    // Guarda punteros y no objetos para no copiar los archivos: si se copiaran, cada archivo se cerraría dos veces.
    ListaDeObjetos<Archivo*> lista(3);

    const char* nombres[3] = { "archivo1.txt", "archivo2.txt", "archivo3.txt" }; // Nombres de los archivos que vamos a crear
    const char* frases[3] = { // Frase que se escribirá en cada archivo
        "C++: lenguaje compilado que permite gestionar la memoria manualmente con punteros, new y delete.\n",
        "Java: lenguaje orientado a objetos que se ejecuta en la maquina virtual de Java y libera la memoria con el recolector de basura.\n",
        "Python: lenguaje interpretado de sintaxis sencilla, muy usado en ciencia de datos e inteligencia artificial.\n"
    };

    for (int i = 0; i < 3; i++) { // Recorremos los nombres para crear, escribir y agregar cada archivo
        Archivo* nuevo = new Archivo(nombres[i]); // new reserva el objeto en el heap y ejecuta su constructor, que abre el archivo
        nuevo->escribir(frases[i]); // Escribimos en el archivo la frase que describe un lenguaje de programación
        lista.agregar(nuevo);       // Agregamos a la lista la dirección del archivo
    } // nuevo deja de existir al terminar cada vuelta, así que nunca queda como puntero colgante

    Archivo* archivo; // Puntero en el stack donde se guardará cada archivo extraído
    while (lista.extraer(archivo)) { // Extraemos los archivos mientras la lista no esté vacía
        delete archivo;    // delete ejecuta el destructor, que cierra el archivo, y devuelve la memoria del objeto
        archivo = nullptr; // El puntero sigue existiendo: evitamos un puntero colgante al asignar nullptr
    }

    return 0; // Finalizamos la ejecución del programa; la lista se destruye y su destructor libera el array
}
