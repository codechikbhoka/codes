#include <bits/stdc++.h>
using namespace std;

int Evaluate(string s){
	stack <char>  op;
	stack <int>   num;
	int n1,n2;
	map<char,int> priority;
	priority['-']=1;
	priority['+']=1;
	priority['*']=2;
	priority['/']=2;
	priority['^']=3;
	for(int i=0;i<s.size();i++){
		//cout<<"s[i]"<<s[i]<<endl;
		if(s[i]=='('){
			op.push('(');			
		}
		else if(s[i]==')'){
			while(!op.empty() && op.top()!='('){
				n2=num.top();	num.pop();
				n1=num.top();	num.pop();
				if(op.top()=='+')			num.push(n1+n2);
				else if(op.top()=='-')		num.push(n1-n2);
				else if(op.top()=='*')		num.push(n1*n2);
				else if(op.top()=='/')		num.push(n1/n2);
				op.pop();
			}
			op.pop();
		}
		else{			
			if(s[i]>='0' && s[i]<='9'){
				n1=0;
				for(;i<s.size()&&s[i]>='0'&&s[i]<='9';i++){
					n1 = n1*10+int(s[i]-'0');
				}	
				i--;			
				num.push(n1);
			}else{
				if(op.empty()|| priority[s[i]]>priority[op.top()]){
					op.push(s[i]);
				}else {
					while(!op.empty()&&op.top()!='(' && priority[op.top()]>= priority[s[i]]){
						n2=num.top();	num.pop();
						n1=num.top();	num.pop();
						if(op.top()=='+')			num.push(n1+n2);
						else if(op.top()=='-')		num.push(n1-n2);
						else if(op.top()=='*')		num.push(n1*n2);
						else if(op.top()=='/')		num.push(n1/n2);
						op.pop();						
		//				cout<<num.top()<<endl;
					}
					op.push(s[i]);
				}
			}
		}
	}
	while(!op.empty()){
		n2=num.top();	num.pop();
		n1=num.top();	num.pop();
		if(op.top()=='+')			num.push(n1+n2);
		else if(op.top()=='-')		num.push(n1-n2);
		else if(op.top()=='*')		num.push(n1*n2);
		else if(op.top()=='/')		num.push(n1/n2);
		op.pop();						
	}
	return (num.top());
}
int main(){
	string s;
	cin>>s;
	cout<<Evaluate(s)<<endl;
return 0;	
}











