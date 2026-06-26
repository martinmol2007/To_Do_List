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
 * @return false De lo contrario
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
    if(v.empty()) {
        cout << "No hay tareas" << endl;
    }
    else {
        sort(v.begin(), v.end(), cmp);
        cout << "Lista ordenada según prioridad!" << endl;
    }
    
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
    cout << "Introduce el nombre de la tarea a realizar: ";
    string tarea;
    getline(cin, tarea);
    info.tarea = tarea;
          
    // Consigue la prioridad
    cout << "Introduce la prioridad de la tarea (1, 2 o 3): ";
    int prioridad;
    cin >> prioridad;

    // Por seguridad
    if(prioridad <= 0 or prioridad > 3) {
        cout << "Prioridad incorrecta!" << endl;

        return;
    }

    info.prioridad = prioridad;
    info.realizada = false;

    // Poner en el vector
    to_do_list.push_back(info);

    return;
}


/**
 * @brief Saca el "emote" segun si esta hecha o no
 * 
 * @param b Estado
 * @return string Emote
 */
string estado(const bool& b) {
    return b ? "✓" : "✖";
}


/**
 * @brief Mostrar la lista de tareas actuales
 * 
 * @param v Vector de tareas
 */
void mostrar_lista(const vector<Informacion>& v) {
    cout << "Num.  Prioridad    Estado    Tarea" << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << "[" << i+1 << "]" << "       " << v[i].prioridad << "      " << "    " << estado(v[i].realizada) << "       " << v[i].tarea << endl;
    }

    return;
}

/**
 * @brief Marca una tarea como hecha
 * 
 * @param v Vector donde estan todas las tareas
 */
void marcar_tarea_hecha(vector<Informacion>& v) {
    cout << "A continuación, se mostrará la lista" << endl;
    mostrar_lista(v);
    cout << "Introduce el número de la tarea que quieres marcar como hecha: ";

    int num_tarea;
    cin >> num_tarea;

    if(num_tarea <= 0 or num_tarea >= v.size() + 1) {
        cout << "Índice incorrecto, prueba de nuevo!" << endl;
    } else {
        if(v[num_tarea-1].realizada) {
            cout << "Tarea previamente marcada como hecha" << endl;
        }
        else {
            v[num_tarea-1].realizada = true;
            cout << "Tarea número " << num_tarea << " marcada como hecha!" << endl;
        }
    }

    return;
}


/**
 * @brief Borra y ordena(despues de borrar) las tareas hechas
 * 
 * @param v Vector de Tareas
 */
void borrar_tareas_hechas(vector<Informacion>& v) {
    if(v.empty()) {
        cout << "No hay tareas" << endl;

        return;
    }

    auto it = v.begin();

    while(it != v.end()) {
        if(it->realizada) {
            it = v.erase(it);
        } else {
            it++;
        }
    }

    ordenar_vector(v);

    return;
}


/**
 * @brief Borra la lista de tareas (pregunta por si acaso)
 * 
 * @param v Vector de lista de tareas
 */
void borrar_lista(vector<Informacion>& v) {
    if(v.empty()) {
        cout << "No hay tareas" << endl;

        return;
    }

    string confirmacion;
    cout << "¿Estás seguro de que quieres borrar la lista? Introduce Y/N: ";
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
 * @param veces Veces que se ha creado un archivo como ese
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

    archivo << "Num.  Prioridad    Estado    Tarea" << endl;
    for(int i = 0; i < v.size(); i++) {
        archivo << "[" << i+1 << "]" << "       " << v[i].prioridad << "      " << "    " << estado(v[i].realizada) << "       " << v[i].tarea << endl;
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
    if(v.empty()) {
        cout << "No hay tareas, por lo tanto, es imposible exportarlas a un .txt" << endl;

        return;
    }

    string nombre;
    string nombre_archivo;
    cout << "Introduce el nombre del archivo: ";
    getline(cin, nombre);

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

    // Ponerle la extension .txt y dentro de la carpeta out
    nombre_archivo = "out/" + nombre_archivo + ".txt";

    crear_archivo(v, nombre_archivo);

    cout << "Archivo .txt creado!" << endl;

    return;
}


#endif