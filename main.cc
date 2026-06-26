#include <iostream>

#include "include/funciones.hh"
#include "include/menu.hh"

using namespace std;


int main() {
    // Se guardaran todas las tareas que hay
    vector<Informacion> to_do_list;
    // Para gestionar si ya se ha creado un archivo con ese nombre y cuantas veces se ha creado
    map<string, int> nombre_veces;

    info_inicial();

    cout << endl;

    selector_inicial();
    
    int selector;
    
    while(cin >> selector && selector != 0) {
        // Ignorar el endl
        cin.ignore();

        if(selector == 1) {
            crear_nueva_tarea(to_do_list);
        } 
        else if(selector == 2) {
            if(to_do_list.empty()) {
                cout << "No hay tareas pendientes!" << endl;
            } else {
                marcar_tarea_hecha(to_do_list);
            }
        }
        else if(selector == 3) {
            ordenar_vector(to_do_list);
        }
        else if(selector == 4) {
            if(to_do_list.empty()) {
                cout << "La lista esta vacia!" << endl;
            } else {
                mostrar_lista(to_do_list);
            }
        }
        else if(selector == 5) {
            borrar_tareas_hechas(to_do_list);
        }
        else if(selector == 6) {
            borrar_lista(to_do_list);
        }
        else if(selector == 7) {
            exportar_lista(nombre_veces, to_do_list);
        }
        else if(selector == 8) {
            mostrar_informacion();
        }
        else {
            cout << "Opcion incorrecta, prueba de nuevo!" << endl;
        }

        cout << "Ingresa tu opcion: ";
    }
  
    return 0;
}