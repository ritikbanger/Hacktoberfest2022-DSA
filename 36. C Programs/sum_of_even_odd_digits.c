/*
Sum_of_Even_Odd_Digits
If a number with n-digits is an input through the keyboard, As a programmer, write a 'C'-program and subsequent 
pseudocode to calculate the sum of its Even digits and ODD digits of a number. 
(Hint: Use the modulus operator ‘%’). Compute and print the Sum_of_EvenDigits and Sum_of_OddDigits 
only if the given number is +ve, otherwise, print "Invalid Number".

For Example :

if the given number is 12345, then Sum_of_EvenDigits = 2 + 4 = 6 and Sum_of_OddDigits = 1 + 3 + 5 = 9
if the given number is -567, then Sum_of_EvenDigits = Sum_of_OddDigits = 0 
Input : Read the number (Integer Data type)

Output : Print Sum_of_EvenDigits, Sum_of_OddDigits of a number, if the number is +ve. 
Otherwise print "Invalid Number"
*/

#include<stdio.h>

int main()
{
    int number,sum_of_even_digit=0,sum_of_odd_digit=0,rem;
    printf("Enter the number: ");
    scanf("%d",&number);
    if (number>0)
    {
        while (number!=0)
        {
            rem = number % 10;
            sum_of_odd_digit += rem;
            number = number/10;
            rem = number % 10;
            sum_of_even_digit += rem;
        }
        printf("Sum of Even Digits: %d\n",sum_of_even_digit);
        printf("Sum of odd Digits: %d\n",sum_of_odd_digit);
    }
    else
    {
        printf("Invalid number entered");
    }
}
/*
----> OUTPUT : <----

Enter the number: 5678
Sum of Even Digits: 18
Sum of odd Digits: 26

*/
