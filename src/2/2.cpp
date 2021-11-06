#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

void queryExec(connection &C, const char *query, bool hasOutput)
{
   if (hasOutput)
   {
      nontransaction N(C);
      result R(N.exec(query));
      int counter = 1;
      for (result::const_iterator c = R.begin(); c != R.end(); ++c)
      {
         cout << counter << ")\n";
         cout << "id = " << c[0].as<int>() << endl;
         cout << "name = " << c[1].as<string>() << endl;
         cout << "major = " << c[2].as<string>() << endl;
         cout << "address = " << c[3].as<string>() << endl;
         cout << "phone = " << c[4].as<string>() << endl;
         cout << endl;
         counter++;
      }
      cout << endl;
   }
   else
   {
      work W1(C);
      W1.exec(query);
      W1.commit();
   }
}

void firstQ(connection &C)
{
   const char *sql = "ALTER TABLE students ADD COLUMN phone VARCHAR;";
   queryExec(C, sql, false);
}

void thirdQ(connection &C)
{
   //insert
   const char *insert = "INSERT INTO students (id,name,major,address,phone)   \
   VALUES (1, 'smmir', 'CE', 'Lavasan', '09361111111' ); \
   INSERT INTO students (id,name,major,address,phone)    \
   VALUES (2, 'Allen', 'EE', 'Tehran', '09121111111' );  \
   INSERT INTO students (id,name,major,address,phone) \
   VALUES (3, 'Mark', 'CS', 'Tehran', '09371111111' );";
   queryExec(C, insert, false);
   //select
   const char *select1 = "SELECT * from students;";
   cout << "*************\nSELECT * from students;\n";
   queryExec(C, select1, true);
   // update
   const char *update = "UPDATE students set address = 'toronto' where id=2; \
   UPDATE students set major = 'Electrical Engineering' where major='EE'; \
   UPDATE students set phone = '09101111111' where id=1;";
   queryExec(C, update, false);
   //select
   const char *select2 = "SELECT * from students where major='CE';";
   cout << "*************\nSELECT * from students where major='CE';\n";
   queryExec(C, select2, true);
   const char *select3 = "SELECT * from students where id=2;";
   cout << "*************\nSELECT * from students where id=2;\n";
   queryExec(C, select3, true);
}

void fourthQ(connection &C)
{
   const char *view = "CREATE VIEW profView AS \
   SELECT  id,name,major FROM students;";
   queryExec(C, view, false);

   const char *view2 = "SELECT * FROM profView;";

   cout << "CREATE VIEW profView AS \nSELECT  id,name,major FROM students;\n\n";
   cout << "SELECT * FROM profView;\n\n";
   nontransaction N(C);
   result R(N.exec(view2));
   int counter = 1;
   for (result::const_iterator c = R.begin(); c != R.end(); ++c)
   {
      cout << counter << ")\n";
      cout << "id = " << c[0].as<int>() << endl;
      cout << "name = " << c[1].as<string>() << endl;
      cout << "major = " << c[2].as<string>() << endl;
      cout << endl;
      counter++;
   }
}

int main(int argc, char *argv[])
{
   try
   {
      connection C("dbname = smmir user = postgres password = 123 hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open())
      {
         cout << "Opened database successfully: " << C.dbname() << endl;
      }
      else
      {
         cout << "Can't open database" << endl;
         return 1;
      }
      // firstQ(C);
      // thirdQ(C);
      fourthQ(C);
      C.disconnect();
   }
   catch (const std::exception &e)
   {
      cerr << e.what() << std::endl;
      return 1;
   }
}