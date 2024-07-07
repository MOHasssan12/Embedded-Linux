#include<iostream>

using namespace std ;

int main()
{
int var=0 ;
cout<<"please enter Number"<<endl ;
 cin>>var;
int result=0;
while(var!=0)
 {
    result=result+var;
    cout<<"please Enter New Number"<<endl;
    cin>>var;
 }

 cout<< result<<endl;
 

    return 0 ;
}