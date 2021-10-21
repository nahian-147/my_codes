import mysql.connector 

mydb = mysql.connector.connect(
 host = 'localhost',
 user = 'nahian',
 password = 'Nahian_8'
)

cursor = mydb.cursor()
cursor.execute("USE CONSUMABLES;")

cursor.execute("SELECT * from consumables;")

result = cursor.fetchall()

for k in result:
    print(k)
