#include<iostream>


void time(int seconds)
{
int minutes=seconds/60;    
int hours=minutes/60;
minutes=minutes%60;
int sec=seconds%60 ;

std::cout<<"H:M:S - "<<hours<<":"<<minutes<<":"<<sec<<std::endl;
}
int main()
{
int seconds=0;
std::cout<<"enter Time in seconds "<<std::endl;
std::cin>>seconds;
time(seconds);




    return 0 ;
}