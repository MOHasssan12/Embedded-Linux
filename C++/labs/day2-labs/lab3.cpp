#include <iostream>
#include <utility>


namespace ArrayPair 
{

std::pair<int, int>* CreateArray(int size)
{
std::pair<int, int>* ptr= new std::pair<int,int> [size];
    return ptr;
}

void dele(std::pair<int,int>* ptr)
{
    delete[] ptr;
}

void SetPair(std::pair<int,int>* ptr,int index,int value1 , int value2)
{
    ptr[index].first=value1;
    ptr[index].second=value2;
}

void getPair(std::pair<int,int>* ptr ,int index)
{
    std::cout<<"first is "<<ptr[index].first<<" second is "<<ptr[index].second<<std::endl;

}

void printarr(std::pair<int,int>* ptr ,int size)
{

for(int i=0;i<size;i++)
{
    std::cout<<ptr[i].first<<" "<<ptr[i].second<<std::endl;
}

}

}
int main()
{

std::pair<int, int>* ptr = ArrayPair::CreateArray(2);
ArrayPair::SetPair(ptr, 0, 5, 10);
ArrayPair::SetPair(ptr, 1, 6, 12);
ArrayPair::getPair(ptr, 0);
ArrayPair::getPair(ptr, 1);
ArrayPair::printarr(ptr, 2);





 

    return 0;
}