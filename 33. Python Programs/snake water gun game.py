import random

def game_win(player, comp):
    if (player==comp):
        print("It's a tie")
    elif (comp=='s'):
        if (player=='w'):
            return False
        else:
            return True

    elif (comp=='w'):
        if (player=='g'):
            return False
        else:
            return True
    elif (comp=='g'):
        if (player=='s'):
            return False
        else:
            return True

player=input("Choose one of snake(s), water(w) and gun(g)\n")
print("computer turn: snake(s), water(w) and gun(g)\n ")

randno= random.randint(1,3)
if randno==1:
    comp='s'
elif randno==2:
    comp='w'
else:
    comp='g'


print(f"computer choosen {comp}\n")

a= game_win(player, comp)
if (a==True):
    print("You won")
if (a==False):
    print("You lost")


