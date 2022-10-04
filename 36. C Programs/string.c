// Write a program in C that will implement the following functions

// a.       Count the total number of words in a string.

// b.      Find number of occurrences of a given word

// c.       Print individual characters of string in reverse order.

// d.      Count the total number of vowels and consonants in a string.

// e.      Find the most frequent character in a string.

// f.        Check whether a given substring is present in the given string. [OPTIONAL]

#include <stdio.h>
#include <string.h>
int countWords(char str[])
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}
int countOccurrences(char str[], char word[])
{
    int i, j, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == word[0])
        {
            for (j = 0; word[j] != '\0'; j++)
            {
                if (str[i + j] == word[j])
                {
                    count++;
                }
            }
        }
    }
    return count;
}
void reverseString(char str[])
{
    int i, j, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    for (i = count - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}
int countVowels(char str[])
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }
    return count;
}
int countConsonants(char str[])
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
        {
            count++;
        }
    }
    return count;
}
int mostFrequent(char str[])
{
    int i, j, count = 0, max = 0;
    char word[100];
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            word[count] = str[i];
            count++;
        }
        else
        {
            word[count] = '\0';
            if (countOccurrences(str, word) > max)
            {
                max = countOccurrences(str, word);
            }
            count = 0;
        }
    }
    return max;
}
int checkSubstring(char str[], char word[])
{
    int i, j, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == word[0])
        {
            for (j = 0; word[j] != '\0'; j++)
            {
                if (str[i + j] == word[j])
                {
                    count++;
                }
            }
        }
    }
    if (count == strlen(word))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char str[100];
    int i, j, count = 0;
    printf("Enter a string: ");
    gets(str);
    printf("Total number of words: %d\n", countWords(str));
    printf("Enter a word: ");
    char word[100];
    gets(word);
    printf("Number of occurrences: %d\n", countOccurrences(str, word));
    reverseString(str);
    printf("\n");
    printf("Total number of vowels: %d\n", countVowels(str));
    printf("Total number of consonants: %d\n", countConsonants(str));
    printf("Most frequent character: %c\n", mostFrequent(str));
    printf("Enter a substring: ");
    char sub[100];
    gets(sub);
    if (checkSubstring(str, sub))
    {
        printf("Substring is present in the string\n");
    }
    else
    {
        printf("Substring is not present in the string\n");
    }
    return 0;
}