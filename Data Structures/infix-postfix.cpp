#include <iostream>
#include <stack>

using std::cout;
using std::stack;
using std::string;

int precedence(char p){

	if(p == '^')
		return 3;
	if(p == '*' || p == '/' || p == '%')
		return 2;
	if(p == '+' || p == '-')
		return 1;
	
	return -1;
}
string infix_to_postfix(string& exp){

	string postfix = "";
	int i = 0;

	stack<char> s;
	s.push('C');


	while(exp[i] != '\0'){

		if(isalnum(exp[i])){
			postfix+=exp[i];
		}

		else if(exp[i] == '(')
			s.push(exp[i]);

		else if(exp[i] == ')'){

			while(s.top()!= 'C' && s.top() != '('){
				char x = s.top();
				s.pop();
				postfix += x;
			}

			if(s.top() == '('){
				char x = s.top();
				s.pop();
			}
		}

		else{

			while(s.top() != 'C' && precedence(exp[i]) <= precedence(s.top())){
				char x = s.top();
				s.pop();
				postfix+=x;
			}

			s.push(exp[i]);
		}
		i++;
	}

	while(s.top()!='C'){
		char x = s.top();
		s.pop();
		postfix+=x;
	}
	return postfix;

}

int main(void){


	string exp = "a+b*(c^d-e)^(f+g*h)-i";

	string postfix = infix_to_postfix(exp);

	cout << postfix << "\n";


	return 0;
}
