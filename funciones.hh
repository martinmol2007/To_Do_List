#ifndef FUNCIONES_HH
#define FUNCIONES_HH

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

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
 * @brief Funcion para ordenar las tareas
 * 
 * @param a Tarea a realizar 1
 * @param b Tarea a realizar 2
 * @return true Si a va antes que b
 * @return false Altramente
 */
bool cmp(const Informacion& a, const Informacion& b) {
    if(a.prioridad != b.prioridad) {
        return a.prioridad < b.prioridad;
    } else {
        return a.tarea < b.tarea;
    }
}


/**
 * @brief Ordena el vector
 * 
 * @param v Vector a ordenar
 */
void ordenar_vector(vector<Informacion>& v) {
    sort(v.begin(), v.end(), cmp);
    cout << "Lista ordenada segun prioridad!" << endl;

    return;
}


/**
 * @brief Crea una nueva tarea y la pone en el vector
 * 
 * @param to_do_list El vector en el que van las tareas
 */
void crear_nueva_tarea(vector<Informacion>& to_do_list) {
    Informacion info;

    // Consigue la tarea
    cout << "Introduce el nombre de la tarea a relalizar: ";
    string tarea;
    getline(cin, tarea);
    info.tarea = tarea;
          
    // Consigue la prioridad
    cout << "Introduce la prioridad de la tarea (1, 2 o 3): ";
    int prioridad;
    cin >> prioridad;
    info.prioridad = prioridad;
    info.realizada = false;

    // Poner en el vector
    to_do_list.push_back(info);

    return;
}


/**
 * @brief Mostrar la lista de tareas actuales
 * 
 * @param v Vector de tareas
 */
void mostrar_lista(const vector<Informacion>& v) {
    cout << "Num.  Prioridad    Tarea" << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << "[" << i+1 << "]" << "       " << v[i].prioridad << "        " << v[i].tarea << endl;
    }

    return;
}


/**
 * @brief Borra la lista de tareas (pregunta por si acaso)
 * 
 * @param v Vector de lista de tareas
 */
void borrar_lista(vector<Informacion>& v) {
    string confirmacion;
    cout << "Estas seguro de que quieres borrar la lista? Introduce Y/N: ";
    cin >> confirmacion;

    if(confirmacion == "Y" or confirmacion == "y") {
        v.erase(v.begin(), v.end());
        cout << "Lista de tareas borrada!" << endl;
    }
    else if(confirmacion == "N" or confirmacion == "n") {
        cout << "No se ha borrado!" << endl;
    }
    else {
        cout << "Letra no reconocida, prueba de nuevo!" << endl;
    }

    return;
}


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
 * @brief Crea un archivo .txt con toda la informacion
 * 
 * @param m map<string, int> para saber si ya se ha creado antes
 * @param v Vector con las cosas
 */
void exportar_lista(map<string, int>& m, const vector<Informacion>& v) {
    string nombre;
    string nombre_archivo;
    cout << "Introduce el nombre del archivo: ";
    cin >> nombre;

    // Verificar si el nombre del archivo ya ha sido creado
    // Si no ha sido creado, no le pone sufijo
    // Si si que ha sido creado, le pone el respectivo numero de veces que se ha usado
    auto it = m.find(nombre);
    if(it == m.end()) {
        m.insert({nombre, 0});
        nombre_archivo = nombre;
    } else {
        m[nombre]++;
        nombre_archivo = generador_nombre_archivo(nombre, it->second);
    }

    // Ponerle la extension .txt
    nombre_archivo = nombre_archivo + ".txt";

    crear_archivo(v, nombre_archivo);

    return;
}


#endif