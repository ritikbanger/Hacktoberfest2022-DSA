#include <iostream>

using namespace std;

int main()
{
    char route[1000];
    cout<<"Enter the route: ";
    cin.getline(route, 1000);

    int x=0;
    int y=0;

    for(int i=0; route[i]!='\0'; i++)
    {
        switch(route[i])
        {
            case 'N' : y++;
                      break;
            case 'S' : y--;
                      break;
            case 'W' : x--;
                      break;
            case 'E' : x++;
                       break;
        }

    }
    cout<<"The final coordinates of the shortest route are "<<x<<","<<y<<endl;
    cout<<"The shortest route is ";

    //Output in form of Directions
    if(x>=0 and y>=0)//1st Quadrant
    {
        while(y--)
        {
            cout<<"N";
        }
        while(x--)
        {
            cout<<"E";
        }
    }

    else if(x<=0 and y>=0)//2nd Quadrant
    {
        while(x++)
        {
            cout<<"W";
        }
        while(y--)
        {
            cout<<"N";
        }
    }

    else if(x<=0 and y<=0)
    {
        while(x++)
        {
            cout<<"W";
        }
        while(y++)
        {
            cout<<"S";
        }
    }

    else if(x>=0 and y<=0)
    {
        while(x--)
        {
            cout<<"N";
        }
        while(y++)
        {
            cout<<"S";
        }
    }

}
