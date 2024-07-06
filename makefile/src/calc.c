int calc(char symbol , int var1 , int var2)
{
    int result ;

    switch (symbol) 
    {
        case '+': result=var1+var2; break;
        case '*': result=var1*var2; break;
        case '-': result=var1-var2; break;
        case '/': result=var1/var2; break;
        default: break;
    }

    return result;
}
