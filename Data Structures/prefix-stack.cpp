#include <iostream>
#include <stack>
#include <algorithm>

using std::cout;
using std::string;
using std::stack;

int prefix_evaluator(string& exp){
	int i = 0;
	
	stack<int> s;

	while(exp[i]!='\0'){


		if(isdigit(exp[i])){
			s.push(exp[i]-'0');
		}
		else{
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();

			switch(exp[i]){
				case '+':  	s.push(x+y);
							break;
				case '-': 	s.push(x-y);
							break;
				case '/': 	s.push(x/y);
							break;
				case '*': 	s.push(x*y);
							break;
			}
		}
		i++;
	}
	
	return s.top();

}
int main(void){


	string exp = "-+/2*43*45*62";

	reverse(exp.begin(),exp.end());
	
	int res = prefix_evaluator(exp);

	cout << res << "\n";

	return 0;
}