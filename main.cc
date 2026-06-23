#include <iostream>
#include <fstream>

#include "funciones.hh"
#include "menu.hh"

using namespace std;


int main() {
    // Se guardaran todas las tareas que hay
    vector<Informacion> to_do_list;
    // Para gestionar si ya se ha creado un archivo con ese nombre y cuantas veces se ha creado
    map<string, int> nombre_veces;
    // Para saber cuando poner el comando de ayuda
    bool primera = true;

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
            ordenar_vector(to_do_list);
        }
        else if(selector == 3) {
            mostrar_lista(to_do_list);
        }
        else if(selector == 4) {
            borrar_lista(to_do_list);
        }
        else if(selector == 5) {
            exportar_lista(nombre_veces, to_do_list);
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