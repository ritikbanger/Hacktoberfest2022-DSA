import random
import sys
ALL_CLOSED = """
+------+  +------+  +------+
|      |  |      |  |      |
|   1  |  |   2  |  |   3  |
|      |  |      |  |      |
|      |  |      |  |      |
|      |  |      |  |      |
+------+  +------+  +------+"""

FIRST_GOAT = """
+------+  +------+  +------+
|  ((  |  |      |  |      |
|  oo  |  |   2  |  |   3  |
| /_/|_|  |      |  |      |
|    | |  |      |  |      |
|GOAT|||  |      |  |      |
+------+  +------+  +------+"""

SECOND_GOAT = """
+------+  +------+  +------+
|      |  |  ((  |  |      |
|   1  |  |  oo  |  |   3  |
|      |  | /_/|_|  |      |
|      |  |    | |  |      |
|      |  |GOAT|||  |      |
+------+  +------+  +------+"""

THIRD_GOAT = """
+------+  +------+  +------+
|      |  |      |  |  ((  |
|   1  |  |   2  |  |  oo  |
|      |  |      |  | /_/|_|
|      |  |      |  |    | |
|      |  |      |  |GOAT|||
+------+  +------+  +------+"""

FIRST_CAR_OTHERS_GOAT = """
+------+  +------+  +------+
| CAR! |  |  ((  |  |  ((  |
|    __|  |  oo  |  |  oo  |
|  _/  |  | /_/|_|  | /_/|_|
| /_ __|  |    | |  |    | |
|   O  |  |GOAT|||  |GOAT|||
+------+  +------+  +------+"""

SECOND_CAR_OTHERS_GOAT = """
+------+  +------+  +------+
|  ((  |  | CAR! |  |  ((  |
|  oo  |  |    __|  |  oo  |
| /_/|_|  |  _/  |  | /_/|_|
|    | |  | /_ __|  |    | |
|GOAT|||  |   O  |  |GOAT|||
+------+  +------+  +------+"""

THIRD_CAR_OTHERS_GOAT = """
+------+  +------+  +------+
|  ((  |  |  ((  |  | CAR! |
|  oo  |  |  oo  |  |    __|
| /_/|_|  | /_/|_|  |  _/  |
|    | |  |    | |  | /_ __|
|GOAT|||  |GOAT|||  |   O  |
+------+  +------+  +------+"""
swapwin=0
swaplose=0
ogwin=0
oglose=0
while True:
    doorwithcar=random.randint(1,3)
    print(ALL_CLOSED)
    while True:
        userinput=int(input("Enter door number you think has the car(Press 0 to stop playing)"))
        if userinput in range(1,4):
            break
        elif userinput==0:
            print("Thanks for playing")
            sys.exit()
        else:
            print("Enter valid input")
    if doorwithcar==1 and userinput==1:
        doorshown=random.choice([2,3])
        if doorshown==2:
            print(SECOND_GOAT)
        else:
            print(THIRD_GOAT)
    elif doorwithcar==2 and userinput==1:
        doorshown=3
        print(THIRD_GOAT)
    elif doorwithcar==3 and userinput==1:
        doorshown=2
        print(SECOND_GOAT)
    elif doorwithcar==1 and userinput==2:
        doorshown=3
        print(THIRD_GOAT)

    elif doorwithcar==2 and userinput==2:
        doorshown=random.choice([1,3])
        if doorshown==1:
            print(FIRST_GOAT)
        else:
            print(THIRD_GOAT)
    elif doorwithcar==3 and userinput==2:
        doorshown=1
        print(FIRST_GOAT)
    elif doorwithcar==1 and userinput==3:
        doorshown=2
        print(SECOND_GOAT)
    elif doorwithcar==2 and userinput==3:
        doorshown=3
        print(THIRD_GOAT)
    elif doorwithcar==3 and userinput==3:
        doorshown=random.choice([1,2])
        if doorshown==1:
            print(FIRST_GOAT)
        else:
            print(SECOND_GOAT)
    else:
        print("Error")
    swap=input("Do you want to swap your selection? (Y/N)")
    #swap update ladder
    if(swap.upper()=='Y'):
        if userinput==1 and doorshown==2:
            userinput=3
        elif userinput==1 and doorshown==3:
            userinput=2 
        elif userinput==2 and doorshown==3:
            userinput=1
        elif userinput==2 and doorshown==1:
            userinput=3
        elif userinput==3 and doorshown==1:
            userinput=2
        elif userinput==3 and doorshown==2:
            userinput=1
        else:
            print("Error")
    #doorwithcar ladder
    if doorwithcar==1:
        print(FIRST_CAR_OTHERS_GOAT)
    elif doorwithcar==2:
        print(SECOND_CAR_OTHERS_GOAT)
    else:
        print(THIRD_CAR_OTHERS_GOAT)
    #scoring ladder
    if userinput==doorwithcar and swap.upper()=='Y':
        swapwin+=1
        print("congratulations you won!!")
    elif userinput==doorwithcar and swap.upper()=='N':
        ogwin+=1
        print("congratulations you won!!")
    elif userinput==doorwithcar and swap.upper()=='Y':
        swaplose+=1
        print("Better luck next time!")
    else:
        oglose+=1
        print("Better luck next time!")

    print("""Thanks for playing 
    Wins after swapping : {}
    wins without swapping : {}
    loses after swapping : {}
    loses without swapping : {}""".format(swapwin,ogwin,swaplose,oglose))
    successrateswap=0
    sucessrateog=0
    try:
        successrateswap=round(swapwin/(swapwin+swaplose)*100)
    except ZeroDivisionError:
        successrateswap=0
    try:
        successrateog=round(ogwin/(ogwin+oglose)*100)
    except ZeroDivisionError:
        successrateog=0
    print("""Success rate if you swap: {}
    Success rate if you don't: {}""".format(successrateswap,successrateog))
