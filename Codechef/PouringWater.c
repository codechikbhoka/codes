#include <iostream>
#include "stdio.h"
#include <deque>

using namespace std;


int answer = 0 ;

struct State
{
	int first;
	int second;
	int level;

	State(){}
	State(int a, int b, int l)
	{
		first = a;
		second = b;
		level = l;
	}
};


struct AdvancedQueue
{

private:

	deque<State> v;

public:

	void push_back(int a, int b, int l)
	{
		State temp(a,b,l);
		v.push_back(temp);
	}

	void uniquely_push_back(int a, int b, int l)
	{
		if (!contains(a,b))
		{
			State temp(a,b,l);
			v.push_back(temp);	
		}
		
	}

	bool contains(int a, int b)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (a == v.at(i).first && b == v.at(i).second)	
			{
				return true;
			}
		}

		return false;
	}

	State front()
	{
		return v.front();
	}

	State pop_front()
	{
		v.pop_front();
	}

	bool empty()
	{
		if (v.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	State at(int h)
	{
		return v.at(h);
	}

	void push_intelligently(int x, int y, int l, int X, int Y, int C , AdvancedQueue & frontr, bool& shallIcontinue)
	{

		int finalx, finaly;
		//X -> Y
			if( y+x <= Y )
			{
				finalx = 0;
				finaly = y + x;
				if (!frontr.contains(finalx,finaly))
				{
					frontr.push_back(finalx, finaly, l+1);
				}	

				if(finalx == C || finaly == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}

			}
			else
			{
				finalx = x - (Y - y);
				finaly = Y;
				if (!frontr.contains(finalx,finaly))
				{
					frontr.push_back(finalx, finaly, l+1);
				}

				if(finalx == C || finaly == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}
			}
				

		// Y -> X

			if( x+y <= X )
			{
				finalx = x + y;
				finaly = 0;
				if (!frontr.contains(finalx,finaly))
				{
					frontr.push_back(finalx, finaly, l+1);
				}

				if(finalx == C || finaly == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}
			}
			else
			{
				finalx = X;
				finaly = y - (X - x);
				if (!frontr.contains(finalx,finaly))
				{
					frontr.push_back(finalx, finaly, l+1);
				}

				if(finalx == C || finaly == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}
			}


		// Empty X
			if (!frontr.contains(0,y))
				{
					frontr.push_back(0, y , l+1);
				}

			if(0 == C || y == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}



		// Empty Y
			if (!frontr.contains(x,0))
				{
					frontr.push_back(x, 0, l+1);
				}
			
			if(x == C || 0 == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}

		// Fill X
			if (!frontr.contains(X, y))
				{
					frontr.push_back(X, y, l+1);
				}
			
			if(X == C || y == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}

		// Fill Y
			if (!frontr.contains(x, Y))
				{
					frontr.push_back(x, Y, l+1);
				}
			if(x == C || Y == C)
				{
					shallIcontinue = false;
					answer = l+1;
				}

	}

};

int HCF(int A, int B)
{ 
	int temp1 = max(A,B);
	int temp2 = min(A,B);
	int  r = temp1%temp2;
	if (r == 0)
	{
		return temp2;
	}
	else
	{
		return HCF(temp2,r);
	}

}




int main(int argc, char const *argv[])
{
	int Testcases;
	scanf("%d",&Testcases);
	for(int z = 0;z<Testcases;z++)
	{
		int X,Y,C;
		cin >> X;
		cin >> Y;
		cin >> C;

		if (C%HCF(X,Y) != 0)
		{
			cout << "not possible"<<endl;
			continue;
		}
		int k = 0;
		AdvancedQueue Frontier;
		Frontier.push_back(0,0,0);
		bool shallIcontinue = true;

		while(!Frontier.empty() && shallIcontinue == true)
		{
			State myHead;
			myHead = Frontier.at(k);
			k++;
			Frontier.push_intelligently(myHead.first, myHead.second, myHead.level, X, Y, C, Frontier, shallIcontinue);
		}

		cout<<answer<<endl;

	}
	return 0;
}

 

