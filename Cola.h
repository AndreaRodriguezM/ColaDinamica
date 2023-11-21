#ifndef COLA_H
#define COLA_H

#include <iostream>

// Definición de la clase alumno
class alumno {
private:
    std::string nombre;
    std::string nombreCarrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    alumno() : nombre(""), nombreCarrera(""), materiasAprobadas(0), promedioGeneral(0.0) {}
    alumno(std::string n, std::string nc, int ma, float pg) : nombre(n), nombreCarrera(nc), materiasAprobadas(ma), promedioGeneral(pg) {}

   void operator=(const alumno& x) {
    nombre = x.nombre;
    nombreCarrera = x.nombreCarrera;
    materiasAprobadas = x.materiasAprobadas;
    promedioGeneral = x.promedioGeneral;
}

    friend std::ostream& operator<<(std::ostream& os, const alumno& a) {
        os << "\tNombre: " << a.nombre
           << ", Carrera: " << a.nombreCarrera
           << ", Materias Aprobadas: " << a.materiasAprobadas
           << ", Promedio General: " << a.promedioGeneral;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, alumno& a) {
        std::cout << "\tIngrese nombre del alumno: ";
        is >> a.nombre;
        std::cout << "\tIngrese nombre de la carrera: ";
        is >> a.nombreCarrera;
        std::cout << "\tIngrese cantidad de materias aprobadas: ";
        is >> a.materiasAprobadas;
        std::cout << "\tIngrese promedio general: ";
        is >> a.promedioGeneral;
        return is;
    }
};

// Definición de la clase node
template<class T>
class node {
public:
    T data;
    node<T>* sig;

    node() : sig(nullptr) {}
};

// Definición de la clase Cola (LSLSE a Cola dinámica)
template<class T>
class Cola {
private:
    node<T>* frente;
    node<T>* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    bool vacia() const {
        return frente == nullptr;
    }

   void enqueue(const T& elem) {
        node<T>* nuevo = new node<T>;
        nuevo->data = elem;
        nuevo->sig = nullptr;

        if (vacia()) {
            frente = final = nuevo;
        } else {
            final->sig = nuevo;
            final = nuevo;
        }
        std::cout << "\t¡Elemento encolado correctamente!." << std::endl;
    }

    T dequeue() {
        if (vacia()) {
            std::cout << "\tLa cola está vacía, no se puede eliminar ningún elemento." << std::endl;
            return T();
        } else {
            node<T>* temp = frente;
            T eliminado = frente->data;
            frente = frente->sig;
            if (frente == nullptr) {
                final = nullptr;
            }
            delete temp;
            return eliminado;
        }
    }

   /* void imprimir() const {
        node<T>* aux = frente;
        while (aux != nullptr) {
            std::cout << aux->data << "-> ";
            aux = aux->sig;
        }
    } */
};

#endif // COLA_H
