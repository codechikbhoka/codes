#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};


int count(node* head)
{
	node* temp = new node();
	temp = head;
	int count = 0;
	while(temp)
	{
		temp->next;
		count++;
	}

	return count;
}

node* DLLtoBST(node **head_ref, int n)
{
	if (n <= 0)
	{
		return NULL;
	}
        
	node* left = DLLtoBST(head_ref, n/2);

	node* root = *head_ref;

	root->prev = left;

	*head_ref = (*head_ref)->next;

	root->next = DLLtoBST(head_ref, n - n/2 - 1);

	return root;
}


node* finalFunc(node *head)
{
	int n = count(head);

	return DLLtoBST(&head, n);
}


int main(int argc, char const *argv[])
{



	return 0;
}