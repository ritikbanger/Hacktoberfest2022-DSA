#include<iostream>
using namespace std;
class Student
{
    private:    string Name;
                int roll;
                float s1,s2,s3,per;
    public:     void Inputinfo()
                {
                    cout<<"enter name"<<endl;
                    getline(cin,Name);
                    cout<<"enter roll"<<endl;
                    cin>>roll;
                    cout<<"enter marks in 3 subjects"<<endl;
                    cin>>s1>>s2>>s3;
                }
                void CalcPercentage()
                {
                    per=((s1+s2+s3)/3);
                    if(per>=90&&per<=100)
                    cout<<"Grade A";
                    else if(per>=80&&per<90)
                    cout<<"Grade B";
                    else if(per>=60&&per<80)
                    cout<<"Grade C";
                    else if(per>=40&&per<60)
                    cout<<"Grade D";
                    else 
                    cout<<"Grade F";
                }
                void DisplayInfo()
                {
                    cout<<endl;
                    cout<<Name<<endl;
                    cout<<roll<<endl;
                    cout<<s1<<s2<<s3<<endl;
                
                }
};
int main()
{
    Student ob;
    ob.Inputinfo();
    ob.CalcPercentage();
    ob.DisplayInfo();
    return 0;
}