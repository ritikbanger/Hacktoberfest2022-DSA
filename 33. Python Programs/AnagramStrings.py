print("Enter the First String:")
Firststr = str(input())
print("Enter the Second String:")
Secondstr = str(input())
found=0
notFound=0
lenOne = len(Firststr)
lenTwo = len(Secondstr)
if lenOne == lenTwo:
    for i in range(lenOne):
        found = 0
        for j in range(lenOne):
            if Firststr[i] == Secondstr[j]:
                found = 1
                break
        if found==0:
            notFound = 1
            break
    if notFound==1:
        print("\nStrings are Not Anagram")
    else:
        print("\nStrings are Anagram")
else:
    print("\nLength of Strings are not Equal")
