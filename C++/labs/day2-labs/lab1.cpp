#include <cctype>
#include <cmath>
#include <iostream>
#include <cstring>


namespace Mathfunctions 
{
   void print(double var)
   {
      std::cout<<sqrt(var)<<std::endl;
   }
}

namespace Stringfunctions 
{
    void print(std::string str)
   {
    int leng=str.length();
        for(int i=0;i<leng;i++)
        {
            if(isupper(str[i]))
            {
                str[i]=str[i]+32;
            }
            else 
            {
                str[i]=str[i]-32;            
            }
            
        }

        std::cout<<str<<std::endl;
   }

}
namespace Arrayfunctions 
{
    void print(int var)
   {
   int arr[var];
    for(int i=0;i<var;i++)
     {
        arr[i]=i+1;
        
     }
    
    std::cout<<"the elements of the array in reverse order "<<std::endl;
   for(int i=var-1;i>=0;i--)
     {
        std::cout<<arr[i]<<std::endl;
     }
   }

}

int main()
{
Mathfunctions::print(16);
Stringfunctions::print("mohamed");
Arrayfunctions::print(5);
    return 0;
}