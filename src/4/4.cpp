#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;


/*
First question: 

select * from crosstab( 'SELECT  store_id, category.category_id, count(film.film_id) as total from category, film, inventory, film_category where category.category_id = film_category.category_id and film.film_id = film_category.film_id and film.film_id = inventory.film_id and inventory.film_id = film.film_id group by inventory.store_id,category.category_id order by 1' , 'select m from generate_series(1,16) m' ) AS ( store_id int,"Action"     int,"Animation" int,"Children"   int,"Classics"   int,"Comedy"    int, "Documentary" int,"Drama"   int,"Family"  int,"Foreign" int,"Games"  int,"Horror" int,"Music"  int,"New"    int,"Sci-Fi" int, "Travel" int,"Sports" int );

*/

void secondQ(connection &C)
{
   cout << "***second question***\n";
   cout << "select RP.yyear, RP.mmonth, RP.dday, sum(RP.amount) from (select extract(year from rental_date) as yyear, extract(month from rental_date) as mmonth, extract(day from rental_date) as dday, amount from rental, payment where rental.rental_id = payment.rental_id) as RP group by rollup (RP.yyear, RP.mmonth, RP.dday) order by RP.yyear, RP.mmonth, RP.dday;" <<endl;
   nontransaction N1(C);
   const char *query1 = "select RP.yyear, RP.mmonth, RP.dday, sum(RP.amount) from (select extract(year from rental_date) as yyear, extract(month from rental_date) as mmonth, extract(day from rental_date) as dday, amount from rental, payment where rental.rental_id = payment.rental_id) as RP group by rollup (RP.yyear, RP.mmonth, RP.dday) order by RP.yyear, RP.mmonth, RP.dday;";
   result R1(N1.exec(query1));
   int counter = 1;
   for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
   {
      cout << counter << ")\n";
      cout << "yyear = ";
      if(!c[0].is_null())
      {
         cout << c[0].as<int>();
      }
      cout << endl;
      cout << "mmounth = ";
      if(!c[1].is_null())
      {
         cout << c[1].as<int>();
      }
      cout << endl;
      cout << "dday = ";
      if(!c[2].is_null())
      {
         cout << c[2].as<int>();
      }
      cout << endl; 
      cout << "sum = " << c[3].as<double>() << endl;
      cout << endl;
      counter++;
   }
   cout << "*********" << endl;
}

void thirdQ(connection &C)
{
   cout << "***third question***\n";
   cout << "select RP.yyear, RP.mmonth, RP.dday, sum(RP.amount) from (select extract(year from rental_date) as yyear, extract(month from rental_date) as mmonth, extract(day from rental_date) as dday, amount from rental, payment where rental.rental_id = payment.rental_id) as RP group by CUBE (RP.yyear, RP.mmonth, RP.dday) order by RP.yyear, RP.mmonth, RP.dday;" <<endl;
   nontransaction N1(C);
   const char *query1 = "select RP.yyear, RP.mmonth, RP.dday, sum(RP.amount) from (select extract(year from rental_date) as yyear, extract(month from rental_date) as mmonth, extract(day from rental_date) as dday, amount from rental, payment where rental.rental_id = payment.rental_id) as RP group by CUBE (RP.yyear, RP.mmonth, RP.dday) order by RP.yyear, RP.mmonth, RP.dday;";
   result R1(N1.exec(query1));
   int counter = 1;
   for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
   {
      cout << counter << ")\n";
      cout << "yyear = ";
      if(!c[0].is_null())
      {
         cout << c[0].as<int>();
      }
      cout << endl;
      cout << "mmounth = ";
      if(!c[1].is_null())
      {
         cout << c[1].as<int>();
      }
      cout << endl;
      cout << "dday = ";
      if(!c[2].is_null())
      {
         cout << c[2].as<int>();
      }
      cout << endl; 
      cout << "sum = " << c[3].as<double>() << endl;
      cout << endl;
      counter++;
   }
   cout << "*********" << endl;
}

void fourthQ(connection &C)
{
   cout << "***fourth question***\n";
   cout << "select film.title, category.name, film.length, rank() over( partition by category.name order by film.length ) from film, category, film_category where film.film_id = film_category.film_id and category.category_id = film_category.category_id;" <<endl;
   nontransaction N1(C);
   const char *query1 = "select film.title, category.name, film.length, rank() over( partition by category.name order by film.length ) from film, category, film_category where film.film_id = film_category.film_id and category.category_id = film_category.category_id;";
   result R1(N1.exec(query1));
   int counter = 1;
   for (result::const_iterator c = R1.begin(); c != R1.end(); ++c)
   {
      cout << counter << ")\n";
      cout << "title = " << c[0].as<string>() << endl;
      cout << "name = " << c[1].as<string>() << endl;
      cout << "length = " << c[2].as<int>() << endl;
      cout << "rank = " << c[3].as<int>() << endl;
      cout << endl;
      counter++;
   }
   cout << "*********" << endl;
}



int main(int argc, char *argv[])
{
   try
   {
      connection C("dbname = dvdrental user = postgres password = 123 hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open())
      {
         cout << "Opened database successfully: " << C.dbname() << endl;
      }
      else
      {
         cout << "Can't open database" << endl;
         return 1;
      }
      // secondQ(C);
      // thirdQ(C);
      // fourthQ(C);
      C.disconnect();
   }
   catch (const std::exception &e)
   {
      cerr << e.what() << std::endl;
      return 1;
   }
}

