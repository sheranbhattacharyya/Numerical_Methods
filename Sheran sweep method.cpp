//Sweep Method Sheran
#include<iostream>
#include<iomanip>
#include<cmath>
#include<conio.h>
#include<string.h>

int SheranRox(char string[100]);

using namespace std;

int main()
{
    float x[5];
    //float a[5],b[5],c[5],d[5];
    int n = 5, i;
    float P[5], Q[5];


    float a[5] = { 0 , -4, -1 , 6, 4};
    float b[5] = { 13, 9 , -12, 20, 5};
    float c[5] = { -5 , -5 , -6 , -5 , 0};
    float d[5] = { -66 , -47 , -93 , -74 , 14 };

    //a[1] = 0;
    //c[n] = 0;

    std::cout << "P and Q values are the following : \n" << "\n" << endl;
    for( i=0; i<=n-1; i++)
    {
        P[i] = (((-1) * c[i])) / ( b[i] + (a[i] * P[i-1]));
        Q[i] = (d[i] - (a[i] * Q[i-1])) / ( b[i] + (a[i] * P[i-1]));
        std::cout << "P(" << i+1 << ") = " << P[i] << endl;
        std::cout << "Q(" << i+1 << ") = " << Q[i] << "\n\n" << endl;
    }

    x[4] = Q[4];

    std::cout << " \nx values are the following : \n" << "\n" << endl;
    for(int i=n-1; i>=0; i--)
    {
        x[i] = ((P[i] * x[i+1]) + Q[i]);
    }

    for(i=0; i<=n-1; i++)
        std::cout << "x(" << i+1 << ") = " << x[i] << "\n" << endl;

    SheranRox("Done");
    std::cout << "   ";
    SheranRox("by");
    std::cout << "   ";
    SheranRox("Sheran");
    std::cout << "   ";
    SheranRox("the");
    std::cout << "   ";
    SheranRox("great");
    return 0;
}


int SheranRox(char string[100])
{
    for(int i = 0; i <= strlen(string); i++)
    {
        for(int j = 0; j <= 10000; j++)
        {
            std::cout<< string[i] << "\b";
        }
        //if(strcmp(string[i], " "))
          //  std::cout << "   ";
        std::cout << string[i] << " ";
    }
    return 0;
}
