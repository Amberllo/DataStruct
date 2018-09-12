#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>
using namespace std;


class Node{

	public: 
		Node(char v);
		Node* getChildRight();
		Node* getChildLeft();
		void setChildLeft(Node* node);
		void setChildRight(Node* node);
		char getValue();
	private:
		char value;
		Node* childLeft;
		Node* childRight;
};




Node::Node(char c):value(c){
}

Node* Node::getChildRight(){
	return childRight;
}

Node* Node::getChildLeft(){
	return childLeft;
}

void Node::setChildLeft(Node* node){
	childLeft = node;
}

void Node::setChildRight(Node* node){
	childRight = node;
}

char Node::getValue(){
	return value;
}

class BiTree{

	public:
		int size();
		void setRoot(Node* node);
		Node* getRoot();
	private:
		Node* root;
};

int BiTree::size(){
	return 0;
}

Node* BiTree::getRoot(){
	return root;
}

void BiTree::setRoot(Node* node){
	root = node;
} 

BiTree* makeTree(){
	Node* nodeA = new Node('a');
	Node* nodeB = new Node('b');
	Node* nodeC = new Node('c');
	Node* nodeD = new Node('d');
	Node* nodeE = new Node('e');
	Node* nodeF = new Node('f');
	Node* nodeG = new Node('g');
	Node* nodeH = new Node('h');
	Node* nodeI = new Node('i');
	
	nodeA -> setChildLeft(nodeB);
	nodeA -> setChildRight(nodeC);

	nodeB -> setChildLeft(nodeD);
	nodeB -> setChildRight(nodeF);

	nodeC -> setChildLeft(nodeG);
	nodeC -> setChildRight(nodeI);

	nodeD -> setChildLeft(NULL);
	nodeD -> setChildRight(NULL);

	nodeE -> setChildLeft(NULL);
	nodeE -> setChildRight(NULL);

	nodeF -> setChildLeft(nodeE);
	nodeF -> setChildRight(NULL);

	nodeG -> setChildLeft(NULL);
	nodeG -> setChildRight(nodeH);

	nodeH -> setChildLeft(NULL);
	nodeH -> setChildRight(NULL);

	nodeI -> setChildLeft(NULL);
	nodeI -> setChildRight(NULL);

	BiTree* tree = new BiTree();
	tree->setRoot(nodeA);

	return tree;
}

//先序遍历 中左右
void readFirst(Node* node){

	printf("%c", node -> getValue());
	if(node->getChildLeft() != NULL){
		readFirst(node -> getChildLeft());
	}
	if(node->getChildRight() != NULL){
		readFirst(node -> getChildRight());
	}
}

//中序遍历 左中右
void readMiddle(Node* node){
	if(node->getChildLeft() != NULL){
		readMiddle(node -> getChildLeft());
	}
	printf("%c", node -> getValue());
	if(node->getChildRight() != NULL){
		readMiddle(node -> getChildRight());
	}
}

//后序遍历 左右中
void readLast(Node* node){
	if(node->getChildLeft() != NULL){
		readLast(node -> getChildLeft());
	}
	if(node->getChildRight() != NULL){
		readLast(node -> getChildRight());
	}
	printf("%c", node -> getValue());
}

int main(int argc, char const *argv[])
{
	
	
	BiTree* tree = makeTree();

	cout << "先序遍历：";	
	readFirst(tree->getRoot());
	cout << endl;

	cout << "中序遍历：";	
	readMiddle(tree->getRoot());
	cout << endl;

	cout << "后序遍历：";	
	readLast(tree->getRoot());
	cout << endl;

	return 0;
}
