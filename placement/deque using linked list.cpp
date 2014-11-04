#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct queueNode
{
	TreeNode* data;
	queueNode* prev;
	queueNode* next;

	queueNode(TreeNode* x)
	{
		data = x;
		prev = NULL;
		next = NULL;
	}
};


class myQueue
{

public:

	queueNode* head;
	queueNode* tail;

	myQueue()
	{
		head = NULL;
		tail = NULL;
	}

	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}

		return false;
	}

	void push_back(TreeNode* data)
	{
		queueNode* newNode = new queueNode(data);

		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}		
	}

	void push_front(TreeNode* data)
	{
		queueNode* newNode = new queueNode(data);

		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = tail->next;
		}		
	}

	queueNode* pop_back()
	{
		queueNode* result = head;
		head = head->next;
		
		if (head != NULL)
		{
			head->prev = NULL;	
		}
		else
		{	
			tail = NULL;
		}
		
		return result;
	}

	queueNode* pop_front()
	{
		queueNode* result = tail;

		tail = tail->prev;
		if (tail != NULL)
		{
			tail->next = NULL;	
		}
		else
		{	
			head = NULL;
		}
		
		return result;
	}

	

	void printQueue()
	{
		queueNode* temp = head;
		while(temp)
		{
			cout << temp->data->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};