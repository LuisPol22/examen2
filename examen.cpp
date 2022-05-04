#include <iostream>
#include "Alumno.h"
using namespace std;

int main(){
	string carnet, nombres, apellidos, direccion, email, fecha_n;
	int idEstud=0, telefono=0, genero=0,op=0;
	char con;
	alumno alum = Alumno(idAlumn, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_n);

	do {
		system("cls");
		cout << "MENU: \n";
		cout << "1. Insertar datos "<<endl; 
		cout << "2. ver datos "<<endl;
		cout << "3. Actualizar datos "<<endl;
		cout << "4. Eliminar Datos " <<endl; 
		cin >> op;
		switch (op) {
		case 1: {
			cin.ignore();
			cout << "Ingrese carnet: ";
			getline(cin, carnet);
			cout << "Ingrese nombres: ";
			getline(cin, nombres);
			cout << "Ingrese apellidos: ";
			getline(cin, apellidos);
			cout << "Ingrese direccion: ";
			getline(cin, direccion);
			cout << "Ingrese telefono: ";
			cin >> telefono;
			cout << "Ingrese su genero: ";
			cin >> genero;
			cout << "Ingrese el correo electronico: ";
			cin >> email;
			cout << "Ingrese la fecha de nacimiento: ";
			cin >> fecha_n;
			Estudiante e = Alumno(idAlum, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_n);
			e.insertar();
			break;
		}
		case 2: {
			est.mostrar(); break;
		}
		case 3: {
			est.mostrar();
			cout << "\nIngrese el id del estudiante que desea actualizar: ";
			cin >> idAlum;
			cin.ignore();
			cout << "Ingrese carnet: ";
			getline(cin, carnet);
			cout << "Ingrese nombres: ";
			getline(cin, nombres);
			cout << "Ingrese apellidos: ";
			getline(cin, apellidos);
			cout << "Ingrese direccion: ";
			getline(cin, direccion);
			cout << "Ingrese telefono: ";
			cin >> telefono;
			cout << "Ingrese su genero: ";
			cin >> genero;
			cout << "Ingrese el correo electronico: ";
			cin >> email;
			cout << "Ingrese la fecha de nacimiento: ";
			cin >> fecha_n;
			Estudiante e = Alumn(idEstud, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_n);
			e.actualizar();
			break;
		}
		case 4: {
			est.mostrar();
			cout << "\nIngrese el id del estudiante que desea eliminar: ";
			cin >> idEstud;
			Estudiante e = Alumn(idEstud, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_n);
			e.eliminar();
			break;
		}
		}
	
	
	system("pause");
}
}

