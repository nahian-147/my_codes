import mysql.connector

db = mysql.connector.connect(
     host='localhost',
     user='nahian',
     password='Nahian_8'
        )

cursor = db.cursor()

cursor.execute('use sample5;')
cursor.execute("select user_id,username,password, rand() from user_details where gender = 'Male';")
p = cursor.fetchall()
for row in p:
    print(row[0]," ",row[1]," ",row[2],"  ",row[3])

print(len(p))
