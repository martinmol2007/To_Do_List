#pragma once

#include <iostream>
using namespace std;

/**
 * @brief Selector inicial
 * 
 */
void selector_inicial() {
    cout << "Selecciona una de las posibles opciones: " << endl;
    cout << "00. Salir" << endl;
    cout << "01. Añadir tarea a la lista" << endl;
    cout << "02. Marcar tarea como hecha" << endl;
    cout << "03. Ordenar la lista" << endl;
    cout << "04. Mostrar la lista" << endl;
    cout << "05. Borrar la lista" << endl;
    cout << "06. Exportar lista tipo .txt" << endl;
    cout << "07. Mostrar opciones" << endl;
    cout << "Ingresa tu opcion: ";

    return;
}


/**
 * @brief Info menu inicial
 * 
 */
void info_inicial() {
    cout << "////////////////////////////////////////////////////////////////////" << endl;
    cout << "Bienvenido a la aplicacion (basica) para hacer tu To-Do List!" << endl;
    cout << "Se dara la opcion para poder escoger entre tres prioridades, siendo" << endl;
    cout << "1 la maxima prioridad y 3 la minima" << endl;
    cout << "Tambien podras marcar como hecho las tareas ya realizadas" << endl;
    cout << "A parte, podras exportarlo a un .txt" << endl;
    cout << "////////////////////////////////////////////////////////////////////" << endl;

    return;
}


/**
 * @brief Mustra la informacion del menu
 * 
 */
void mostrar_informacion() {
    cout << "//////////////////INFO/////////////////////////" << endl;
    cout << "00. Salir" << endl;
    cout << "01. Añadir tarea a la lista" << endl;
    cout << "02. Marcar tarea como hecha" << endl;
    cout << "03. Ordenar la lista" << endl;
    cout << "04. Mostrar la lista" << endl;
    cout << "05. Borrar la lista" << endl;
    cout << "06. Exportar lista tipo .txt" << endl;
    cout << "07. Mostrar opciones" << endl;
    cout << "///////////////////////////////////////////////" << endl;

    return;
}