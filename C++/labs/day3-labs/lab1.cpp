#include <iostream>


enum class ErrorCode : int {
     Bad_Request=400,
     Not_found=404,
     Server_error=500,
     Gateway_Timeout=504

};

void printerror(ErrorCode error)
{
   switch (error) {
   case ErrorCode::Bad_Request: std::cout<<"400 Bad Request"<<std::endl;break;
   case ErrorCode::Not_found: std::cout<<"404 Not Found"<<std::endl; break;
   case ErrorCode::Server_error: std::cout<<"500 Server Error"<<std::endl;break;
   case ErrorCode::Gateway_Timeout: std::cout<<"504 Gateway Timeout"<<std::endl;break;
   }

}


int main()
{

ErrorCode error = ErrorCode::Bad_Request;
printerror(error);



// std::pair<int, int> p{1, 2};  // curly prases 
// std::pair<int, int> p2 = std::make_pair(1, 2);

//                               struct

// struct in c++ is the same as the class can has constructor and destructor 
// struct can has functions and access spicifers 
// by default struct is public but class is private 

//                               enum

// enum Color { RED, GREEN, BLUE }; // normal enum

// int var = RED ;

// if(var==GREEN) ; /// valid in normal enum but in enum class not

//if(var==e::first) ; /// valid in normal enum but in enum class not valid




    return 0;
}