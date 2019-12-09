//Simple Iteration of Sheran
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//float iterate(float x[4][4], float alpha[4][4], float beta[4][4]);
//float iterate(float x, float alpha, float beta);


//Declaring and initializing values to Global Variables
int i,j,k;
int n = 4;
float a[4][4] = {{24,2,4,-9},{-6,-27,-8,-6},{-4,8,19,6},{4,5,-3,-13}};
float b[4] = {-9,-76,-79,-70};

float x[4],sum[4],e[4],xpr[4];
float alpha[4][4];
float beta[4];
float ee;
int iteration_count = 0;
//float alpha[4][4] = {{0,-a[0][1]/a[0][0],-a[0][2]/a[0][0],-a[0][3]/a[0][0]},{-a[1][0]/a[1][1],0,a[0][2]/a[1][1],a[0][3]/a[1][1]},{-a[1][0]/a[2][2],0,a[0][2]/a[1][1],a[0][3]/a[1][1]},{0,1,-2,10,-24}};;


int main()
{
    //Matrix A
    std::cout << "\nMatrix A : \n\n";
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
            {
                std::cout << a[i][j] << setw(20);
            }
            std::cout << "\n";
    }
    std::cout << "\n";

    //Matrix B
    std::cout << "\nMatrix B : \n\n";
    for (i=0;i<4;i++)
    {
        std::cout << b[i] << "\n";
    }
    std::cout << "\n";


    //Alpha Matrix
    std::cout << "\nAlpha Matrix : \n\n";
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
            {
                if(i==j)
                {
                    alpha[i][j] = 0 ;
                }
                else
                    alpha[i][j]= -a[i][j]/a[i][i];
                std::cout << alpha[i][j] << setw(20);
            }
            std::cout << "\n";
    }
    std::cout << "\n";


    //Beta Matrix
    std::cout << "\nBeta Matrix : \n\n";
    for (i=0;i<4;i++)
    {
        beta[i]= b[i]/a[i][i];
        std::cout << beta[i] << "\n";
    }
    std::cout << "\n";


    //iteration
    iteration_count = 1;
    std::cout << "\nIterations : \n\n";
    std::cout << "\nx(0) : \n\n";
    for (i=0;i<4;i++)
    {
        x[i] = beta[i];
        std::cout << x[i] << setw(20);
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\nx(1) : \n\n";
    do
    {
        ++iteration_count;
        for (i=0;i<4;i++)
                xpr[i]=x[i];
        for (i=0;i<4;i++)
                sum[i]=0;
        for (i=0;i<4;i++)
            for (j=0;j<4;j++)
                sum[i] += alpha[i][j] * x[j];
        for (i=0;i<4;i++)
            x[i]=sum[i]+beta[i];
        for (i=0;i<4;i++)
        {
            e[i]=abs(xpr[i]-x[i]);
            std::cout << "e(" << i << ") = " << e[i] << "\n";
        }
        ee=e[0];
        for (i=1;i<4;i++)
        {
            if(e[i]>ee)
                ee = e[i];
        }

        std::cout << "\nx(" << iteration_count << "): \n\n";
        for (i=0;i<4;i++)
            std::cout << x[i] << endl;
        std::cout << "\n";
    }
    while(ee>0.01);

    std::cout << "\n";

    /*for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            do
            {
                iterate(x, alpha, beta);
            }
            while( abs(x[i][j] - x_zero[j]) >= 0.01 );

            if(abs(x[i][j] - x_zero[j]) < 0.01)
            {
                break;
            }
        }
        std::cout << "\n";
    }*/
    /*for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            if( abs(x[i][j] - x_zero[j]) >= 0.01 );
                iterate(*x, *alpha, *beta);
            if(abs(x[i][j] - x_zero[j]) < 0.01)
                break;
        }
        std::cout << "\n";
    }
    std::cout << "\nFinal x values";
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
            {
                std::cout << x[i][j] << setw(20);
            }
            std::cout << "\n";
    }
    std::cout << "\n";
    */
    return 0;
}


/*float iterate(float x[4][4], float alpha[4][4], float beta[4])
{
    ++iteration_count;
    std::cout << "\nIteration " << iteration_count << ": \n";
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            float c = 0;
            for(int k=0;k<4;k++)
            {
                c+=alpha[i][k]*x[k][j];

            }
            x[i][j] = c + beta[j];
            //x[i][j] = (alpha[i][j] * x[i][j]) + beta[j];
            std::cout << x[i][j] << setw(20);

        }
        std::cout << "\n";
    }
    std::cout << "\n";


    return 0;
}
*/
