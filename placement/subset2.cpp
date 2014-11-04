#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    
    return 0;
}

class Solution {
public:
    map<int, int> distinctIntegerFreq;
    
    vector<vector<int> > generateSubsets(map<int, int>::iterator it)
    {
        map<int, int>::iterator it2 = it;
        it2++;
        vector<vector<int> > arr;
        if(it2 == distinctIntegerFreq.end())
        {
            int lastElemFreq = it->second;
            for(int i=1; i<=lastElemFreq; i++)
            {
                for(int j=1 ; j<=i; j++)
                {
                    arr[i].push_back(it->first);
                }
            }
            return arr;
        }
        else
        {
            arr = generateSubsets(it2);
            
            vector<vector<int> > arr2;
            int currElemFreq = it->second;
            for(int i=1; i<=currElemFreq; i++)
            {
                for(int j=1 ; j<=i; j++)
                {
                    arr2[i].push_back(it->first);
                }
            }
            
            for(int i=1; i<=currElemFreq; i++)
            {
                for(int j=0 ; j<=arr.size(); j++)
                {
                   vector<int> AB = arr2[i];
                   AB.insert(AB.end(), arr[j].begin(), arr[j].end());
                   arr2.push_back(AB);
                }
            }
            
            return arr2;
            
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        for(int i=0;i< S.size();i++)
        {
            distinctIntegerFreq[i]++ ;
        }
        
     map<int, int>::iterator it=distinctIntegerFreq.begin();
     return generateSubsets(it);
        
    }
};