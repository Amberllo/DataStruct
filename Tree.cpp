#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>
// #include "Stack.h"

using namespace std;

/**
树括号表示法： A(B,C(F,G,H),D,E(I,J))
（1）从左到右扫描树的括号表示；
（2）每当遇到左括号时，其前一个结点进栈，并读入下一个符号；
（3）每当遇到右括号时，栈顶元素出栈。说明以栈顶元素为根的树（子树）构造完毕，此时若栈为空，算法结束，否则读入下一个符号
（4）每当遇到结点时，则它一定为栈顶元素的子女，将其挂到栈顶元素的某子女位置上，并读入下一个符号；
（5）每当遇到“，”，则略过该符号，并读入下一个符号。
*/
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

class Tree{

	public: 
		Tree(Node* v);
		Tree(char expression[]);
		void addChild(Node* node);
		char getValue();
		
	private:
		char value;
		Node* header;
};




// //括号表示法构造函数
// Tree::Tree(char expression[]){

// 	Stack stack = Stack();

// 	char endSymble =  '\0';
// 	int size = strlen(expression);
// 	for(int i=0;i<size;i++) {

// 		if(expression[i] == endSymble){
// 			break;
// 			//结束
// 		} else if(expression[i] == '('){
// 			//左括号

// 		} else if(expression[i] == ')' ){
// 			//右括号

// 		} else if(expression[i] == ',' ){
// 			//逗号

// 		} else {
// 			Node* node = new Node(expression[i]);
// 			stack.push(node);
// 			// printf("%c", node->getValue());	
// 		}
// 	}
	
// };

int main(int argc, char const *argv[])
{
	
	char str[] = "A(B,C(F,G,H),D,E(I,J))";
	// Tree tree = Tree(str);
	
	
}	
	
