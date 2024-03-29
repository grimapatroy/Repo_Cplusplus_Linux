#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// Asumiendo que cada maestro podría tener varias asignaturas a su cargo, se
// pide mostrar un listado de los estudiantes aplazados por maestro.

// Maestro     Estudiantes aplazados
// Juan        2, 3, 5, 6, 9, 10, 15, 17, 23
// Pedro       1, 2, 8, 14
// Marta       2, 4, 5, 14, 15, 16, 19, 21, 23
// :           :



int main()
{   
    Coll<Asignatura> collAsig = subirAsignatura();

    Coll<RMaestro> collRMaestros  = coll<RMaestro>();

    FILE* f = fopen("CALIFICACIONES_v08.dat","r+b");

    Calificacion regCalf = read<Calificacion>(f); 

    while (!feof(f))
    {
        procesarCalificacion(regCalf,collAsig,collRMaestros);
        regCalf = read<Calificacion>(f);
    }
    
    mostrarResultados(collRMaestros);



    fclose(f);

    return 0;
}

