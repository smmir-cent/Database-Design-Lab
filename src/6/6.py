
import psycopg2


def Q5_insert(conn):
    cur = conn.cursor()
    cur.execute("CREATE TABLE test (id serial PRIMARY KEY, num integer, data varchar);")

    cur.execute("INSERT INTO test (num, data) VALUES (%s, %s)",(100, "100100"))
    cur.execute("INSERT INTO test (num, data) VALUES (%s, %s)",(101, "101101"))
    cur.execute("INSERT INTO test (num, data) VALUES (%s, %s)",(102, "102102"))
    cur.execute("INSERT INTO test (num, data) VALUES (%s, %s)",(103, "103103"))    
    conn.commit()
    cur.close()
    print("********insert********")
    return

def Q5_select(conn):

    cursor = conn.cursor()
    postgreSQL_select_Query = "select * from test"

    cursor.execute(postgreSQL_select_Query)
    print("Selecting rows from test table using cursor.fetchall")
    test_records = cursor.fetchall()

    print("Print each row and it's columns values")
    for row in test_records:
        print("Id = ", row[0], )
        print("num = ", row[1])
        print("data  = ", row[2])
        print("--------------")
   
    conn.commit()
    cursor.close()
    print("********select********")

    return 0






if __name__ == "__main__":

    conn =  psycopg2.connect(host="localhost",database="smmir",user="postgres",password="123")
    # Q5_insert(conn=conn)
    Q5_select(conn=conn)

    conn.close()