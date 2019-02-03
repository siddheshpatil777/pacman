//#include "array.h"
#include "queue.h"
#include <iostream>
using namespace std;
int main(){
	Queue<int> a(10);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	int r=a.get();
	a.get();
	a.get();
	a.get();
	a.get();
	cout<<a.length()<<"\n";
	if(a.empty()){
		cout<<"empty"<<"\n";
	}
	else{
		cout<<"full"<<"\n";
	}
	a.print();
	return 0;
}
