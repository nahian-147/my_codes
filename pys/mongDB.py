import pymongo
from pymongo import MongoClient

cluster = MongoClient("mongodb+srv://kaziNAHIAN:kazi_81@cluster0.yjb9f.mongodb.net/myFrst?retryWrites=true&w=majority")
db = cluster["myFrst"]
collection = db["frst"]

post = {"_id":0,"name":"kaziNAHIAN","score":9}

collection.insert_one(post)
