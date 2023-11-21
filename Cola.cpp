#include "Cola.h"

// Implementación de la clase alumno
alumno::alumno(std::string n, std::string nc, int ma, float pg) : nombre(n), nombreCarrera(nc), materiasAprobadas(ma), promedioGeneral(pg) {}

void alumno::operator=(alumno& x)
{
    nombre = x.nombre;
    nombreCarrera = x.nombreCarrera;
    materiasAprobadas = x.materiasAprobadas;
    promedioGeneral = x.promedioGeneral;
}

std::ostream& operator<<(std::ostream& o, alumno& p)
{
    o << "\tNombre: " << p.nombre
      << ", Carrera: " << p.nombreCarrera
      << ", Materias Aprobadas: " << p.materiasAprobadas
      << ", Promedio General: " << p.promedioGeneral;
    return o;
}

std::istream& operator>>(std::istream& o, alumno& p)
{
    std::cout << "\tIngrese nombre del alumno: ";
    o >> p.nombre;
    std::cout << "\tIngrese nombre de la carrera: ";
    o >> p.nombreCarrera;
    std::cout << "\tIngrese cantidad de materias aprobadas: ";
    o >> p.materiasAprobadas;
    std::cout << "\tIngrese promedio general: ";
    o >> p.promedioGeneral;
    return o;
}

// Implementación de la clase Cola
bool Cola::vacia() const
{
    return ult == -1;
}

bool Cola::llena() const
{
    return ult == TAM - 1;
}

int Cola::ultimo() const
{
    return ult;
}

std::ostream& operator<<(std::ostream& o, Cola& L)
{
    int i = 0;
    std::cout << "\n";
    while (i <= L.ultimo())
    {
        o << L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(alumno& elem)
{
    inserta(elem, ult + 1);
}

alumno& Cola::dequeue()
{
    if (vacia())
    {
        std::cout << "\nLa cola está vacía" << std::endl;
        // Devuelve un alumno vacío por defecto
        static alumno alumno_vacio;
        return alumno_vacio;
    }
    else
    {
        return datos[0];
    }
}

bool Cola::elimina(int pos)
{
    if (vacia() || pos < 0 || pos > ult)
    {
        std::cout << "\t\nError de eliminación";
        return true;
    }
    int i = pos;
    while (i < ult)
    {
        datos[i] = datos[i + 1];
        i++;
    }
    ult--;
    return false;
}

int Cola::inserta(alumno& elem, int pos)
{
    if (llena() || pos < 0 || pos > ult + 1)
    {
        std::cout << "\t\nError de inserción";
        return 0;
    }
    int i = ult + 1;
    while (i > pos)
    {
        datos[i] = datos[i - 1];
        i--;
    }
    datos[pos] = elem;
    ult++;
    return 1;
}
