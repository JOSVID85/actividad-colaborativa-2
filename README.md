# Actividad Colaborativa 2: Ejercicios prácticos de gestión de la memoria

**Asignatura:** Programación con Estructuras Lineales — Universidad Europea
**Alumno:** José Antonio Vidal Aparicio

Ejercicios en C++ sobre punteros, memoria dinámica (stack y heap), plantillas y la técnica RAII.
Los ejercicios siguen el mismo orden que el enunciado.

## Ejercicios

### 1. Punteros simples (`1_punteros_simples/`)
| Archivo | Ejercicio |
|---|---|
| `ejercicio1.cpp` | Puntero a un entero: valor y dirección de memoria |
| `ejercicio2.cpp` | Valor introducido por el usuario a través de un puntero |
| `ejercicio3.cpp` | Suma de dos valores almacenada mediante un puntero |
| `ejercicio4.cpp` | Suma de los elementos de un array dinámico |
| `ejercicio5.cpp` | Intercambio de valores mediante dos punteros |

### 2. Punteros complejos (`2_punteros_complejos/`)
| Archivo | Ejercicio |
|---|---|
| `rectangulo.cpp` | Clase Rectángulo: área y perímetro |
| `circulo.cpp` | Clase Círculo: área y circunferencia |
| `fraccion.cpp` | Clase Fracción: suma, resta, multiplicación y división |
| `persona.cpp` | Clase Persona: getters y setters de nombre y edad |
| `libro.cpp` | Clase Libro: getters y setters de título y autor |

### 3. Punteros para la gestión de la memoria (`3_gestion_memoria/`)
| Archivo | Ejercicio |
|---|---|
| `lista_de_objetos.cpp` | Clase ListaDeObjetos: array de objetos de cualquier clase |
| `lista_de_punteros.cpp` | Clase ListaDePunteros: array de punteros a objetos |
| `cadena.cpp` | Clase Cadena: puntero a un array de caracteres |
| `cola.cpp` | Clase Cola con tamaño dinámico (extra) |

### 4. Técnicas RAII (`4_raii/`)
| Archivo | Ejercicio |
|---|---|
| `archivo.cpp` | Clase Archivo almacenada en una ListaDeObjetos |
| `espacios_de_memoria.cpp` | Clase EspaciosDeMemoria: bloques de memoria alineados |
| `dinarray.cpp` | Clase genérica Dinarray con tres TAD diferentes |

## Cómo compilar y ejecutar

Con g++ (MSYS2 UCRT64), desde la carpeta del ejercicio:

```bash
g++ ejercicio1.cpp -o ejercicio1
./ejercicio1
```

## Librerías utilizadas

No se utiliza ningún contenedor de la librería estándar (`vector`, `list`, `array`...): las estructuras de datos se han programado a mano.

- `<iostream>`: entrada y salida por consola (todos los ejercicios).
- `<string>`: textos en Persona, Libro y el TAD Producto de Dinarray.
- `<cstdio>`: puntero a un archivo (`FILE*`), `fopen` y `fclose` en el ejercicio Archivo.
