#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>
using namespace std;

/**
树括号表示法： A(B,C(F,G,H),D,E(I,J))
（1）从左到右扫描树的括号表示；
（2）每当遇到左括号时，其前一个结点进栈，并读入下一个符号；
（3）每当遇到右括号时，栈顶元素出栈。说明以栈顶元素为根的树（子树）构造完毕，此时若栈为空，算法结束，否则读入下一个符号
（4）每当遇到结点时，则它一定为栈顶元素的子女，将其挂到栈顶元素的某子女位置上，并读入下一个符号；
（5）每当遇到“，”，则略过该符号，并读入下一个符号。
**/


class Tree{

	public: 
		Tree(char v);
		void addChild(Tree* node);
		char getValue();
		int size();
	private:
		char value;
};

Tree::Tree(char c):value(c){
};


void Tree::addChild(Tree* node){
	cout << "增加子节点：" << node->getValue() << endl;
};

char Tree::getValue(){
	return value;
};


int main(int argc, char const *argv[])
{
	
	char endSymble =  '\0';
	char str[] = "A(B,C(F,G,H),D,E(I,J))";
	
	for(int i=0;i<sizeof(str);i++){

		if(str[i] == endSymble){
			printf("\n");	
			//结束
			break;
		} else if(str[i] == '('){
			//左括号

		} else if(str[i] == ')' ){
			//右括号

		} else if(str[i] == ',' ){
			//逗号

		} else{
			Tree* node = new Tree(str[i]);
			// stack[i] = node;
			printf("%c", node->getValue());	
		}
	}
	return 0;
}
