#include <stdio.h>
#include <stdlib.h>
struct node
{
	int index;
	struct node* left;
	struct node* right;
};

struct node queue[100];

int top = 0;
int tail = 0;

void push(struct node* y)
{
	tail++;
	queue[tail] = *y;
}

struct node pop()
{
	top++;
	return queue[top];
}


struct node* rightBrother(struct node* root, struct node* x)   //returns index of the right brother, -1 if doesn't exist
{
	push(root);
	struct node* tempy = (struct node*) malloc(sizeof(struct node));
	tempy->index = -1;
	tempy->left = NULL;
	tempy->right = NULL;
	push(tempy);
	
	struct node *k = (struct node*) malloc(sizeof(struct node));
	while(tail != top)
	{
		*k = pop();
		if(k->index == x->index)
		{
			struct node* temp = (struct node*) malloc(sizeof(struct node));
			*temp = pop();
			return temp;
		}
		else if (k->index == -1)
		{
			struct node* temp2 = (struct node*) malloc(sizeof(struct node));
			temp2->index = -1;
			temp2->left = NULL;
			temp2->right = NULL;
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

	struct node* temp3 = (struct node*) malloc(sizeof(struct node));
	temp3->index = -1;
	temp3->left = NULL;
	temp3->right = NULL;
	return temp3; 
} 

int main()
{

	struct node arr[7];
	int i;
	for (i = 0; i < 7; ++i)
	{
		arr[i].index = i;
		arr[i].left = NULL;
		arr[i].right = NULL;
	}

	for (i = 0; i < 3; ++i)
		{
			arr[i].left = arr + 2*i +1;
			arr[i].right = arr + 2*i +2;

		}	

	printf("%d\n",(rightBrother(arr, arr + 2))->index);
	

	return 0;
}