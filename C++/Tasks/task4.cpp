#include<iostream>
#include<cmath>

using namespace std;

int pop(int population , float growth_percenatge)
{

int num_years=0 ;
int pupo=population;
while(pupo<1000000)
{
    num_years++;
    pupo=pupo+static_cast<int>((pupo*6.5)/100);
}

return num_years;
}

int main()
{

    int population=162100;
   float annual_growth=6.5;


cout<<pop(population,annual_growth)<<endl;


    return 0 ;
}