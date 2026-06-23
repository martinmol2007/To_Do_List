#include <iostream>
#include <fstream>

#include "funciones.hh"

#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

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


int main() {
    // Se guardaran todas las tareas que hay
    vector<Informacion> to_do_list;
    // Para gestionar si ya se ha creado un archivo con ese nombre y cuantas veces se ha creado
    map<string, int> nombre_veces;

    bool primera = true;

    info_inicial();

    cout << endl;

    selector_inicial();
    
    int selector;
    
    while(cin >> selector && selector != 0) {
        cin.ignore();
        if(selector == 1) {
            Informacion info;

            // Consigue la tarea
            cout << "Introduce la tarea a relalizar: ";
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
        } 
        else if(selector == 2) {
            sort(to_do_list.begin(), to_do_list.end(), cmp);
            cout << "Lista ordenada segun prioridad!" << endl;
        }
        else if(selector == 3) {
            cout << "Tarea Num.    Prioridad    Tarea" << endl;
            for(int i = 0; i < to_do_list.size(); i++) {
                cout << "[" << i+1 << "]" << "  " << to_do_list[i].prioridad << "  " << to_do_list[i].tarea << endl;
            }
        }
        else if(selector == 4) {
            string confirmacion;
            cout << "Estas seguro de que quieres borrar la lista? Introduce Y/N: ";
            cin >> confirmacion;

            if(confirmacion == "Y" or confirmacion == "y") {
                to_do_list.erase(to_do_list.begin(), to_do_list.end());
                cout << "Lista de tareas borrada!" << endl;
            }
            else if(confirmacion == "N" or confirmacion == "n") {
                cout << "No se ha borrado!" << endl;
            }
            else {
                cout << "Letra no reconocida, prueba de nuevo!" << endl;
            }
        }
        else if(selector == 5) {
            string nombre;
            string nombre_archivo;
            cout << "Introduce el nombre del archivo: ";
            cin >> nombre;

            // Verificar si el nombre del archivo ya ha sido creado
            auto it = nombre_veces.find(nombre);
            if(it == nombre_veces.end()) {
                nombre_veces.insert({nombre, 0});
                nombre_archivo = nombre;
            } else {
                nombre_veces[nombre]++;
                nombre_archivo = generador_nombre_archivo(nombre, it->second);
            }

            nombre_archivo = nombre_archivo + ".txt";

            crear_archivo(to_do_list, nombre_archivo);
        }
        else if(selector == 6) {
            mostrar_informacion();
        }
        else {
            cout << "Opcion incorrecta, prueba de nuevo" << endl;
        }

        primera = false;
        if(not primera) {
            cout << "Ingresa tu opcion: ";
        }
    }
  
    return 0;
}