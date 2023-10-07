#include<iostream>
#include"TreeNode.h"
using namespace std;
void main() {
	TreeNode n;
	n.Insert(1);
	n.Insert(15);
	n.Insert(6);
	n.Insert(12);
	n.Insert(7);
	n.Insert(15);
	n.Insert(3);

	n.PreOrder();
	cout << endl;
	n.InOrder();
	cout << endl;
	n.PostOrder();
	cout << endl;
	//n.LeafNodeCount();
	//cout << "Broj cvora sa jednim listom: " << n.GetSingleLeafNodes() << endl;
	//n.FindClosestValueLeaf(4);
	//cout << "Broj najblizem broju 4 u stablu: " << n.GetClosestLeaf() << endl;
	//system("pause");
}