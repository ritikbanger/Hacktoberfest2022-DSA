#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    /*
    n=4
        * 
        * * 
        * * * 
        * * * * 
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern2(int n){
    /*
    n=4
              * 
            * *
          * * *
        * * * * 
    */
   //process-1
   cout<<"process-1"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //process-2
    cout<<"process-2"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n-i){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
void pattern3(int n){
    /*
    n=4
        * * * * 
          * * *
            * *
              * 
    */
    //process-1
    cout<<"process-1"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //process-2
    cout<<"process-2"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
void pattern4(int n){
    /*
    n=4
        * * * * 
        * * *
        * *
        *
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern5(int n){
    /*
    n=4
              *
            * * *
          * * * * *
        * * * * * * *
    */
   //process-1
   cout<<"process-1"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //process-2
    cout<<"process-2"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j<=n-i || j> n+i-1){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
void pattern6(int n){
    /*
    n=4
           *
          * *
         * * *
        * * * *
    */
    //process-1
    cout<<"process-1"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" "; // decreasing 1 space--> cheating 😜
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //process-2
    cout<<"process-2"<<endl;
    for(int i=1;i<=n;i++){
        int k=1;
        for(int j=1;j<=2*n-1;j++){
            if((j> n-i && j <= n+i-1) && k){
                cout<<"*";
                k=0;
            }
            else{
                cout<<" ";
                k=1;
            }
        }
        cout<<endl;
    }
}
void pattern7(int n){
    /*
    n=4
        * * * * * * * 
        * * *   * * *
        * *       * *
        *           *
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j<=n-i+1 || j>= n+i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern8(int n){
    /*
    n=4
              1       
            1 2 1
          1 2 3 2 1   
        1 2 3 4 3 2 1
    */
    for(int i=1;i<=n;i++){
        int k=1;
        for(int j=1;j<=2*n-1;j++){
           if(j<=n-i || j> n+i-1){
                cout<<"  ";
            }
            else{
                cout<<k<<" ";
                j<n?k++:k--;
            }
        }
        cout<<endl;
    }
}
void pattern9(int n){
    /*
    n=4
        A B C D C B A 
        A B C   C B A
        A B       B A
        A           A
    */
    for(int i=1;i<=n;i++){
        char k='A';
        for(int j=1;j<=2*n-1;j++){
            if(j<=n-i+1 || j>= n+i-1){
                cout<<k<<" ";
            }
            else{
                cout<<"  ";
            }
            j<n?k++:k--;
        }
        cout<<endl;
    }
}
void pattern10(int n){
    /*
    n=8
              *       
            * * *     
          * * * * *   
        * * * * * * * 
          * * * * *   
            * * *     
              *      
    */
    double d =n;
    n = ceil(d/2);
    int k=0; // (-i+1)
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j>=n-k && j<=n+k){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern11(int n){
    /*
    n=7
        * 
        * *
        * * *
        * * * *
        * * *
        * * 
        *
    */
    double d =n;
    n = ceil(d/2);
    int k=1; // (-i+1)
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=k;j++){
           cout<<"* ";
        //    i<=n?k++:k--;
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern11a(int n){
    /*
    n=9
        * * * * * 
          * * * *
            * * *
              * *
                *
              * *
            * * *
          * * * *
        * * * * *
    */
    double d =n;
    n = ceil(d/2);
    int k=1;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=n;j++){
            if(j>=k){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern11b(int n){
    /*
    n=9
        1 2 3 4 5 
          1 2 3 4
            1 2 3
              1 2
                1
              1 2
            1 2 3
          1 2 3 4
        1 2 3 4 5
    */
    double d =n;
    n = ceil(d/2);
    int k=1;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=n;j++){
            if(j>=k){
                cout<<j-k+1<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern12(int n){
    /*
    n=5
        * * * * * * * * * 
          * * * * * * *   
            * * * * *
              * * *
                *
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j>=i && j<= 2*n-i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern13(int n){
    /*
    n=5
                1
              2 3 2
            3 4 5 4 3
          4 5 6 7 6 5 4   
        5 6 7 8 9 8 7 6 5
    */
    for(int i=1;i<=n;i++){
        int k=i;
        for(int j=1;j<=2*n-1;j++){
           if(j<=n-i || j> n+i-1){
                cout<<"  ";
            }
            else{
                cout<<k<<" ";
                j<n?k++:k--;
            }
        }
        cout<<endl;
    }
}
void pattern14(int n){
    /*
    n=7
        6 5 4 3 2 1 0 
        5 4 3 2 1 0
        4 3 2 1 0 
        3 2 1 0
        2 1 0
        1 0
        0
    */
    for(int i=1;i<=n;i++){
        int k = n-i;
        for(int j=1;j<=n-i+1;j++){
            cout<<k<<" ";
            k--;
        }
        cout<<endl;
    }
}
void pattern15a(int n){
    /*
    n=9
                *
              * *
            * * *
          * * * *
        * * * * *
          * * * *
            * * *
              * *
                *
    */
    double d =n;
    n = ceil(d/2);
    int k =0;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=n;j++){
            if(j>=n-k){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern15b(int n){
    /*
    n=9
                1
              1 2
            1 2 3
          1 2 3 4
        1 2 3 4 5
          1 2 3 4
            1 2 3
              1 2
                1
    */
    double d =n;
    n = ceil(d/2);
    int k =0;
    for(int i=1;i<=2*n-1;i++){
        int count =1;
        for(int j=1;j<=n;j++){
            if(j>=n-k){
                cout<<count<<" ";
                count++;
            }
            else{
                cout<<"  ";
            }
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern16(int n){
    /*
    n=7
          * * * * *  
        *   * * *   *
        * *   *   * *
        * * *   * * *
        * *   *   * *
        *   * * *   *
          * * * * *  
    */
    int k =1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j == k || j == n-k+1){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern17(int n){
    /*
    n=9
        * * * * * * * * * 
        * * * *   * * * *
        * * *       * * *
        * *           * *
        *               *
        * *           * *
        * * *       * * *
        * * * *   * * * *
        * * * * * * * * *
    */
    double d =n;
    n = ceil(d/2);
    int k=0;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j <= n-k || j>= n + k){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        i<n?k++:k--;
        cout<<endl;
    }
}
void pattern18(int n){
    /*
    n=5
        * * * * * * * * *
          * * * * * * *
            * * * * *
              * * *
                *
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j>=i && j<=2*n-i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern19(int n){
    /*
    n=4
              A       
            A B A
          A B C B A   
        A B C D C B A
    */
    for(int i=1;i<=n;i++){
        char c ='A';
        for(int j=1;j<=2*n-1;j++){
           if(j<=n-i || j> n+i-1){
                cout<<"  ";
            }
            else{
                cout<<c<<" ";
                j<n?c++:c--;
            }
        }
        cout<<endl;
    }
}
void pattern20(int n){
    /*
    n=4
              A 1      
            A B 1 2
          A B C 1 2 3   
        A B C D 1 2 3 4
    */
   // process-1
   cout<<"process-1"<<endl;
   for(int i=1;i<=n;i++){
    for(int j=n-i;j>0;j--){
        cout<<"  ";
    }
    char c = 'A';
    for(int j=1;j<=i;j++,c++){
        cout<<c<<" ";
    }
    int k=1;
    for(int j=1;j<=i;j++,k++){
        cout<<k<<" ";
    }
    cout<<endl;
   }

   //process-2
   cout<<"process-2"<<endl;
   for(int i=1;i<=n;i++){
    char c='A';
    int k=1;
    for(int j=1;j<=2*n;j++){
        if(j>=n-i+1 && j<=n+i){
            if(j>n){
                cout<<k<<" ";
                k++;
            }
            else{
                cout<<c<<" ";
                c++;
            }
        }
        else{
            cout<<"  ";
        }
    }
    cout<<endl;
   }
}
void pattern21(int n){
    /*
    n=4
              * * * * * 
            * * * * *  
          * * * * *     
        * * * * *      
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            if(j>=n-i+1 && j<=2*n-i+1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern22(int n){
    /*
    n=4
              1       
            1 2 A
          1 2 3 A B
        1 2 3 4 A B C       
    */
    for(int i=1;i<=n;i++){
        int k=1;
        char c='A';
        for(int j=1;j<=2*n-1;j++){
            if(j>=n-i+1 && j<=n+i-1){
                if(j>n){
                    cout<<c<<" ";
                    c++;
                }
                else{
                cout<<k<<" ";
                k++;
                }
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern23(int n){
    /*
    n=4
        1 
        1 0
        1 0 1
        1 0 1 0 
    */
    for(int i=1;i<=n;i++){
        int k=1;
        for(int j=1;j<=i;j++){
            cout<<k<<" ";
            j%2==0?k++:k--;
        }
        cout<<endl;
    }
}
int main(){
    pattern15b(7);
    return 0;
}
