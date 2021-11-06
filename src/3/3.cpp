#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;


void firstQ(connection &C)
{
   cout << "***first question***\n";
   int one = 1;
   int two = 1;
   int three = 1;
   if (one == 1)
   {
      //SELECT s.major, count(*) FROM students s GROUP BY s.major having s.major = 'CE' or s.major = 'CS';
      cout << "SELECT s.major, count(*) FROM students s GROUP BY s.major having s.major = 'CE' or s.major = 'CS';" <<endl;
      nontransaction N1(C);
      const char *query1 = "SELECT s.major, count(*) FROM students s GROUP BY s.major having s.major = 'CE' or s.major = 'CS';";
      result R1(N1.exec(query1));
      int counter = 1;
      for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
      {
         cout << counter << ")\n";
         cout << "major = " << c[0].as<string>() << endl;
         cout << "count(*) = " << c[1].as<int>() << endl;
         // cout << "major = " << c[2].as<string>() << endl;
         // cout << "address = " << c[3].as<string>() << endl;
         // cout << "phone = " << c[4].as<string>() << endl;
         cout << endl;
         counter++;
      }
      cout << "*********" << endl;

   }
   



   if (two == 1)
   {

      //SELECT t.major FROM teachers t GROUP BY t.major having max(t.salary) > 100000;

      cout << "SELECT t.major FROM teachers t GROUP BY t.major having max(t.salary) > 100000;" <<endl;
      nontransaction N2(C);
      const char *query2 = "SELECT t.major FROM teachers t GROUP BY t.major having max(t.salary) > 100000;";
      result R2(N2.exec(query2));
      int counter = 1;
      for (result::const_iterator c = R2.begin(); c != R2.end(); ++c)
      {
         cout << counter << ")\n";
         cout << "major = " << c[0].as<string>() << endl;
         // cout << "count(*) = " << c[1].as<int>() << endl;
         // cout << "major = " << c[2].as<string>() << endl;
         // cout << "address = " << c[3].as<string>() << endl;
         // cout << "phone = " << c[4].as<string>() << endl;
         cout << endl;
         counter++;
      }
      cout << "*********" << endl;

   }


   if (three == 1)
   {

      //SELECT t.major, count(*) FROM teachers t GROUP BY t.major having count(t.major)>1;
      cout << "SELECT t.major, count(*) FROM teachers t GROUP BY t.major having count(t.major)>1;" <<endl;
      nontransaction N3(C);
      const char *query3 = "SELECT t.major, count(*) FROM teachers t GROUP BY t.major having count(t.major)>1;";
      result R3(N3.exec(query3));
      int counter = 1;
      for (result::const_iterator c = R3.begin(); c != R3.end(); ++c)
      {
         cout << counter << ")\n";
         cout << "major = " << c[0].as<string>() << endl;
         cout << "count(*) = " << c[1].as<int>() << endl;
         // cout << "major = " << c[2].as<string>() << endl;
         // cout << "address = " << c[3].as<string>() << endl;
         // cout << "phone = " << c[4].as<string>() << endl;
         cout << endl;
         counter++;
      }
      cout << "*********" << endl;


   }

}

void secondQ(connection &C)
{
   cout << "***second question***\n";

   //SELECT address FROM students INTERSECT SELECT address FROM teachers ORDER BY address asc;
   cout << "SELECT address FROM students INTERSECT SELECT address FROM teachers ORDER BY address asc;" <<endl;
   nontransaction N1(C);
   const char *query1 = "SELECT address FROM students INTERSECT SELECT address FROM teachers ORDER BY address asc;";
   result R1(N1.exec(query1));
   int counter = 1;
   for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
   {
      cout << counter << ")\n";
      cout << "address = " << c[0].as<string>() << endl;
      cout << endl;
      counter++;
   }
   cout << "*********" << endl;



}

void thirdQ(connection &C)
{
   // WITH cte_foreigner AS ( SELECT id, name ,address FROM students where address != 'Lavasan' and address != 'Tehran') SELECT * from cte_foreigner;
   //insert
      cout << "***third question***\n";

   //WITH cte_foreigner AS ( SELECT id, name ,address FROM students where address != 'Lavasan' and address != 'Tehran') SELECT * from cte_foreigner;
   cout << "WITH cte_foreigner AS ( SELECT id, name ,address FROM students where address != 'Lavasan' and address != 'Tehran') SELECT * from cte_foreigner;" <<endl;
   nontransaction N1(C);
   const char *query1 = "WITH cte_foreigner AS ( SELECT id, name ,address FROM students where address != 'Lavasan' and address != 'Tehran') SELECT * from cte_foreigner;";
   result R1(N1.exec(query1));
   int counter = 1;
   for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
   {
      cout << counter << ")\n";
      cout << "id = " << c[0].as<int>() << endl;
      cout << "name = " << c[1].as<string>() << endl;
      cout << "address = " << c[2].as<string>() << endl;
      cout << endl;
      counter++;
   }
   cout << "*********" << endl;

}

void fourthQ(connection &C)
{
   //select students.id,students.name,students.major from students inner join teachers on students.id = teachers.id;
   cout << "***fourth question***\n";
   if(1==1)
   {
      //select students.id,students.name,students.major from students inner join teachers on students.id = teachers.id;
      cout << "select students.id,students.name,students.major from students inner join teachers on students.id = teachers.id;" <<endl;
      nontransaction N1(C);
      const char *query1 = "select students.id,students.name,students.major from students inner join teachers on students.id = teachers.id;";
      result R1(N1.exec(query1));
      int counter = 1;
      for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
      {
         cout << counter << ")\n";
         cout << "id = " << c[0].as<int>() << endl;
         cout << "name = " << c[1].as<string>() << endl;
         cout << "major = " << c[2].as<string>() << endl;
         cout << endl;
         counter++;
      }
      cout << "*********" << endl;
   }



   if(1==1)
   {
      //select s.id,s.name,s.major from students s left join teachers t on  s.id = t.id;

      cout << "select s.id,s.name,s.major from students s left join teachers t on  s.id = t.id;" <<endl;
      nontransaction N1(C);
      // const char *query1 = "select s.id,s.name,s.major from students s full outer join teachers t;";
      const char *query1 = "select s.id,s.name,s.major from students s left join teachers t on  s.id = t.id;";
      result R1(N1.exec(query1));
      int counter = 1;
      for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
      {
         if(!c[0].is_null())
         {
            cout << counter << ")\n";
            cout << "id = " << c[0].as<int>() << endl;
            cout << "name = " << c[1].as<string>() << endl;
            cout << "major = " << c[2].as<string>() << endl;
            cout << endl;
            counter++;
         }

      }
      cout << "*********" << endl;
   }



}

void fifthQ(connection &C)
{
   cout << "***fifth question***\n";

   //SELECT id,name,salary FROM teachers WHERE name like 'P.%' and salary >= ALL(SELECT teachers.salary FROM teachers);
   if (1==1)
   {
      //SELECT id,name,salary FROM teachers WHERE name like 'P.%' and salary >= ALL(SELECT teachers.salary FROM teachers);
      cout << "SELECT id,name,salary FROM teachers WHERE name like 'P.%' and salary >= ALL(SELECT teachers.salary FROM teachers);" <<endl;
      nontransaction N1(C);
      const char *query1 = "SELECT id,name,salary FROM teachers WHERE name like 'P.%' and salary >= ALL(SELECT teachers.salary FROM teachers);";
      result R1(N1.exec(query1));
      int counter = 1;
      for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
      {
         cout << counter << ")\n";
         cout << "id = " << c[0].as<int>() << endl;
         cout << "name = " << c[1].as<string>() << endl;
         cout << "salary = " << c[2].as<int>() << endl;
         cout << endl;
         counter++;
      }
      cout << "*********" << endl;
   }
   
   // SELECT * FROM students WHERE EXISTS (SELECT 1 FROM teachers WHERE students.id = teachers.id and teachers.salary > 0 );
      if (1==1)
   {
      //SELECT * FROM students WHERE EXISTS (SELECT 1 FROM teachers WHERE students.id = teachers.id and teachers.salary > 0 );
      cout << "SELECT * FROM students WHERE EXISTS (SELECT 1 FROM teachers WHERE students.id = teachers.id and teachers.salary > 0 );" <<endl;
      nontransaction N1(C);
      const char *query1 = "SELECT * FROM students WHERE EXISTS (SELECT 1 FROM teachers WHERE students.id = teachers.id and teachers.salary > 0 );";
      result R1(N1.exec(query1));
      int counter = 1;
      for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
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
      cout << "*********" << endl;
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
      // secondQ(C);
      // thirdQ(C);
      // fourthQ(C);
      fifthQ(C);
      C.disconnect();
   }
   catch (const std::exception &e)
   {
      cerr << e.what() << std::endl;
      return 1;
   }
}