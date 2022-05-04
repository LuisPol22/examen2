
#include<iostream>
#include<string>
#include<mysql.h>
#include "aa.h"

using namespace std;

class Alumno {
public: string carnet, nombres, apellidos, direccion, email, fecha_n;
	  int idEstud,telefono, genero;

public: 
	Alumno() {
	}
	Alumno(int ides,string car,string nom, string ape, string dir,int tel, int gen, string em, string fn) {
		idEstud = ides;
		carnet = car;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		genero = gen;
		email = em;
		fecha_n = fn;
	}

	void insertar() {
		string t = to_string(telefono);
		string g = to_string(genero);
		int q_consulta;
		Conexion cn = Conexion();
		cn.a_conectar();
		
		if (cn.getConectar()) {
			string insertar = "insert into alumno(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) values('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + "," + g + ",'" + email + "','" + fecha_n + "');";
			const char* i = insertar.c_str();
			q_consulta = mysql_query(cn.getConectar(), i);
			if (!q_consulta) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.c_conexion();
	}

	void mostrar() {
		int q_conulta;
		Conexion cn = Conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.a_conectar();

		if (cn.getConectar()) {
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_conulta = mysql_query(cn.getConectar(), c);
			cout << "\n\tEstudiantes\n";
			cout << "\nid_estudiante, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento\n\n";
			if (!q_conulta) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.c_conexion();
	}

	void actualizar() {
		string t = to_string(telefono);
		string g = to_string(genero);
		int q_query;
		Conexion cn = Conexion();
		cn.a_conectar();

		if (cn.getConectar()) {
			string p = to_string(idEstud);
			string update = "update alumnos set carnet='"+carnet+"',nombres='"+nombres+"',apellidos='"+apellidos+"',direccion='"+direccion+"',telefono="+t+",genero="+g+",email='"+email+"',fecha_nacimiento='"+fecha_n+"' where id_estudiante=" + p + ";";
			const char* i = update.c_str();
			q_query = mysql_query(cn.getConectar(), i);
			if (!q_query) {
				cout << "Actualizacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.c_conexion();
	}
	void eliminar() {
		int q_consulta;
		Conexion cn = Conexion();
		cn.a_conectar();

		if (cn.getConectar()) {
			string p = to_string(idEstud);
			string elimin = "delete from estudiantes where id_estudiante=" + p + ";";
			const char* i = elimin.c_str();
			q_consulta = mysql_query(cn.getConectar(), i);
			if (!q_consulta) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.c_conexion();
	}

};

