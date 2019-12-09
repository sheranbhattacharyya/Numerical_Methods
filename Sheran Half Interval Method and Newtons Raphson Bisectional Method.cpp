#include <iostream>
#include <conio.h>
#include <math.h>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

double f(double x);
double fprime(double x);
void Half_Interval_Method();
void Newtons_Method();

void SheranRox();
void SheranRox(char string[100]);

double a = 0.4, b = 0.6;
double e = 0.001;

int main()
{
    std::cout << "The given Equation is : \nsqrt(1 - x^2) - e^x + 1 = 0" << endl;
    std::cout << "e = " << e << endl;

    std::cout << "\nHalf Interval method :" << endl;
    Half_Interval_Method();

    std::cout << "\n\nPress enter to continue with the Newton's Method!" << endl;
    getch();

    std::cout << "\nNewton's Method :" << endl;
    Newtons_Method();

    SheranRox();

    return 0;
}

double f(double x)
{
    double f_of_x_val =  (sqrt((1 - (pow(x, 2)))) - exp(x) + 1);
    return f_of_x_val;
}

double fprime(double x)
{
    double fprime_of_x_val = - exp(x) - (x / (sqrt( -(pow(x, 2))  + 1)));
    return fprime_of_x_val;
}

void Half_Interval_Method()
{
    double x = a + b / 2, c;
    int k = 0;

    std::cout << "\nInitial Values : " << endl;
    std::cout << "\na = " << a << endl;
    std::cout << "b = " << b << endl;
    std::cout << "f(a) = " << f(a) << endl;
    std::cout << "f(b) = " << f(b) << endl;
    std::cout << "(a + b) / 2 = " << a + b / 2 << endl;
    std::cout << "(f(a) + f(b) / 2 = " << (f(a) + f(b)) / 2 << endl;
    std::cout << "(b - a) / 2 = " << (b - a) / 2 << endl;
    std::cout << "\n\nIterating..." << endl;


    if(f(a) * f(b) >= 0)
    {
        cout<<"Incorrect a and b";
        return;
    }

    c = a;

    while ((b-a) >= e)
    {
        ++k;
        c = (a+b)/2;
        if (f(c) == 0.0)
        {
            break;
        }
        else if (f(c)*f(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
        std::cout << "\nIteration count = " << k << endl;
        std::cout << "\na = " << a << endl;
        std::cout << "b = " << b << endl;
        std::cout << "f(a) = " << f(a) << endl;
        std::cout << "f(b) = " << f(b) << endl;
        std::cout << "(a + b) / 2 = " << a + b / 2 << endl;
        std::cout << "(f(a) + f(b) / 2 = " << (f(a) + f(b)) / 2 << endl;
        std::cout << "(b - a) / 2 = " << (b - a) / 2 << endl;
    }
}

void Newtons_Method()
{
    double x,x1,e,fx,fx1;
    cout.setf(ios::fixed);
    x1 = 0.4;
    e = 0.001;
    fx = f(x);
    fx1 = fprime(x);
    std::cout <<"iterations  "<<"x{i}"<<"    "<<"x{i+1}"<<"        "<<"|x{i+1}-x{i}|"<<endl;
    int k = 0;
    do
    {
        ++k;
        x = x1;                //make x equal to the last calculated value of x1
        fx = f(x);            //simplifying f(x)to fx
        fx1 = fprime(x);            //simplifying fprime(x) to fx1
        x1 = x -(fx / fx1);            //calculate x{1} from x, fx and fx1
        std::cout << k<<"       "<< x <<"     "<< x1 <<"        "<< abs(x1 - x)<<endl;
    }
    while (fabs(x1 - x) >= e);            //if |x{i+1}-x{i}| remains greater than the desired accuracy, continue the loop
    std::cout << "The root of the equation is " << x1 << endl << "\n\n";
}



void SheranRox()
{
    SheranRox("Done");
    SheranRox("by");
    SheranRox("Sheran");
    SheranRox("the");
    SheranRox("great");
}

void SheranRox(char string[100])
{
    for(int i = 0; i <= strlen(string); i++)
    {
        for(int j = 0; j <= 2000; j++)
        {
            std::cout<< string[i] << "\b";
        }
        std::cout << string[i] << " ";
    }
    std::cout << "   ";
}
