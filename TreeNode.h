#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
class TreeNode
{
protected:
	Node* root;
	int size;
	int leafNodes;
	int closestLeaf, ost;
public:

	TreeNode();
	~TreeNode();
	void DeleteTree(Node* p);
	void Insert(Node p);
	void Insert(int p);
	Node* FindNode(int info);

	int GetSingleLeafNodes() { return leafNodes; }//vraca koliko ima cvorova sa jednim listom
	void LeafNodeCount();
	void LeafNodeCount(Node* p);

	int GetClosestLeaf() { return closestLeaf; }//Vraca cvor koja je najblza zadatoj vrednosti
	void FindClosestValueLeaf(int value);
	void FindClosestValueLeaf(Node* p, int value);

	//Print
	void PostOrder();
	void PostOrder(Node* p);
	void InOrder();
	void InOrder(Node* p);
	void PreOrder();
	void PreOrder(Node* p);
};

