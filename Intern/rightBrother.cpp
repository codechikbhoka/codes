#include <iostream>
using namespace std;

struct node
{
	int index;
	int data;
	node* left;
	node *right;

public:
	node(){}

	node(int index1, int data1, node* left1, node* right1)
	{
		this->index = index1;
		this->data = data1;
		this->left = left1;
		this->right = right1;
	}
};

node *queue = new node[100];
int top = 0;
int tail = 0;

void push(node* y)
{
	tail++;
	queue[tail] = *y;
}

node pop()
{
	top++;
	return queue[top];
}


node* rightBrother(node* root, node* x)   //returns index of the right brother, -1 if doesn't exist
{
	push(root);
	node* tempy = new node(-1,-1,NULL, NULL);
	push(tempy);
	
	node *k = new node();
	while(tail != top)
	{
		*k = pop();
		if(k->index == x->index)
		{
			node* temp = new node();
			*temp = pop();
			return temp;
		}
		else if (k->index == -1)
		{
			node* temp2 = new node(-1,-1,NULL, NULL);
			push(temp2);

		}
		else
		{
			if (k->left != NULL)
			{
				push(k->left);
			}
			if (k->right != NULL)
			{
				push(k->right);
			}
		}

	}

	node* temp3 = new node(-1,-1,NULL, NULL);
	return temp3; 
}

int main()
{

	node arr[7];
	for (int i = 0; i < 7; ++i)
	{
		arr[i].index = i;
		arr[i].data = i;
		arr[i].left = NULL;
		arr[i].right = NULL;
	}

	for (int i = 0; i < 3; ++i)
		{
			arr[i].left = arr + 2*i +1;
			arr[i].right = arr + 2*i +2;

		}	

	cout << (rightBrother(arr, arr + 1))->index << endl;
	

	return 0;
}