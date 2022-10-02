words_file = open("words_sorted_on_letter_frequency.txt", "r")
words = words_file.read().splitlines()
words_file.close()

alphabets = list('abcdefghijklmnopqrstuvwxyz')
state = [alphabets.copy(),alphabets.copy(),alphabets.copy(),alphabets.copy(),alphabets.copy(),[]]

def isAcceptable(choice):
    for i in range(0,5):
        if choice[i] not in state[i]:
            return False
    for i in state[5]:
        if i not in choice:
            return False
    return True


#B:Black:Not Present
#Y:Yellow:Present at different position
#G:Green:Present at correct position

def handleBlack(i,char):
    #print(0,i,char)
    for j in range(0,5):
        if char in state[j]:
            state[j].remove(char)
def handleYellow(i,char):
    #print(1,i,char)
    state[i].remove(char)
    state[5].append(char)
def handleGreen(i,char):
    #print(2,i,char)
    state[i] = [char]

def handleVerdict(choice, verdict):
    for i in range(0,5):
        v = verdict[i]
        if(v=='B'):
            handleBlack(i,choice[i])
        elif(v=='Y'):
            handleYellow(i,choice[i])
        elif(v=='G'):
            handleGreen(i,choice[i])
        else:
            print("INVALID VERDICT")

def play():
    position = 0
    verdict = 'BBBBB'
    while(verdict != 'GGGGG' and position<len(words)):
        choice = words[position]
        if(isAcceptable(choice)):
            print(choice)
            verdict = input()
            print()
            handleVerdict(choice, verdict)
        else:
            position += 1
    if position<len(words):
        print("WORDLE SOLVED")
    else:
        print("WORDLE NOT SOLVED")

def main():
    print("This Wordle Solver will try to guess a 5 letter english word")
    print("Enter 5 character string for Wordle's Response")
    print("'B' for Black, 'Y' for Yellow and 'G' for Green")
    print()

    play()

    print("END")

if __name__ == "__main__":
    main()
