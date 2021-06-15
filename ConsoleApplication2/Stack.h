#pragma once
#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

template<class T>
class Stack;

template <class T>
class node{
private:
	T data;
	node<T>* next;
public:
	node(const T& value, node<T>* nxt = nullptr){
		data = value;
		next = nxt;
	}
	~node(){
		if (next != NULL)
			delete next;
		else
			next = nullptr;
	}

	friend class Stack<T>;
};

template<class T>
class Stack{
private:
	node<T>* top;
public:
	Stack(node<T>* hd = nullptr){
		top = hd;
	}
	bool isEmpty(){
		if (top == nullptr)
			return true;
		return false;
	}
	void push(const T & element){
		if (isEmpty())
			top = new node<T>(element, nullptr);
		else{
			node<T>* temp = new node<T>(element, top);
			top = temp;
		}
	}
	T pop(){//return type not by reference as ret is created inside function and it will be destructed at the end of function
		if (!isEmpty()){
			T ret = top->data;
			node<T>* temp = top;
			top = top->next;
			temp->next = nullptr;
			delete temp;
			return ret;
		}
	}
	T & upnext(){
		if (!isEmpty())
			return top->data;
		else
			cout << endl << "Stack is empty | Junk Alert!";
	}
	~Stack(){
		if (top)
			delete top;
		else
			top = nullptr;
	}
};