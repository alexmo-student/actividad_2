#pragma once
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>

using namespace std;

class sucursal {
private:
    int id_sucursal = 0;
    string nombre, ubicacion, cantidad_trabajadores, fecha_inaguracion, activo;

public:
    sucursal() {}

    sucursal(int id, string nom, string ub, string ct, string fi, string ac)
        : id_sucursal(id), nombre(nom), ubicacion(ub), cantidad_trabajadores(ct), fecha_inaguracion(fi), activo(ac) {
    }

    // Setters
    void setIdsucursal(int id) { id_sucursal = id; }
    void setNombre(string nom) { nombre = nom; }
    void setUbicacion(string ub) { ubicacion = ub; }
    void setCantidad_trabajadores(string ct) { cantidad_trabajadores = ct; }
    void setFecha_inaguracion(string fi) { fecha_inaguracion = fi; }
    void setActivo(string ac) { activo = ac; }

    // CRUD
    void crear() {
        ConexionBD cn;
        cn.abrir_conexion();

        if (cn.getConector()) {
            string consulta = "INSERT INTO sucursales (nombre, ubicacion, cantidad_trabajadores, fecha_inaguracion, activo) VALUES ('" +
                nombre + "', '" + ubicacion + "', '" + cantidad_trabajadores + "', '" + fecha_inaguracion + "', " + activo + ");";

            const char* c = consulta.c_str();
            int q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                cout << "Sucursal agregada exitosamente.\n";
                int id = mysql_insert_id(cn.getConector());
                cout << "Nuevo ID: " << id << endl;
            }
            else {
                cout << "Error al insertar sucursal.\n";
                cout << "MySQL Error: " << mysql_error(cn.getConector()) << endl;
            }
        }
        else {
            cout << "Error de conexión.\n";
        }
        cn.cerrar_conexion();
    }

    void leer() {
        ConexionBD cn;
        cn.abrir_conexion();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;

        if (cn.getConector()) {
            string consulta = "SELECT * FROM sucursales;";
            const char* c = consulta.c_str();
            mysql_query(cn.getConector(), c);

            resultado = mysql_store_result(cn.getConector());

            while ((fila = mysql_fetch_row(resultado))) {
                cout << "ID: " << fila[0] << ", Nombre: " << fila[1] << ", Ubicacion: " << fila[2]
                    << ", Cantidad Trabajadores: " << fila[3] << ", Fecha Inaguracion: " << fila[4]
                    << ", Activo: " << fila[5] << endl;
            }
        }
        else {
            cout << "Error de conexión.\n";
        }
        cn.cerrar_conexion();
    }

    void actualizar() {
        ConexionBD cn;
        cn.abrir_conexion();

        if (cn.getConector()) {
            string idStr = to_string(id_sucursal);
            string consulta = "UPDATE sucursales SET nombre='" + nombre + "', ubicacion='" + ubicacion +
                "', cantidad_trabajadores='" + cantidad_trabajadores + "', fecha_inaguracion='" + fecha_inaguracion +
                "', activo='" + activo + "' WHERE id_sucursales=" + idStr + ";";

            const char* c = consulta.c_str();
            if (!mysql_query(cn.getConector(), c)) {
                cout << "Sucursal actualizada correctamente.\n";
            }
            else {
                cout << "Error al actualizar.\n";
                cout << "MySQL Error: " << mysql_error(cn.getConector()) << endl;
            }
        }
        else {
            cout << "Error de conexión.\n";
        }
        cn.cerrar_conexion();
    }

    void borrar() {
        ConexionBD cn;
        cn.abrir_conexion();

        if (cn.getConector()) {
            string idStr = to_string(id_sucursal);
            string consulta = "DELETE FROM sucursales WHERE id_sucursales=" + idStr + ";";

            const char* c = consulta.c_str();
            if (!mysql_query(cn.getConector(), c)) {
                cout << "Sucursal eliminada correctamente.\n";
            }
            else {
                cout << "Error al eliminar.\n";
                cout << "MySQL Error: " << mysql_error(cn.getConector()) << endl;
            }
        }
        else {
            cout << "Error de conexión.\n";
        }
        cn.cerrar_conexion();
    }
};
