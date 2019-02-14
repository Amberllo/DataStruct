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
	};

	void addChild(BiSearchTree* child){
		addChild(this,child);
	}

	

	int getValue(){
		return value;
	}

	BiSearchTree* getLeft(){
		return left;
	}

	BiSearchTree* getRight(){
		return right;
	}

protected:
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
			if(parent->getRight()==NULL){
				parent->setRight(child);
			}else{
				addChild(parent->getRight(),child);
			}
	
		} 

	}

private:
	int value;
	BiSearchTree* left;
	BiSearchTree* right;

};

int main(int argc, char const *argv[]){
	BiSearchTree root = BiSearchTree(10);
	BiSearchTree node1 = BiSearchTree(5);
	BiSearchTree node2 = BiSearchTree(15);
	BiSearchTree node3 = BiSearchTree(20);

	root.addChild(&node1);
	root.addChild(&node3);
	root.addChild(&node2);
	

	cout<< root.getLeft()-> getValue()<< endl;
	cout<< root.getRight()-> getValue()<< endl;
	cout<< root.getRight()-> getLeft() -> getValue()<< endl;
}