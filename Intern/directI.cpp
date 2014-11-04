#include <iostream>
using namespace std;

struct Node
{
public:
	char data;
	Node* left;
	Node* right;

	Node(char x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};


string answer ;

void func(Node* root)
{
	if (root->left)
		func(root->left);
	if (root->right)	
	{
		func(root->right);
	}
	answer = answer + root->data;
}

Node* myFunction(string T)
{
	int temp = 1, i=0;
	Node* krr[T.length()];
	for (int i = 0; i < T.length(); ++i)
	{
		krr[i] = NULL;
	}

	Node* root = new Node(T[0]);
	krr[0] = root;

	while(i < T.length())
	{
		if ((krr[i])->data == '1')
		{
			Node* leftChild = new Node(T[temp]);
			krr[temp] = leftChild;
			temp++;

			Node* rightChild = new Node(T[temp]);
			krr[temp] = rightChild;
			temp++;

			krr[i]->left = leftChild;
			krr[i]->right = rightChild;
			i++;

		}
		else
		{
			i++;
		}

	}

	return krr[0];
}



int main(int argc, char const *argv[])
{

	Node *root = myFunction("111001000");
	func(root);
	cout << answer << endl;

	return 0;
}