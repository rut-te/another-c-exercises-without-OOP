#include <iostream>
#include <ostream>
using namespace std;
#include "StackVector.h"

string infixToPostfix(string exp);
int calcPostfix(string postfix);

int main() {
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl;
	cout << "calculated value: " << calcPostfix(postfix) << endl;
	return 0;
}

string infixToPostfix(string exp)
{
	string str;
	StackVector<char> stk(1000);
	char sum[100];
	int j=0,m=0;
	for (int i = 0; i< exp.length(); i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if (sum)
			{
				for (int t = 0; t < j; t++)
				{
					str += sum[t];
				}
				str += " ";
				j = 0;
				
			}
			if (!stk.isEmpty()) {
				while (stk.top() == '+' || stk.top() == '-' || stk.top() == '*' || stk.top() == '/')
				{
					str += stk.pop();
					str += " ";
				}
			}
			stk.push(exp[i]);
		}
		else {
			if (exp[i] == '(')
			{
				stk.push(exp[i]);
			}
			else {
				if (exp[i] == ')')
				{
					if (sum)
					{
						for (int t = 0; t < j; t++)
						{
							str += sum[t];
							
						}
						str += " ";
						j = 0;
					}
					while (stk.top() != '(')
					{
						str += stk.pop();

					}
					stk.pop();
				}
				else {
					sum[j] = exp[i];
					j++;
				}
			}
		}
	}
	while (!stk.isEmpty())
	{
		str += " ";
		str += stk.pop();
		str += " ";
	}
	return str;
}
int calcPostfix(string postfix)
{
	StackVector<int> stk(1000);
	int j = 0;
	int arr[100];
	int sum = 0;
	for (int i = 0; i < postfix.length(); )
	{
		j = 0;
		bool flag = false;
		while (postfix[i] != ' ' && postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
		{
			sum = 0;
			arr[j] = postfix[i] - 48;
			i++;
			j++;
			flag = true;
		}
		
		if (postfix[i] == ' '&& i < postfix.length())
		{
			if (postfix[i-1]!='+'&& postfix[i - 1] != '-'&& postfix[i - 1] != '*'&& postfix[i - 1] != '/') {
				int k = 1;
				for (int m = j - 1; m >= 0; m--)
				{
					sum += arr[m] * k;
					k *= 10;
				}
				stk.push(sum);
				flag = false;
				
			}
			i++;
		}
		if(i < postfix.length()&&postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			int x = stk.pop();
			int y = stk.pop();
			switch (postfix[i]) {
			case '+':
				stk.push(y + x);
				break;

			case '-':
				stk.push(y - x);
				break;
			case '*':
				stk.push(y * x);
				break;
			case '/':
				stk.push(y / x);
				break;
			}	
			i++;
		}
		
	}
	return stk.pop();
}

//exemple:
//enter an infix expression as a string
//(5 + 3)* ((20 / 10) + (8 - 6))
//in postfix form : 5 3 + 20 10 / 8 6 - +*
//calculated value : 32
