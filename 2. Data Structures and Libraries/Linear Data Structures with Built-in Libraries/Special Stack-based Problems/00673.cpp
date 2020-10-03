#include <iostream>
#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	string input;
	stack<char> s;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, input);
		//cout << "input: " << input << endl;
		//cout << "size: " << s.size() << endl;

		if (/*!input.compare("\n") ||*/ !input.compare(""))
		{
			cout << "Yes" << endl;
			continue;
		}
		for (unsigned int j = 0; j < input.size(); j++)
		{
			if (input[j] == '(' || input[j] == '[')
			{
				//cout << "pushing " << input[j] << endl;
				s.push(input[j]);
				continue;
			}
			if (s.size() == 0)
			{
				if (input[j] == ')' || input[j] == ']')
				{
					//cout << "pushing " << input[j] << endl;
					s.push(input[j]);
				}
			}
			else if (s.size() > 0)
			{
				if (input[j] == ')' && s.top() == '(')
				{
					//cout << "poping " << s.top() << endl;
					s.pop();
				}
				else if (input[j] == ']' && s.top() == '[')
				{
					//cout << "poping " << s.top() << endl;
					s.pop();
				}
				else
				{
					s.push(input[j]);
				}
			}
		}
		if (s.empty())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		while(!s.empty())
		{
			s.pop();
		}
	}
	return 0;
}
