#include
using namespace std;
int main() {

for (int i = 1; i <= 4; i++){
    for(int j = 1;j<=4; j++){
        cout<<"*";
    }
cout<<endl;
    
}

return 0;
}
/*
OUTPUT.................................

*****/
#include
using namespace std;
int main() {

for (int i = 1; i <= 4; i++){
    for(int j = 1;j<=4; j++){
        cout<<j;
    }
cout<<endl;
    
}

return 0;
}
/*
OUTPUT........................................
1234
1234
1234
1234
*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 4; i++){
for(int j = 1; j <= 4; j++){
cout<<i;
}
cout<<endl;
}
return 0;
}
/*
OUTPUT...............................................
1111
2222
3333
4444*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 4; i++){
for(int j= 1; j <= 4; j++){
if(j % 2 == 0){
cout<<"#";
}
else
cout<<"*";

}
cout<<endl;
}
return 0;
}/*
OUTPUT.........................................................

##
##
##
##*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 4; i++){
for(int j= 1; j <= 4; j++){
//if(j % 2 == 0){
cout<<j;
// }
//else
//cout<<"*";

}
cout<<endl;
}
return 0;
}/*
OUTPUT.............................................

1234
1234
1234
1234*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 4; i++){
for(int j= 1; j <= 4; j++){
if(j % 2 == 0){
cout<<"#";
}
else{
cout<<"";
}
}
cout<<endl;
}
return 0;
}/
OUTPUT.......................................................
##
##
##
##*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 4; i++){
for(int j= 1; j <= 4; j++){
if(i % 2 == 0 && j % 2 != 0){
cout<<"";
}
else{
cout<<"#";
}
}
cout<<endl;
}
return 0;
}/
OUTPUT..........................................................

##

##*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 4; i++){
for(int j= 1; j <= 4; j++){
if(i % 2 == 0 && j % 2 == 0){
cout<<"#";
}
else{
cout<<"";
}
}
cout<<endl;
}
return 0;
}/
OUTPUT............................................................

##

##*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= i; j++){
//if(i % 2 == 0 && j % 2 == 0){
cout<<"";
// }
// else{
// cout<<"";
// }
}
cout<<endl;
}
return 0;
}/*
OUTPUT...............................................................

**

*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= i; j++){
//if(i % 2 == 0 && j % 2 == 0){
cout<<j;
// }
// else{
// cout<<"";
// }
}
cout<<endl;
}
return 0;
}/
OUTPUT................................................................
1
12
123
1234
12345*/
int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= i; j++){
//if(i % 2 == 0 && j % 2 == 0){
cout<<i;
// }
// else{
// cout<<"";
// }
}
cout<<endl;
}
return 0;
}/
OUTPUT................................................................
1
22
333
4444
55555*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 5; j >= i; j--){
//if(i % 2 == 0 && j % 2 == 0){
cout<<j;
// }
// else{
// cout<<"";
// }
}
cout<<endl;
}
return 0;
}/
OUTPUT................................................................
54321
5432
543
54
5*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 5; j >= i; j--){
//if(i % 2 == 0 && j % 2 == 0){
cout<<"";
// }
// else{
// cout<<"";
// }
}
cout<<endl;
}
return 0;
}/*
OUTPUT......................................................................

**
*
*/
#include
using namespace std;

int main()
{
for(int i= 5;i >= 1; i--){
for(int j= 1; j <= i; j++){
//if(i % 2 == 0 && j % 2 == 0){
cout<<j;
// }
// else{
// cout<<"";
// }
}
cout<<endl;
}
return 0;
}/
OUTPUT...............................................................................
12345
1234
123
12
1*/
#include
using namespace std;

int main()
{
int c = 1;

for(int i= 1;i <= 5; i++){
for(int j= 1; j <= i; j++){
if(c % 2 == 1){ // && j % 2 == 0){
cout<<"1";
}
else{
cout<<"0";
}
c++;
}
cout<<endl;
}
return 0;
}/*

OUTPUT....................................................
1
01
010
1010
10101*/
#include
using namespace std;

int main()
{
int c = 1;

for(int i= 1;i <= 5; i++){
for(int j= 1; j <= i; j++){
if(c % 2 == 1 || c % 3 == 0){
cout<<"1";
}
else{
cout<<"0";
}
c++;
}
cout<<endl;
}
return 0;
}/*
OUTPUT......................................................
1
01
011
1010
11101*/

#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= 5-i; j++){
cout<<" ";
}
for(int k = 1 ; k <= i ; k++ ){
cout<<"*";
}
cout<<endl;
}

for(int i = 4; i>=1;i--){

for(int k = 1; k<=5-i;k++){
cout<<" ";}
for(int j = 1; j<=i; j++){
cout<<"";
}
cout<<endl;
}
return 0;
}/
OUTPUT--------------------------
*
**

**
*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= 5; j++){
if(i==1||i==5||j==1||j==5){
cout<<"";}
else{
cout<<" ";
}
}
cout<<endl;
}
return 0;
}/
OUTPUT..............................

*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= 5-i; j++){
cout<<" ";
}
for(int k = 1; k <= i ; k++){
cout<<"*";
}
cout<<endl;

}
return 0;
}/*
OUTPUT..................................
*
**

*/
#include
using namespace std;

int main()
{
for(int i= 5; i >= 1; i--){
for(int j= 1; j <= 5-i; j++){
cout<<" ";
}
for(int k = 1; k <= i ; k++){
cout<<"*";
}
cout<<endl;

}
return 0;
}/*
OUTPUT........................................

**
*
*/
#include <iostream>
using namespace std;

int main()
{
for(int i= 1; i <= 5; i++){
for(int j= 1; j <= i; j++){
cout<<"*"; }
cout<<endl;}

for(int i= 4; i >= 1 ; i--){
  for(int j = 1 ; j<= i ; j++){
    cout<<"*";
  }
    cout<<endl;
  }
}
/*
OUTPUT............................................
*
**

**
*
*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= 5-i; j++){
cout<<" ";
}
for(int k = 1 ; k <= i ; k++ ){
cout<<"*";
}
cout<<endl;
}

for(int i = 4; i>=1;i--){

for(int k = 1; k<=5-i;k++){
cout<<" ";}
for(int j = 1; j<=i; j++){
cout<<"";
}
cout<<endl;
}
return 0;
}/
OUTPUT--------------------------
*
**

**
*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= 5; j++){
if(i==1||i==5||j==1||j==5){
cout<<"";}
else{
cout<<" ";
}
}
cout<<endl;
}
return 0;
}/
OUTPUT..............................

*/
#include
using namespace std;

int main()
{
for(int i= 1;i <= 5; i++){
for(int j= 1; j <= 5-i; j++){
cout<<" ";
}
for(int k = 1; k <= i ; k++){
cout<<"*";
}
cout<<endl;

}
return 0;
}/*
OUTPUT..................................
*
**

*/
#include
using namespace std;

int main()
{
for(int i= 5; i >= 1; i--){
for(int j= 1; j <= 5-i; j++){
cout<<" ";
}
for(int k = 1; k <= i ; k++){
cout<<"*";
}
cout<<endl;

}
return 0;
}/*
OUTPUT........................................

**
*
*/
#include <iostream>
using namespace std;

int main()
{
for(int i= 1; i <= 5; i++){
for(int j= 1; j <= i; j++){
cout<<"*"; }
cout<<endl;}

for(int i= 4; i >= 1 ; i--){
  for(int j = 1 ; j<= i ; j++){
    cout<<"*";
  }
    cout<<endl;
  }
}
/*
OUTPUT............................................
*
**

**
*
*/
#include
using namespace std;
int main()
{
for(int i=1 ; i<=5; i++)
{
for(int j =5;j>=i;j--)
{
cout<<" * ";
}
for(int t=1;t<=i2-2;t++)
{
cout<<" ";
}
for(int k=5;k>=i;k--)
{
cout<<" * ";
}
cout<<endl;
}
}/
OUTPUT.............................

                     *
*/
#include
using namespace std;

int main()
{
int rows;

cout << "Enter number of rows: ";
cin >> rows;

for(int i = 1; i <= rows; ++i)
{
    for(int j = 1; j <= i; ++j)
    {
        cout << "hello ";
    }
    cout << "\n";
}
return 0;
}/*
OUTPUT.............
Enter number of rows: 8
hello
hello hello
hello hello hello
hello hello hello hello
hello hello hello hello hello
hello hello hello hello hello hello
hello hello hello hello hello hello hello
hello hello hello hello hello hello hello hello
*/
#include
using namespace std;

int main()
{
int rows;

cout << "Enter number of rows: ";
cin >> rows;

for(int i = 1; i <= rows; ++i)
{
    for(int j = 1; j <= i; ++j)
    {
        cout << j << " ";
    }
    cout << "\n";
}
return 0;
}
/*
A
B B
C C C
D D D D
E E E E E
*/
#include
using namespace std;

int main()
{
int rows;

cout << "Enter number of rows: ";
cin >> rows;

for(int i = rows; i >= 1; --i)
{
    for(int j = 1; j <= i; ++j)
    {
        cout << j << " ";
    }
    cout << endl;
}

return 0;
}
/*
*
* * *
* * * * *

*/
#include
using namespace std;

int main()
{
int space, rows;

cout <<"Enter number of rows: ";
cin >> rows;

for(int i = 1, k = 0; i <= rows; ++i, k = 0)
{
    for(space = 1; space <= rows-i; ++space)
    {
        cout <<"  ";
    }

    while(k != 2*i-1)
    {
        cout << "* ";
        ++k;
    }
    cout << endl;
}    
return 0;
}
*/
