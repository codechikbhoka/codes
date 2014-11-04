#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long int yippi = 0;

struct node
{


 node * leftChild;
 node * rightChild;
 double frequency;

};


vector<node> nodeArray;// Use nodeArray to record all the nodes that may be created in the whole process


vector<node>::iterator  extractMin()
{ 
 double temp = 1000000;
 vector<node>::iterator i1, pos;
 for(i1 = nodeArray.begin();i1!=nodeArray.end() - 1;i1++)
 {

  if(temp>(*i1).frequency + (*(i1 + 1)).frequency)
  {
   pos = i1;
   temp = (*i1).frequency + (*(i1 + 1)).frequency;
  }
  
 }

return pos;
}



void getHuffmanTree()
{

  while(!nodeArray.empty())
  {

    vector<node>::iterator pos1;
    node* tempNode = new node;
    node* tempNode1 = new node;
    node* tempNode2 = new node; 
    pos1 = extractMin();

    tempNode1->frequency = (*pos1).frequency;
    tempNode2->frequency = (*(pos1 + 1)).frequency;

    tempNode->leftChild = tempNode1;
    tempNode->rightChild = tempNode2;
    tempNode->frequency = (*pos1).frequency + (*(pos1 + 1)).frequency + 1;
    yippi = yippi + tempNode->frequency;
    *pos1 = *tempNode ;
    nodeArray.erase(pos1 + 1);
      if(nodeArray.size() == 1)//only the root node exsits
      {
        break;
      }

    }

  }

  void insertNode(long long int tempDouble)
  {
    node tempNode;
    tempNode.frequency = tempDouble;
    yippi = yippi + tempDouble;
    tempNode.leftChild = NULL;
    tempNode.rightChild = NULL;
    nodeArray.push_back(tempNode);
  }

int main()
  {
    long long int N;
    cin >> N ;
    for (long long int i = 0; i < N; ++i)
    {
        long long int M, K=0, Z, P;
        cin >> M;
        cin >> Z;


        for (long long int i = 0; i < Z; ++i)
        {
          cin >> P;
          insertNode(P-K-1);
          K = P;
        }
      
      insertNode(M-K);

      vector<node>::iterator i1;
      // for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++)
      // {
      //   cout << (*i1).frequency << " " ;
      // }
      // cout << endl;

      getHuffmanTree();

      i1 = nodeArray.begin();
      yippi = yippi - (*i1).frequency ;
      cout << yippi << endl;
      yippi = 0;
      nodeArray.clear();

    }

    return 0;
  }