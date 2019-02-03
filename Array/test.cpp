#include "array.h"
#include <iostream>
using namespace std;
int main(){
	Array<int> a(10);
	a.push(3);
	a.push(10);
	a.push(56);
	//cout<<a[2];
	a.print();
	a.splice(1,1);
	a.push(11111);
	a.print();
	return 0;
}
