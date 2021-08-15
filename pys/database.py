import mysql.connector

db = mysql.connector.connect(
        host='localhost',
        user='nahian',
        password='Nahian_8',
        database='CONSUMABLES')

c = db.cursor()

name = input("name ? : ")
hours = input("Hours ? : ")

def addTime(name,hours):
    q1 = "UPDATE consumables SET consTime = consTime + "+hours+" WHERE name  = '"+name+"';"
    q2 = "UPDATE total SET total_time = total_time + "+hours+";"
    c.execute(q1)
    c.execute(q2)
    db.commit()
    db.close()

addTime(name,hours)
