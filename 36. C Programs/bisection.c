#include <stdio.h>
#include <Math.h>
#include <conio.h>
float function(float x)
{
    return (exp(-x)-3*log(x));
}
int main()
{
    float x0,x1,e,x2,f0,f1,f2;
    int step=1;
    label: 
    printf("Enter the lower and upper guesses and tolerable error e:\n");
    scanf("%f%f%f",&x0,&x1,&e);
    f0=function(x0);
    f1=function(x1);
    if(f0*f1>0.0)
    {
        printf("Incorrect initial guesses\n");
        goto label;
    }
    do
    {
        x2=(x0+x1)/2;
        f2=function(x2);
        printf("Step %d. Intermediate root: %f\n",step,x2);
        if(f0*f2<0)
        {
            x1=x2;
            f1=f2;
        }
        else
        {
            x0=x2;
            f0=f2;
        }
        step++;
    } while (fabs(f2)>e);
    printf("Final Root is: %f",x2);
    return 0;
}
