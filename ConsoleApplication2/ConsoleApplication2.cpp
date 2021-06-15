#include "stdafx.h"
#include <iostream>
#include<conio.h>
#include"Stack.h"
#include"string.h"
#include<fstream>
using namespace std;
bool DelimeterMatch(){
	char ch;
	Stack<char> stack;
	ifstream fin("text.txt");
	fin >> ch;
	while (fin.eof() == false){
		if (ch == '(' || ch == '{' || ch == '['){
			stack.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']'){
			char d = stack.pop();
			switch (ch){
			case ')':
				if (d != '(')
					return false;
				break;
			case '}':
				if (d != '{')
					return false;
				break;
			case ']':
				if (d != '[')
					return false;
				break;
			}
		}
		else if (ch == '/'){
			fin >> ch;
			if (ch == '*'){
				while (ch != '*'){
				commented:
					fin >> ch;
					if (fin.eof() == true)
						return false;
				}
				fin >> ch;
				if (ch != '/')
					goto commented;
			}
		}
			fin >> ch;
	}
	return true;
}
int main(){
	if(DelimeterMatch())
		cout<<"true";
	else
		cout << "false";
	_getch();
}

