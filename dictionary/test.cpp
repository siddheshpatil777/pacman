#include "dictionary.h"

#include<iostream>
using namespace std;
 
int main(){
	cout<<"hi";
	int s;
	static Dictionary<int> d(2);
	d.add("test",69);
	d.add("ee",69);
	//d.add("teset",69);
	d.view();
	cout<<d["test"];
	return 0;
}
