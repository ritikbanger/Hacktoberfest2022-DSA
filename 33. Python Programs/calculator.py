num1 = int(input('Enter a number: '))
num2 = int(input('Enter another number: '))
op = input('Enter operator from the following: + - * ? ')

if(op == "+"):
    calc = num1 + num2
    print(calc)  
elif(op == "-"):
    calc = num1 - num2
    print(calc)
elif(op == "*"):
    calc = num1 * num2
    print(calc)
elif(op == "/"):
    if(num2 == 0):
        print("Denominator should not be zero")
    else:
        calc = num1 / num2
        print(calc)
else:
    print("Enter valid inputs")
