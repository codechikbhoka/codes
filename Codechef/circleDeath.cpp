#include <iostream>
#include "stdio.h"
#include "math.h"
using namespace std;

void incrementKill(int j1, int j2, int j3, int j4, double& kill, double X[], double Y[]);
double detforvalues(double a, double b, double c, double d, double e, double f, double g, double h, double i);

int main(int argc, char const *argv[])
{
	int Testcases;
	scanf("%d",&Testcases);
	for(int z = 0;z<Testcases;z++)
	{
		int N;
		cin >> N;
		double *X = new double[N];
		double *Y = new double[N];

		double total = 0, kill = 0;

		for (int i = 0; i < N; ++i)
		{
			cin >> X[i];
			cin >> Y[i];
		}

		for (int j1 = 0; j1 < N-2; ++j1)
		{
			for (int j2 = j1+1; j2	< N-1; ++j2	)
			{
				for (int j3 = j2+1; j3 < N; ++j3)
				{
					for (int j4 = 0; j4 < N; ++j4)
					{
						if (j4!=j1 && j4!=j2 && j4!=j3 )
						{
							total++;
							incrementKill(j1,j2,j3,j4,kill,X,Y);
							//cout << "kill is "<<kill<<endl;
						}
					}

				}
			}
		}
		cout.precision(10);
		cout<<kill/total<<endl;
		
	}


	return 0;
} 

void incrementKill(int j1, int j2, int j3, int j4, double& kill, double X[], double Y[])
{
	//x^2 + y^2 + Ax + By + C = 0 ;
	double delta, deltaA, deltaB, deltaC;
	double D1 = (-1) * ( pow(X[j1],2) + pow(Y[j1],2) );
	double D2 = (-1) * ( pow(X[j2],2) + pow(Y[j2],2) );
	double D3 = (-1) * ( pow(X[j3],2) + pow(Y[j3],2) );
	delta = detforvalues(X[j1] , X[j2] , X[j3] , Y[j1] , Y[j2] , Y[j3] , 1 , 1 , 1);
	if (delta == 0)
	{
		return;
	}
	deltaA = detforvalues(D1 , D2 , D3 , Y[j1] , Y[j2] , Y[j3] , 1 , 1 , 1);
	deltaB = detforvalues(X[j1] , X[j2] , X[j3] , D1 , D2 , D3 , 1 , 1 , 1);
	deltaC = detforvalues(X[j1] , X[j2] , X[j3] , Y[j1] , Y[j2] , Y[j3] , D1 , D2 , D3);
	if (delta < 0)
	{
		deltaA = (-1)*deltaA;
		deltaB = (-1)*deltaB;
		deltaC = (-1)*deltaC;
		delta = (-1)*delta;	
	}

	//cout<<deltaA<<" "<<deltaB<<" "<<deltaC<<endl;
	double decis = delta*pow(X[j4],2) + delta*pow(Y[j4],2) + deltaA*X[j4] + deltaB*Y[j4] + deltaC ;
	if (decis <= 0)
	{
		kill++;
	}
}

double detforvalues(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
	double k;
	k = a*((e*i) - (f*h)) - b*((d*i)-(f*g)) + c*((d*h)-(e*g));
	return k;
}