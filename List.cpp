#include <iostream>
using namespace std;
#define Initial_Capacity 10 //数组初始化容量

class List{
public:
	void add(int position, int value);
	void set(int position, int value);
	int get(int index);
	void remove(int index);
	void claer();
	int size();
	void printList();
	
};


class ArrayList : public List{
public : 
	

	ArrayList(){
		_size = Initial_Capacity;
	};

	
	void printList(){
		for(int i=0;i<_size;i++){

		}
	};

	int size(){
		return _size;
	}

private	:
	int _size = 0;
	int array[];
};


class LinkList : public List{
	public:
};

int main(){

	ArrayList arraylist;
	arraylist.printList();



	return 0;
}