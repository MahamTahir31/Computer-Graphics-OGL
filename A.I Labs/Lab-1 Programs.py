# LAB-1 A.I
#Program to swap 4 variable values:
# _________________________________

##v1 = int(input("Enter value 1 :"))
##v2 = int(input("Enter value 2 :"))
##v3 = int(input("Enter value 3 :"))
##v4 = int(input("Enter value 4 :"))
##
##print("Before Swap : \n_____________" )
##print("value-1 = " + str(v1) + "\nvalue-2 = " + str(v2) +
##      "\nvalue-3 = " + str(v3) + "\nvalue-4 =  " + str(v4))
##
##temp = v1
##v1 = v4
##v4 = temp
##temp = v2
##v2 = v3
##v3 = temp

##print("After Swap : \n____________" )
##
##print("value-1 = " + str(v1) + "\nvalue-2 = " + str(v2) +
##      "\nvalue-3 = " + str(v3) + "\nvalue-4 =  " + str(v4))

# Program of celsius and fahrenheit conversions:
# _____________________________________________

## celsius to fahrenheit:
##temp_cels = float(input("Enter temperature in celsius : "))
##temp_fahr = (temp_cels*1.8)+32
##print(str(temp_cels) + "°C in Fahrenheit = " + str(temp_fahr) + "°F")
##
### fahrenheit to celsius:
##temp_fahr = float(input("Enter temperature in fahrenheit : "))
##temp_cels = (temp_fahr-32)*(5/9)
##print(str(temp_fahr) + "°F in Celsius = " + str(temp_cels) + "°C")


# List functions

##def count_word(words):
##    count = 0
##    for i in words:
##        if(len(i)>1 and i[0] == i[-1]):
##            count+=1
##    return count
##print ("count of words with same first and last character is:" )
##print(count_word(["Hi !", "This", "is", "maham", "Tahir"]))

# Dictionaries

##dict1 = {1:10, 2:20}
##dict2 = {3:30, 4:40}
##dict3 = {5:50, 6:60}
##dict4 = {}
##for d in (dict1, dict2, dict3) : dict4.update(d)
##print("combined dictionary is ready :\n" ,dict4)

# List Comprehensions
## task 1
##def list_comp(words):
##    list = []
##    for i in words:
##        if len(i) >2:
##            list.append(i.lower())
##
##    return list
##print(list_comp(["What", "a", "DAY", "it", "WAS"]))

##task 2
##list = ["Red", "Green", "Blue", "Yellow", "Pink", "White"]
##list = [x for (i,x) in enumerate(list) if i not in (0,4,5)]
##print(list)

# Main Task
# __________
#                                                                                Game : == Guess The Word ==
#                                                                                ......................................................

words = ["data", "learn", "tech", "world", "grow","code", "program", "shell", "prompt"]
ask = input("Start? === ")
if(ask == "yes" or ask== "Yes" or ask== "YES"):
    print("______Enjoy your game_______")
    turns = 3
    for i in range(len(words)):
        if turns == 0:
            continue
        print("____",words[i][1], "____", words[i][-1])
        guess = input("Guess the above word : ")
        if(guess==words[i]):
            print("Perfect ! ")
            if(i==len(words)-1):
                if(guess==words[i]):
                    print("Hurrah !!! You won the Game ")
        else:
            turns-=1
            if(turns==0):
                print("Game Over !")   
            else:  
                print("Ooops ! You lost , number of turns left = " + str(turns) )
else:
    print("*** Play Next time ***")


















    









