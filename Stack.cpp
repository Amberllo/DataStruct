#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>
using namespace std;

/**
* 链盏实现
*/
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

class Stack{
	public:
		Stack();
		void push(char v);
		char peek();
		char pop();
		void clean();
		bool isEmpty();
		void printStack();
	private:
		Node* header;
		Node* cur;
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

Stack::Stack(){
	header = new Node('\0');
	cur = header;
};

void Stack::push(char v){
	Node* node = new Node(v);
	if(cur==header){
		node->setPre(header);
	}else{
		node->setPre(cur);
	}
	cur = node;
};

char Stack::peek(){
	if(isEmpty()){
		return '\0';
	}
	return cur->getValue();
};

char Stack::pop(){
	if(isEmpty()){
		return '\0';
	}
	Node* temp = cur;
	cur = (cur->getPre());
	return temp->getValue();
};

void Stack::clean(){
	cur = header;
};

bool Stack::isEmpty(){
	return cur == header;
};

int main(int argc, char const *argv[])
{
	Stack stack;
	stack.push('a');
	stack.push('b');
	if(!stack.isEmpty()){
		printf("%c\n", stack.peek());
	}
	
	if(!stack.isEmpty()){
		printf("%c\n", stack.pop());
	}

	if(!stack.isEmpty()){
		printf("%c\n", stack.pop());
	}

	return 0;
}