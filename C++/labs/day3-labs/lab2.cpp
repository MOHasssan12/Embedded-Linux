#include <iostream>


template <typename T>
class Pair
{
   private:

   T first;
   T second;

   public:

   Pair():first(0),second(0)
   {
   }
  Pair(T fi , T sec):first(fi),second(sec)
  {
  }

    void setFirst(T str)
    {
         first=str;
    }
    void setSecond(T str)
    {
        second=str;
    }

    T getFirst()
    {
        return first;   
    }

    T getSecond()
    {
       return second;   
    }

    void swap()
    {
        T temp=0;

        temp=first;
        first=second;
        second=temp;
    }

    void print()
    {
        std::cout<<first<<" "<<second<<std::endl;
    }
};

int main()
{

Pair <int>obj(10 , 15 ); 
std::cout<<obj.getFirst()<<std::endl;
std::cout<<obj.getSecond()<<std::endl;
obj.swap();
obj.print();


    return 0;
}