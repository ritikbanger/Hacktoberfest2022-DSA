import pandas as pd

def main():
    df = pd.read_table('valid_words.txt',sep='\n')
    df['WORD'] = df['WORD'].apply(lambda x : x.replace("\r",""))

    scoreDict = {
        'q':53, 'j':89, 'z':135, 'x':139,
        'v':318, 'w':505, 'f':561, 'k':596,
        'g':679, 'b':715, 'h':814, 'm':843,
        'y':886, 'p':955, 'c':964, 'u':1089,
        'd':1181, 'n':1285, 't':1585, 'l':1586,
        'i':1592, 'r':1910, 'o':1915, 'a':2348,
        'e':3009, 's':3033
    }

    def totalScore(word):
        score = 0
        for letter in word:
            score += scoreDict[letter]
        return score

    def uniqueScore(word):
        score = 0
        letters = set(list(word))
        for letter in letters:
            score += scoreDict[letter]
        return score

    df['TOTAL SCORE'] = df['WORD'].apply(totalScore)
    df['UNIQUE SCORE'] = df['WORD'].apply(uniqueScore)

    df = df.sort_values(by=['UNIQUE SCORE'], ascending=False, ignore_index=True)

    scoreCSV = df.to_csv(index=False,sep=',')
    scoreCSV = scoreCSV.replace("\r","")

    f = open("scores.csv", "w")
    f.write(scoreCSV)
    f.close()

    wordsCSV = df['WORD'].to_csv(index=False,sep='\n')
    wordsCSV = wordsCSV.replace("\r","")

    f = open("words.txt", "w")
    f.write(wordsCSV)
    f.close()

if __name__ == "__main__":
    main()