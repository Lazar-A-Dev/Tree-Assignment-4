#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	Node* left, * right, * parent;
	int info;
public:
	Node();
	Node(int info);
	~Node();
	void Print();

	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	Node* GetParent() { return parent; }
	int GetInfo() { return info; }
};

