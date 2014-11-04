#include <iostream>
#include "Rubik.h"
#include <deque>
using namespace std;

#define WHITE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
#define BLUE 4
#define ORANGE 5



struct AdvancedQueue
{

private:

	deque<Rubik> v;

public:

	void push_back(Rubik A)
	{
		v.push_back(A);
	}

	bool contains(Rubik A)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (v.at(i) == A)	
			{
				return true;
			}
		}

		return false;
	}

	Rubik front()
	{
		return v.front();
	}

	Rubik pop_front()
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

	Rubik at(int h)
	{
		return v.at(h);
	}

	void push_intelligently(Rubik A, AdvancedQueue& frontr, bool& shallIcontinue)
	{

		Rubik finalRubik ;
		for (int i = 0; i < 12; ++i)
		{
			put(A, finalRubik, i);
			if (!frontr.contains(finalRubik))
			{
				if(finalRubik.solved())
				{
					finalRubik.lastturn = A.lastturn*10 + i;
					shallIcontinue = false;
					cout << finalRubik.lastturn <<" reached" << endl;
					return;
				}
				else
				{
					finalRubik.lastturn = A.lastturn*10 + i;
					cout << finalRubik.lastturn << endl;
					frontr.push_back(finalRubik);
				}
				
			}
		}
			

	}

};


/*
0 : R
1 : R'
2 : L
3 : L'
4 : F
5 : F'
6 : B
7 : B'
8 : T
9 : T'
10 : D
11 : D' 
*/


int main(int argc, char const *argv[])
{
	Rubik rootRubik;
	rootRubik.setFront(WHITE,BLUE,BLUE,RED);
	rootRubik.setLeft(BLUE,GREEN,GREEN,WHITE);
	rootRubik.setRight(RED,BLUE,GREEN,YELLOW);
	rootRubik.setBack(ORANGE,GREEN,ORANGE,ORANGE);
	rootRubik.setTop(YELLOW,WHITE,ORANGE,YELLOW);
	rootRubik.setBottom(RED,WHITE,YELLOW,RED);

	//rootRubik.rotateleft();
	//rootRubik.rotaterightdash();
	//rootRubik.rotatetop();

	AdvancedQueue Frontier;
	Frontier.push_back(rootRubik);
	bool shallIcontinue = true;
	int k=0;

	if(rootRubik.solved())
		{
			shallIcontinue = false;
			cout << "-- reached" << endl;
			return 0;
		}

	

	while(!Frontier.empty() && shallIcontinue == true)
	{
		Rubik myHead;
		myHead = Frontier.at(k);
		k++;
		Frontier.push_intelligently(myHead, Frontier, shallIcontinue);
	}

	return 0;
}