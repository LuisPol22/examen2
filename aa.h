
#include <iostream>
#include <mysql.h>

class Conexion{
private: MYSQL* conectar;
public:
	   void a_conectar() {
		   conectar = mysql_init(0);
		   conectar = mysql_real_connect(conectar, "localhost", "usr_examen", "examm.", "db_examen", 3306, NULL, 0);
	   }
	   MYSQL* getConectar() {
		   return conectar;
	   }
	   void c_conexion() {
		   mysql_close(conectar);
	   }

};

