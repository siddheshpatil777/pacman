#include <iostream>
#include <string.h>
using namespace std;
#include <math.h>
#define MAX_LENGTH 100
#define DEFAULT_VALUE 0
#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class Queue{
	// Private section
	bool queueMade;
	T *data;
	int max_length,len;
	int bottom;
	public:
		Queue();
		Queue(int _len);
		Queue(int _len ,T defaultValue);
		~Queue();
		void setLength(int _len);
		void setLength(int _len,T defaultValue);
		void push(T element);
		bool empty();
		T get();
		int length();
		void setDefaultValue(T _value);
		void print();
		void copyFrom(Queue<T> &a,T defaultValue);
		void clear(T defaultValue);
};
template<class T>
Queue<T>::Queue(){
	queueMade=false;
	bottom=0;
}
template<class T>
bool Queue<T>::empty(){
	if(len-1<=bottom || len>=max_length-1){
		return true;
	}
	else{
		return false;
	}
}
template<class T>
Queue<T>::Queue(int _len){
	max_length=_len;
	len=0;
	bottom=0;
	data=new T[max_length];
	queueMade=true;
}
template<class T>
void Queue<T>::setLength(int _len){
	max_length=_len;
	len=0;
	data=new T[max_length];
	queueMade=true;
}
template<class T>
T Queue<T>::get(){
	if(len>=bottom){
		return data[bottom++];
	}
}
template<class T>
Queue<T>::Queue(int _len,T defaultValue){
	max_length=_len;
	len=0;
	data=new T[max_length];
	for(int i=0;i<max_length;i++){
		data[i]=defaultValue;
	}
	queueMade=true;
}
template<class T>
void Queue<T>::clear(T defaultValue){
	len=0;
	for(int i=0;i<max_length;i++){
		data[i]=defaultValue;
	}
}
template<class T>
void Queue<T>::setDefaultValue(T _value){
	for(int i=0;i<max_length;i++){
		data[i]=_value;
	}
}

template<class T>
void Queue<T>::setLength(int _len,T defaultValue){
	max_length=_len;
	len=0;
	data=new T[max_length];
	for(int i=0;i<max_length;i++){
		data[i]=defaultValue;
	}
	queueMade=true;
}
template<class T>
Queue<T>::~Queue(){
	delete [] data;
}
template<class T>
void Queue<T>::push(T element){
	data[len++]=element;
}

template<class T>
int Queue<T>::length(){
	return len-bottom;
}
template<class T>
void Queue<T>::print(){
	if(len-bottom>=1){
		cout<<"[ ";
		cout<< data[bottom];
		for(int i=bottom+1;i<len;i++){
			cout<<", "<< data[i];
		}
		cout<<"]"<<"\n";
	}
	else{
		cout<<"queue is empty"<<"\n";
	}
	
}
template<class T>
void Queue<T>::copyFrom(Queue<T> &a,T defaultValue){
	if(max_length>=a.max_length){
		for(int i=0;i<a.len;i++){
			data[i]=defaultValue;
		}
		len=a.len;
		for(int i=0;i<a.len;i++){
			data[i]=a.data[i];
		}
	}
}
#endif
