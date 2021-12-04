from pymongo import MongoClient
from random import randint

# mongoimport --db lab9 --collection rest --drop --file restaurants.json


if __name__ == "__main__":
    question = 4
    client = MongoClient(port=27017)
    db = client["lab9"]
    mycol = db["rest"]
    if question == 1:
        # db.rest.find()
        for t in mycol.find():
            print(t)
            print("*********")

    elif question == 2:
        # db.rest.find({"borough":"Bronx"})
        for t in mycol.find({"borough":"Bronx"}):
            print(t)
            print("*********")

    elif question == 3:
        # db.rest.find({"grades.score" : {$lt : 30} }).count();
        query = {"grades.score" : {"$lt" : 30} }
        i = 0
        for t in mycol.find(query): 
            i += 1
        print(i)

    elif question == 4:
        # db.rest.find( { "cuisine" : {$ne : "American "}, "grades.grade" :"A" } ).sort({"cuisine":-1});
        query =  { "cuisine" : {"$ne" : "American "}, "grades.grade" :"A" }
        for t in mycol.find(query).sort("cuisine",-1):
            print(t)
            print("*********")
