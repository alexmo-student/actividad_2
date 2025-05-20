#include <mysql.h>
#include "Sucursal.h"
#include <iostream>

using namespace std;

// Menú para manejar las operaciones sobre la sucursal
void menuSucursales() {
    sucursal p;
    int opcion = 0;

    do {
        cout << "\n--- Menu Sucursal ---\n";
        cout << "1. Crear\n2. Leer\n3. Actualizar\n4. Borrar\n5. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            string nombre, ubicacion, cantidad_trabajadores, fecha_inaguracion, activo;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Ubicacion: "; getline(cin, ubicacion);
            cout << "Cantidad de Trabajadores: "; getline(cin, cantidad_trabajadores);
            cout << "Fecha Inauguracion: "; getline(cin, fecha_inaguracion);
            cout << "Activo (1 o 0): "; getline(cin, activo);

            p = sucursal(0, nombre, ubicacion, cantidad_trabajadores, fecha_inaguracion, activo);
            p.crear();
            break;
        }
        case 2:
            p.leer();
            break;
        case 3: {
            int id;
            string nombre, ubicacion, cantidad_trabajadores, fecha_inaguracion, activo;
            cout << "ID del sucursal a actualizar: "; cin >> id; cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Ubicacion: "; getline(cin, ubicacion);
            cout << "Cantidad de Trabajadores: "; getline(cin, cantidad_trabajadores);
            cout << "Fecha Inauguracion: "; getline(cin, fecha_inaguracion);
            cout << "Activo (1 o 0): "; getline(cin, activo);

            p.setIdsucursal(id);
            p.setNombre(nombre);
            p.setUbicacion(ubicacion);
            p.setCantidad_trabajadores(cantidad_trabajadores);
            p.setFecha_inaguracion(fecha_inaguracion);
            p.setActivo(activo);
            p.actualizar();
            break;
        }
        case 4: {
            int id;
            cout << "ID del sucursal a eliminar: "; cin >> id; cin.ignore();
            p.setIdsucursal(id);
            p.borrar();
            break;
        }
        case 5:
            cout << "Saliendo del menu de sucursales...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 5);
}

// Menú principal
int main() {
    int OpcionPrincipal = 0;

    do {
        cout << "\n--- Menu Principal ---\n";
        cout << "1 - Sucursal\n";
        cout << "2 - Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> OpcionPrincipal;
        cin.ignore();

        switch (OpcionPrincipal) {
        case 1:
            menuSucursales();
            break;
        case 2:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (OpcionPrincipal != 2);

    return 0;
}
