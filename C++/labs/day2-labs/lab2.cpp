#include <cctype>
#include <cmath>
#include <iostream>
#include <cstring>


namespace DynamicAlloc 
{
    int** create2darray(int size)
    {
        int** ptr= new int*[size];
        for(int i=0;i<size;i++)
        {
            ptr[i]= new int[size]{1,2,3,4,5};
        }

        return ptr;
    }

    void dele(int** ptr,int size)
    {
       for(int i=0;i<size;i++)
       {
         delete[] ptr[i];
       }

       delete[] ptr;
    }
   
}

int main()
{

   int** ptr=DynamicAlloc::create2darray(5);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
          std::cout<<ptr[i][j]<<std::endl;
        }
    }
    

    return 0;
}