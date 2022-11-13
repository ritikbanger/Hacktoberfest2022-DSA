import random
def converttoleet(message):
    leetmessage=""
    charMapping = { 'a': ['4', '@', '/-\\'], 'c': ['('], 'd': ['|)'], 'e': ['3'], 'f': ['ph'], 'h': [']-[', '|-|'], 'i': ['1', '!', '|'], 'k': [']<'], 'o': ['0'], 's': ['$', '5'], 't': ['7', '+'], 'u': ['|_|'], 'v': ['\\/']}
    for char in message:
        if (char.lower() in charMapping.keys() and (random.random()<=0.70)):
            possiblereplacements=charMapping.get(char.lower(),"")
            leetmessage+=random.choice(possiblereplacements)
        else:
            leetmessage+=char
    return leetmessage
input_text=input("Enter leet message ")
output_text=converttoleet(input_text)
print("Leetspeak for {} is {}".format(input_text,output_text))