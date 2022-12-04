#include <iostream>
#include <exception>

using namespace std;

class Exception
{
    string message;
public:
    Exception(string message = "exception") : message{ message } {};
    string Message() { return message; }
};

class MathException : public Exception
{

};

double Divide(double x, double y)
{
    if (abs(y) < 0.0001)
        throw invalid_argument("Divide by zero");
    return x / y;
}

void NoStar(char ch)
{
    if (ch == '*')
        throw exception("Func dont like star symbol");
}


void f3()
{
    cout << "func 3 start\n";
    cout << "func 3 throw\n";

    throw exception("way of exception in stack");

    cout << "func 3 finish\n";
}

void f2()
{
    cout << "func 2 start\n";

    f3();
    /*try
    {
        f3();
    }
    catch (exception& e)
    {
        cout << "func 2 cacth exception " << e.what() << "\n";
        throw e;
    }*/

    cout << "func 2 finish\n";
}

void f1()
{
    cout << "func 1 start\n";
    try
    {
        f2();
    }
    catch (exception& e)
    {
        cout << "func 1 cacth exception " << e.what() << "\n";
        throw;
    }

    cout << "func 1 finish\n";
}

int main()
{
    /*double x, y;

    cout << "input numbers: ";
    cin >> x >> y;
    
    try
    {
        double z = Divide(x, y);
        NoStar('*');
        cout << z + 1;
    }
    catch (exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        cout << "error\n";
    }*/


    try 
    {
        f1();
    }
    catch (exception& e)
    {
        cout << "main cacth exception " << e.what() << "\n";    
    }

    cout << "program work again\n";
}
