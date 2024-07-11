#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string dectobi(int n)
{

    string binary ;

    while(n>0)
    {
        binary = to_string(n % 2) + binary;
        n=n/2 ;
    }

    return binary ;
}

int bitodec(string bi)
{
int dec=0;
int leng=bi.length();
for(int i=0;i<leng;i++)
{
    if(bi[leng-1-i]=='1')
    {
          dec=dec+pow(2,i);
    }
}
    return dec;
}


int main()
{

cout<<dectobi(5)<<endl;
cout<<bitodec("0111")<<endl;

    return 0 ;
}