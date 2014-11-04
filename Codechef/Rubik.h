void turnClock(int &a, int &b, int &c, int &d)
{
	int temp = d;
	d = c;
	c = b;
	b = a;
	a = temp;
}

void turnClock(int &a, int &b, int &c, int &d, int &e, int &f, int &g, int &h)
{
	int temp = h;
	h = g;
	g = f;
	f = e;
	e = d;
	d = c;
	c = b;
	b = a;
	a = temp;
}

void turnAntiClock(int &a, int &b, int &c, int &d)
{
	int temp = a;
	a = b;
	b = c;
	c = d;
	d = temp;
}


void turnAntiClock(int &a, int &b, int &c, int &d, int &e, int &f, int &g, int &h)
{
	int temp = a;
	a = b;
	b = c;
	c = d;
	d = e;
	e = f;
	f = g;
	g = h;
	h = temp;
}

class Rubik
{

public:

	int lastturn;
	int front[4];
	int left[4];
	int right[4];
	int back[4];
	int bottom[4];
	int top[4];

	bool solved()
	{
		if 
		( 
			front[0] == front[1] &&
			front[1] == front[2] &&
			front[2] == front[3] &&

			left[0] == left[1] &&
			left[1] == left[2] &&
			left[2] == left[3] &&

			right[0] == right[1] &&
			right[1] == right[2] &&
			right[2] == right[3] &&

			top[0] == top[1] &&
			top[1] == top[2] &&
			top[2] == top[3] &&

			bottom[0] == bottom[1] &&
			bottom[1] == bottom[2] &&
			bottom[2] == bottom[3] &&

			back[0] == back[1] &&
			back[1] == back[2] &&
			back[2] == back[3]

		){return true;}

		else
		{
			return false;
		}
	}

	bool operator ==(Rubik B)
	{
		if 
		(
			front[0] == B.front[0] &&
			front[1] == B.front[1] &&
			front[2] == B.front[2] &&
			front[3] == B.front[3] &&
			
			back[0] == B.back[0] &&
			back[1] == B.back[1] &&
			back[2] == B.back[2] &&
			back[3] == B.back[3] &&

			right[0] == B.right[0] &&
			right[1] == B.right[1] &&
			right[2] == B.right[2] &&
			right[3] == B.right[3] &&

			left[0] == B.left[0] &&
			left[1] == B.left[1] &&
			left[2] == B.left[2] &&
			left[3] == B.left[3] &&

			top[0] == B.top[0] &&
			top[1] == B.top[1] &&
			top[2] == B.top[2] &&
			top[3] == B.top[3] &&

			bottom[0] == B.bottom[0] &&
			bottom[1] == B.bottom[1] &&
			bottom[2] == B.bottom[2] &&
			bottom[3] == B.bottom[3]
		)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Rubik()
	{
		lastturn = 0;
	}

	void setFront(int topleft, int topright, int bottomleft, int bottomright)
	{
		front[0] = topleft;
		front[1] = topright;
		front[2] = bottomleft;
		front[3] = bottomright;
	}

	void setLeft(int topleft, int topright, int bottomleft, int bottomright)
	{
		left[0] = topleft;
		left[1] = topright;
		left[2] = bottomleft;
		left[3] = bottomright;
	}

	void setRight(int topleft, int topright, int bottomleft, int bottomright)
	{
		right[0] = topleft;
		right[1] = topright;
		right[2] = bottomleft;
		right[3] = bottomright;
	}

	void setBack(int topleft, int topright, int bottomleft, int bottomright)
	{
		back[0] = topleft;
		back[1] = topright;
		back[2] = bottomleft;
		back[3] = bottomright;
	}

	void setBottom(int topleft, int topright, int bottomleft, int bottomright)
	{
		bottom[0] = topleft;
		bottom[1] = topright;
		bottom[2] = bottomleft;
		bottom[3] = bottomright;
	}

	void setTop(int topleft, int topright, int bottomleft, int bottomright)
	{
		top[0] = topleft;
		top[1] = topright;
		top[2] = bottomleft;
		top[3] = bottomright;
	}

	void rotateright()
	{
		turnClock(right[0], right[1], right[3], right[2]);
		turnClock(front[3],front[1], top[3], top[1], back[3], back[1], bottom[3], bottom[1]);
	}

	void rotaterightdash()
	{
		turnAntiClock(right[0], right[1], right[3], right[2]);
		turnAntiClock(front[3],front[1], top[3], top[1], back[3], back[1], bottom[3], bottom[1]);
	}

	void rotateleft()
	{
		turnClock(left[0], left[1], left[3], left[2]);
		turnClock(front[0],front[2], top[0], top[2], back[0], back[2], bottom[0], bottom[2]);
	}

	void rotateleftdash()
	{
		turnAntiClock(left[0], left[1], left[3], left[2]);
		turnAntiClock(front[0],front[2], top[0], top[2], back[0], back[2], bottom[0], bottom[2]);
	}

	void rotatefront()
	{
		turnClock(front[0], front[1], front[3], front[2]);
		turnClock(top[2], top[3], right[0], right[2], bottom[0], bottom[1], left[3], left[1]);
	}

	void rotatefrontdash()
	{
		turnAntiClock(front[0], front[1], front[3], front[2]);
		turnAntiClock(top[2], top[3], right[0], right[2], bottom[0], bottom[1], left[3], left[1]);
	}

	void rotateback()
	{
		turnClock(back[0], back[1], back[3], back[2]);
		turnClock(top[1], top[0], left[0], left[2], bottom[3], bottom[2], right[3], right[1]);
	}

	void rotatebackdash()
	{
		turnAntiClock(back[0], back[1], back[3], back[2]);
		turnAntiClock(top[1], top[0], left[0], left[2], bottom[3], bottom[2], right[3], right[1]);
	}

	void rotatetop()
	{
		turnClock(top[0], top[1], top[3], top[2]);
		turnClock(front[1], front[0], left[1], left[0], back[2], back[3], right[1], right[0]);
	}

	void rotatetopdash()
	{
		turnAntiClock(top[0], top[1], top[3], top[2]);
		turnAntiClock(front[1], front[0], left[1], left[0], back[2], back[3], right[1], right[0]);
	}

	void rotatebottom()
	{
		turnClock(bottom[0], bottom[1], bottom[3], bottom[2]);
		turnClock(front[2], front[3], right[2], right[3], back[1], back[0] , left[2], left[3]);
	}

	void rotatebottomdash()
	{
		turnAntiClock(bottom[0], bottom[1], bottom[3], bottom[2]);
		turnAntiClock(front[2], front[3], right[2], right[3], back[1], back[0] , left[2], left[3]);
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
void put(Rubik A, Rubik& B, int operation)
{
	switch(operation)
	{
		case 0:
			A.rotateright();
			B = A;
			break;

		case 1:
			A.rotaterightdash();
			B = A;
			break;

		case 2:
			A.rotateleft();
			B = A;
			break;

		case 3:
			A.rotateleftdash();
			B = A;
			break;
			
		case 4:
			A.rotatefront();
			B = A;
			break;
			
		case 5:
			A.rotatefrontdash();
			B = A;
			break;
			
		case 6:
			A.rotateback();
			B = A;
			break;
			
		case 7:
			A.rotatebackdash();
			B = A;
			break;
			
		case 8:
			A.rotatetop();
			B = A;
			break;
			
		case 9:
			A.rotatetopdash();
			B = A;
			break;
			
		case 10:
			A.rotatebottom();
			B = A;
			break;
			
		case 11:
			A.rotatebottomdash();
			B = A;
			break;

	}

}