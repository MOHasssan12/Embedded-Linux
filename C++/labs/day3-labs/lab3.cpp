#include <iostream>

template<typename T1 , typename T2>
class KeyValuePair 
{

private:
  T1 key ;
  T2 value;
public:

   KeyValuePair():key(),value()
   {
   }
  KeyValuePair(T1 fi , T2 sec):key(fi),value(sec)
  {
  }

    void setkey(T1 var1)
    {
         key=var1;
    }
    void setvalue(T2 var2)
    {
        value=var2;
    }

    T1 getkey()
    {
        return key;   
    }

    T2 getvalue()
    {
       return value;   
    }

    void print()
    {
        std::cout<<"the key is "<<key<<"the value is "<<value<<std::endl;
    }

};

int main()
{
KeyValuePair<std::string, int> obj("cairo",35); 

std::cout<<obj.getvalue();
std::cout<<obj.getkey();
obj.print();


    return 0;
}





/*                        functions overloading 


functions signature

1-function name
2-order of arguments 
3-types of arguments 
4-using const and volatile 
5- Reference or pointer 

int add(int , int ) -> if the inputs is char the compiler will impicity change int to char 

as we know that char is integer from ascii table

Example:

void func(int num)
{
    std::cout<<num<<std::endl;
}


void func(double num)
{
    std::cout<<num<<std::endl;
}

void func(std::string num)
{
    std::cout<<num<<std::endl;
}


*/

// // topic search   template specialization 

// template <typename t>

// t print(t x)
// {
//     return x;
// }

// // what if i want to prevent string input use overloading 

// void print(std::string)=delete;     
// //------------------------------------------

// std::cout<<print<int>(5)<<std::endl; // excpilict tell compiler the datatype 