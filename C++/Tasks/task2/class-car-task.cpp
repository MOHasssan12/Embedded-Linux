#include <iostream>


class Car 
{
    private:
    std::string company;
    std::string model;
    int year ; 

    public:
    
    void Set_Comany(std::string name)
    {
         company=name;
    }
    void Set_model(std::string model)
    {
        this->model=model;
    }
    void Set_year(int year)
    {
        this->year=year;
    }

    void Get_comapny()
    {
    std::cout<<company<<std::endl;   
    }

    void Get_model()
    {
    std::cout<<model<<std::endl;   
    }

    void Get_year()
    {
    std::cout<<year<<std::endl;   
    }

};


int main()
{
Car astra;
astra.Set_Comany("opel");
astra.Set_model("Astra 2019");
astra.Set_year(2019);
astra.Get_model();
astra.Get_year();
astra.Get_comapny();



    return 0;
}