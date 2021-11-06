#include <iostream>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
   try {
    //   connection C("dbname = SM-Mir user = postgres hostaddr = 127.0.0.1 port = 5432");
      connection C("dbname = smmir user = postgres password = 123 hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      const char * studentSql = "CREATE TABLE IF NOT EXISTS students ( \
      id		INT PRIMARY KEY, \
      name	VARCHAR(25) NOT NULL, \
	   major	VARCHAR(25) NOT NULL, \
	   address VARCHAR(25) NOT NULL);";
      const char * teacherSql = "CREATE TABLE IF NOT EXISTS teachers ( \
	   id		INT PRIMARY KEY, \
	   name	VARCHAR(25) NOT NULL, \
	   major	VARCHAR(25) NOT NULL, \
	   address VARCHAR(25) NOT NULL, \
	   salary	INT 		NOT NULL);";
      

      work W1(C);
      W1.exec( studentSql );
      W1.commit();
      cout << "student Table created successfully" << endl;


      work W2(C);
      W2.exec( teacherSql );
      W2.commit();
      cout << "teacher Table created successfully" << endl;

      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }
}