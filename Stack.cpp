#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>
using namespace std;


class Node {

	public:
		Node(char v);
		void setPre(Node* node);
		Node* getPre();
		char getValue();
	private:
		char value;
		Node* pre;
};

Node::Node(char v):value(v){
	pre = NULL;
}

void Node::setPre(Node* node){
	pre = node;
}

Node* Node::getPre(){
	return pre;
}

char Node::getValue(){
	return value;
}

class Stack{
	public:
		Stack();
		void push(Node* node);
		Node* peek();
		Node* pop();
		void clean();
		bool isEmpry();
		void printStack();
	private:
		Node* header;
		Node* cur;
};

Stack::Stack(){
	header = new Node('\0');
	cur = header;
};

void Stack::push(Node* node){
	if(cur==header){
		node->setPre(header);
	}else{
		node->setPre(cur);
	}
	cur = node;
};

Node* Stack::peek(){
	if(isEmpry()){
		return NULL;
	}
	return cur;
};

Node* Stack::pop(){
	if(isEmpry()){
		return NULL;
	}
	Node* temp = cur;
	cur = (cur->getPre());
	return temp;
};

void Stack::clean(){
	cur = header;
};

bool Stack::isEmpry(){
	return cur == header;
};

int main(int argc, char const *argv[])
{
	/* code */

	Node* nodeA = new Node('a');
	Node* nodeB = new Node('b');

	Stack stack;
	stack.push(nodeA);
	stack.push(nodeB);
	
	printf("%c\n", stack.pop()->getValue());
	printf("%c\n", stack.pop()->getValue());
	printf("%c\n", stack.pop()->getValue());

	

	return 0;
}