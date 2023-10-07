#include "TreeNode.h"
TreeNode::TreeNode() {
	root = NULL;
	size = 0;
	leafNodes = 0;
	closestLeaf = 0;
	ost = 0;
}

TreeNode::~TreeNode() {
	DeleteTree(root);
}

void TreeNode::DeleteTree(Node* p) {
	if (p != NULL) {
		DeleteTree(p->GetLeft());
		DeleteTree(p->GetRight());
		delete p;
	}
}

void TreeNode::Insert(Node p) {
	if (root == NULL) {
		root = new Node(p.GetInfo());
	}
	else {
		Node* next = root;
		Node* prev = NULL;

		while (next != NULL) {
			prev = next;
			if (next->GetInfo() > p.GetInfo()) {
				next = next->GetLeft();
			}
			else if (next->GetInfo() < p.GetInfo()) {
				next = next->GetRight();
			}
		}

		if (prev->GetInfo() > p.GetInfo()) {
			prev->left = new Node(p.GetInfo());
		}
		else if (prev->info < p.GetInfo()) {
			prev->right = new Node(p.GetInfo());
		}
	}
}

void TreeNode::Insert(int p) {
	if (root == NULL) {
		root = new Node(p);
		size = 1;
	}
	else {
		Node* next = root;
		Node* prev = NULL;

		while (next != NULL) {
			prev = next;
			if (next->GetInfo() > p) {
				next = next->GetLeft();
			}
			else if (next->GetInfo() < p) {
				next = next->GetRight();
			}
		}

		if (prev->GetInfo() > p) {
			prev->left = new Node(p);
			size++;
		}
		else if (prev->info < p) {
			prev->right = new Node(p);
			size++;
		}
		else return;
	}
}

Node* TreeNode::FindNode(int info) {
	Node* tmp = root;
	while (tmp != NULL && tmp->GetInfo() != info) {
		tmp = tmp->GetLeft();
	}

	if(tmp->GetInfo() == info)
	return tmp;
}

void TreeNode::LeafNodeCount() {
	LeafNodeCount(root);
}

void TreeNode::LeafNodeCount(Node* p) {
	if (p != NULL) {
		if (p->left == NULL && p->right != NULL) 
			leafNodes++;
		
		else if (p->right == NULL && p->left != NULL) 
			leafNodes++;
		
		LeafNodeCount(p->left);
		LeafNodeCount(p->right);
	}
}

void TreeNode::FindClosestValueLeaf(int value) {
	closestLeaf = root->GetInfo();
	ost = root->GetInfo() - value;
	if (ost < 0)
		ost *= (-1);
	FindClosestValueLeaf(root, value);
}

void TreeNode::FindClosestValueLeaf(Node*p, int value) {
	if (p != NULL) {
		if (p->GetInfo() - value == 0)
			closestLeaf = p->GetInfo();

		else if (p->GetInfo() - value > 0) {
			if (ost > p->GetInfo() - value) {
				ost = p->GetInfo() - value;
				closestLeaf = p->GetInfo();
			}
		}
		else if (p->GetInfo() - value < 0) {
			if (ost > (p->GetInfo() - value)*(-1)) {
				ost = (p->GetInfo() - value)*(-1);
				closestLeaf = p->GetInfo();
			}
		}

		FindClosestValueLeaf(p->left, value);
		FindClosestValueLeaf(p->right, value);
	}
}

void TreeNode::PostOrder() {
	cout << "PostOrder: " << endl;
	PostOrder(root);
}

void TreeNode::PostOrder(Node* p) {
	if (p != NULL) {
		PostOrder(p->GetLeft());
		PostOrder(p->GetRight());
		p->Print();
	}
}

void TreeNode::InOrder() {
	cout << "InOrder: " << endl;
	InOrder(root);
}

void TreeNode::InOrder(Node* p) {
	if (p != NULL) {
		InOrder(p->GetLeft());
		p->Print();
		InOrder(p->GetRight());
	}
}

void TreeNode::PreOrder() {
	cout << "PreOrder: " << endl;
	PreOrder(root);
}

void TreeNode::PreOrder(Node* p) {
	if (p != NULL) {
		p->Print();
		PreOrder(p->GetLeft());
		PreOrder(p->GetRight());
	}
}