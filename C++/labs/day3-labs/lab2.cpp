#include <iostream>


// class Pair
// {
//    private:

//    int first;
//    int second;

//    public:

//    Pair():first(0),second(0)
//    {
//    }
//   Pair(int fi , int sec):first(fi),second(sec)
//   {
//   }

//     void setFirst(int num)
//     {
//          first=num;
//     }
//     void setSecond(int num)
//     {
//         second=num;
//     }

//     int getFirst()
//     {
//         return first;   
//     }

//     int getSecond()
//     {
//        return second;   
//     }
  
//     void swap()
//     {
//         int temp=0;

//         temp=first;
//         first=second;
//         second=temp;
//     }

//     void print()
//     {
//         std::cout<<first<<" "<<second<<std::endl;
//     }

// };


class Pair
{
   private:

   std::string first;
   std::string second;

   public:

   Pair():first("ha"),second("ah")
   {
   }
  Pair(std::string fi , std::string sec):first(fi),second(sec)
  {
  }

    void setFirst(std::string str)
    {
         first=str;
    }
    void setSecond(std::string str)
    {
        second=str;
    }

    std::string getFirst()
    {
        return first;   
    }

    std::string getSecond()
    {
       return second;   
    }
  
    void swap()
    {
        std::string temp="";

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

// Pair obj;
// obj.setFirst("moahemd");
// obj.setSecond("hassan");

Pair obj("ahmed" , "30" );

std::cout<<obj.getFirst()<<std::endl;
std::cout<<obj.getSecond()<<std::endl;
obj.swap();
obj.print();




// Pair obj;
// obj.setFirst(5);
// obj.setSecond(10);

// Pair obj(20 , 30 );

// std::cout<<obj.getFirst()<<std::endl;
// std::cout<<obj.getSecond()<<std::endl;
// obj.swap();
// obj.print();

    return 0;
}