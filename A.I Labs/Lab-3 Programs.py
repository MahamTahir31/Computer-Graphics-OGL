# Lab-3 A.I
# Exercise-1
#Task-1
# _____
##list1 = [5,8,2,5,3,1,2]
##squ_list=[]
##for i in range(len(list1)): # for square
##    lam = lambda list1: list1[i]*list1[i]
##    squ_list.append(lam(list1))
##print("All List elements are squared now : ", squ_list)
##
##cub_list=[]
##for i in range(len(list1)): # for cube
##    lam = lambda list1: list1[i]*list1[i]*list1[i]
##    cub_list.append(lam(list1))
##print("All List elements are cubed now : ", cub_list)  

# Task-2
# ______
##char = "m"
##lam =  lambda word : word[0] == char
##word = "moral"
##if lam(word) == True:
##    print("Found")
##else:
##    print("Not found")

# Task-3
# ______
##import datetime
##now = datetime.datetime.now()
##print("Date and time using single function :  .........."+str(now) + "..........")
##year = lambda x: x.year
##month = lambda x: x.month
##day = lambda x: x.day
##t = lambda x: x.time()
### after extracting using lamda function 
##print("After extracting date and time using lamda function :")
##print(".....Year:",year(now),".....")
##print(".....Month:",month(now),".....")
##print(".....Day:",day(now),".....")
##print(".....Time:",t(now),".....")

# Exercise-2
# Task-1
# ______
##num_cities = int(input("Enter number of cities: "))
##
##city_file = open("city.txt","w")
##for i in range(num_cities):
##    name = input("Enter name of the city: ")
##    population = int(input("Enter population of the city: "))
##    mayor = input("Enter the name of mayor of the city: ")
##    city_file.write("Name of the city: {}\n".format(name))
##    city_file.write("Population of the city(in millions): {}\n".format(population))
##    city_file.write("Mayor of the city: {}\n".format(mayor))
##city_file.close()
##print("________________________________________________")
##print("File after write : ")
##city_file = open("city.txt", "r")
##print(city_file.read())
##city_file.close()

# Task-2
# ______
##f =  open("student.txt","w")
##f.write("Now, I am AI student\n")
##f = open("student.txt","a")
##f.write("Now we are AI students")
##f.close()
##f = open("student.txt","r")
##print(f.read())
##f.close()


## Exercise-3

##import math
##help(math)
##help(math.sqrt)
##
##from math import sqrt
##print(sqrt(3))
##
##import math as maths
##print(maths.sqrt(3))
##
##from math import sqrt as squareroot
##print(squareroot(3))
##
##import time
##print(time.time())
##
##current_time = time.time()
##print(time.ctime(current_time))
##print(time.ctime())
##
##print(time.sleep(3))
##print(time.sleep(0.5))
##
##import glob
##glob.glob("file.py")
##glob.glob("*")
##glob.glob("*.py")
##
##import random
##print(random.randint(1, 100))
##print(random.random())
##x = [2,4,6,8,10]
##random.shuffle(x)
##print(x)
##x = [2,4,6,8,10]
##print(random.sample(x, 4))




















