#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>

using namespace std;

/**
* 堆栈
*/
class Stack{
	public:

	private:
		char stack[];
};

/**
* 二叉树，链实现
*/
class BiTree{

	public: 
		BiTree(char v){
			value = v;
		}

		BiTree* getChildRight(){
			return childRight;
		}

		BiTree* getChildLeft(){
			return childLeft;
		}

		void setChildLeft(BiTree* node){
			childLeft = node;
		}

		void setChildRight(BiTree* node){
			childRight = node;
		}

		char getValue(){
			return value;
		}

		void readFirst(){
			readRecursionFirst(this);
		}

		void readMiddle(){
			readRecursionMiddle(this);
		}

		void readLast(){
			readRecursionLast(this);
		}

	private:
		char value;
		BiTree* childLeft;
		BiTree* childRight;

		//先序遍历 中左右
		void readRecursionFirst(BiTree* node){

			printf("%c", node -> getValue());
			if(node->getChildLeft() != NULL){
				readRecursionFirst(node -> getChildLeft());
			}
			if(node->getChildRight() != NULL){
				readRecursionFirst(node -> getChildRight());
			}
		}

		//中序遍历 左中右
		void readRecursionMiddle(BiTree* node){
			if(node->getChildLeft() != NULL){
				readRecursionMiddle(node -> getChildLeft());
			}
			printf("%c", node -> getValue());
			if(node->getChildRight() != NULL){
				readRecursionMiddle(node -> getChildRight());
			}
		}

		//后序遍历 左右中
		void readRecursionLast(BiTree* node){
			if(node->getChildLeft() != NULL){
				readRecursionLast(node -> getChildLeft());
			}
			if(node->getChildRight() != NULL){
				readRecursionLast(node -> getChildRight());
			}
			printf("%c", node -> getValue());
		}
};




BiTree* makeTree(){
	BiTree* nodeA = new BiTree('a');
	BiTree* nodeB = new BiTree('b');
	BiTree* nodeC = new BiTree('c');
	BiTree* nodeD = new BiTree('d');
	BiTree* nodeE = new BiTree('e');
	BiTree* nodeF = new BiTree('f');
	BiTree* nodeG = new BiTree('g');
	BiTree* nodeH = new BiTree('h');
	BiTree* nodeI = new BiTree('i');
	
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

	return nodeA;
}



int main(int argc, char const *argv[])
{
	
	BiTree* tree = makeTree();

	cout << "先序遍历：";	
	tree->readFirst();
	cout << endl;

	cout << "中序遍历：";	
	tree->readMiddle();
	cout << endl;

	cout << "后序遍历：";	
	tree->readLast();
	cout << endl;

	return 0;
}
