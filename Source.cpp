#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include<vector>
#include<stack>

using namespace std;

bool isMatchingPair(char opening, char closing) {
	if (opening == '(' && closing == ')')
		return true;
	else if (opening == '{' && closing == '}')
		return true;
	else if (opening == '[' && closing == ']')
		return true;
	return false;
}

bool checkValidString(string str) {
	
	stack<string> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			s.push(str);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (s.empty() || !isMatchingPair(s.top(), str[i])) {
				return false;
			}
			else {
				s.pop();
			}
		}
	}
	return s.empty();
}

int main() {
	string str;
	cout << "Введите строку со скобками: ";
	getline(cin, str);
	if (checkValidString(str)) {
		cout << "Скобки расставлены корректно" << endl;
	}
	else {
		cout << "Ошибка в расстановке скобок" << endl;
	}

	return 0;
}