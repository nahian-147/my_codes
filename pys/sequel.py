import mysql.connector
import os

mydb = mysql.connector.connect(
  host="localhost",
  user="nahian",
  password="Nahian_8"
)

mycursor = mydb.cursor()
mycursor.execute("CREATE DATABASE IF NOT EXISTS sample3")
os.system("sudo mysql -u root -p sample3 < sample2.sql")
