#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>

using namespace std;
class BiSearchTree {
public:
	BiSearchTree(int v){
		value = v;
		left = NULL;
		right = NULL;
	}

	void addChild(BiSearchTree* child){
		addChild(this,child);
	}

	void printFirst(){
		printFirst(this);
	}

	void printMiddle(){
		printMiddle(this);
	}

	void printLast(){
		printLast(this);
	}

	int getValue(){
		return value;
	}

	bool contains(int v){
		return contains(this, v);
	}
	
protected:

	//中序遍历，打印树（左中右）
	void printMiddle(BiSearchTree* node){
		if(node!=NULL){
			printMiddle(node->getLeft());
			printf("%d ", node->getValue());
			printMiddle(node->getRight());
		}
	}

	//中序遍历，打印树（中左右）
	void printFirst(BiSearchTree* node){
		if(node!=NULL){
			printf("%d ", node->getValue());
			printFirst(node->getLeft());
			printFirst(node->getRight());
		}
	}

	//后序遍历，打印树（左右中）
	void printLast(BiSearchTree* node){
		if(node!=NULL){
			printLast(node->getLeft());
			printLast(node->getRight());
			printf("%d ", node->getValue());
		}
	}	

	BiSearchTree* getLeft(){
		return left;
	}

	BiSearchTree* getRight(){
		return right;
	}

	void setLeft(BiSearchTree* l){
		left = l;
	};

	void setRight(BiSearchTree* r){
		right = r;
	};

	void addChild(BiSearchTree* parent, BiSearchTree* child){
		int childValue = child->getValue();
		int parentValue = parent->getValue();
		//不允许值相等
		if(childValue == parentValue){
			return;
		}

		if(childValue < parentValue){
			if(parent->getLeft() == NULL){
				parent->setLeft(child);
			}else{
				addChild(parent->getLeft(),child);
			}
			
		} else if(childValue > parentValue){
			if(parent->getRight() == NULL){
				parent->setRight(child);
			}else{
				addChild(parent->getRight(),child);
			}
	
		} 

	}

	bool contains(BiSearchTree* node, int v){
		if(node == NULL)return false;
		if(v == node->getValue())  {
			return true;
		}else if(v > node->getValue()){
			return contains(node->getRight(),v);
		}else {
			return contains(node->getLeft(),v); 
		}
	}

private:
	int value;
	BiSearchTree* left;
	BiSearchTree* right;

};

int main(int argc, char const *argv[]){
	BiSearchTree root = BiSearchTree(41);
	BiSearchTree node1 = BiSearchTree(22);
	BiSearchTree node2 = BiSearchTree(58);
	BiSearchTree node3 = BiSearchTree(15);
	BiSearchTree node4 = BiSearchTree(33);
	BiSearchTree node5 = BiSearchTree(50);
	BiSearchTree node6 = BiSearchTree(60);
	BiSearchTree node7 = BiSearchTree(13);
	BiSearchTree node8 = BiSearchTree(28);
	BiSearchTree node9 = BiSearchTree(37);
	BiSearchTree node10 = BiSearchTree(42);
	BiSearchTree node11 = BiSearchTree(53);

	root.addChild(&node1);
	root.addChild(&node2);
	root.addChild(&node3);
	root.addChild(&node4);
	root.addChild(&node5);
	root.addChild(&node6);
	root.addChild(&node7);
	root.addChild(&node8);
	root.addChild(&node9);
	root.addChild(&node10);
	root.addChild(&node11);

	root.printFirst();
	printf("\n");
	root.printMiddle();
	printf("\n");
	root.printLast();
	printf("\n");
	printf(" is contains :  %d\n", root.contains(53));
	
}