#ifndef FUNCIONES_HH
#define FUNCIONES_HH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Informacion {
    // Prioridad del 1 al 3 (siendo 1 la maxima prioridad)
    int prioridad;
    // Nombre de la tarea a hacer
    string tarea;
    // Estado de la tarea, hecha o no hecha
    bool realizada;
};

/**
 * @brief Simple funcion para generar el nombre del archivo
 * 
 * @param nombre Nombre del archivo a poner
 * @param veces Veces que se ha creado una archivo como ese
 * @return string Nombre del archivo
 */
string generador_nombre_archivo(string nombre, int veces) {
    if(veces == 0) return nombre;
    else return nombre + "(" + to_string(veces) + ")";
}

/**
 * @brief Funcion para crear un archivo y pasar todo lo que tiene que poner
 * 
 * @param v Vector con toda la informacion
 * @param nombre Nombre del archivo
 */
void crear_archivo(const vector<Informacion>& v, string nombre) {
    // Crea un archivo con ese nombre
    ofstream archivo(nombre);

    archivo << "Num.  Prioridad    Tarea" << endl;
    for(int i = 0; i < v.size(); i++) {
        archivo << "[" << i+1 << "]" << "       " << v[i].prioridad << "        " << v[i].tarea << endl;
    }
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
    cout << "02. Ordenar la lista" << endl;
    cout << "03. Mostrar la lista" << endl;
    cout << "04. Borrar la lista" << endl;
    cout << "05. Exportar lista tipo .txt" << endl;
    cout << "06. Mostrar opciones" << endl;
    cout << "///////////////////////////////////////////////" << endl;

    return;
}

/**
 * @brief Selector inicial
 * 
 */
void selector_inicial() {
    cout << "Selecciona una de las posibles opciones: " << endl;
    cout << "00. Salir" << endl;
    cout << "01. Añadir tarea a la lista" << endl;
    cout << "02. Ordenar la lista" << endl;
    cout << "03. Mostrar la lista" << endl;
    cout << "04. Borrar la lista" << endl;
    cout << "05. Exportar lista tipo .txt" << endl;
    cout << "06. Mostrar opciones" << endl;
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

#endif