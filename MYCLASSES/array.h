#include <iostream>
#include <string.h>
using namespace std;
#include <math.h>
#define MAX_LENGTH 100
#define DEFAULT_VALUE 0
#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class Array{
	// Private section
	bool arrayMade;
	T *data;
	int max_length,len;
	public:
		Array();
		Array(int _len);
		Array(int _len ,T defaultValue);
		~Array();
		void setLength(int _len);
		void setLength(int _len,T defaultValue);
		void push(T element);
		int length();
		bool contains(T element);
		void setDefaultValue(T _value);
		void splice(int index,int len);
		void pop(int i);
		void print();
		int index(T element);
		void reverse();
		void copyFrom(Array<T> &a,T defaultValue);
		void remove(T element);
		void clear(T defaultValue);
		int maxElementIndex();
		int minElementIndex();
		T minElementIndexUsingKeysOf(Array a);
		T max();
		T min();
		T &operator[](int position){
			if(position>=0){
				return data[position];		
			}
			else{
				return data[len-position];
			}
		}
		// Public Declarations
	protected:
		// Protected Declarations
};
template<class T>
Array<T>::Array(){
	arrayMade=false;
}
template<class T>
Array<T>::Array(int _len){
	max_length=_len;
	len=0;
	data=new T[max_length];
	arrayMade=true;
}
template<class T>
void Array<T>::setLength(int _len){
	max_length=_len;
	len=0;
	data=new T[max_length];
	arrayMade=true;
}

template<class T>
Array<T>::Array(int _len,T defaultValue){
	max_length=_len;
	len=0;
	data=new T[max_length];
	for(int i=0;i<max_length;i++){
		data[i]=defaultValue;
	}
	arrayMade=true;
}
template<class T>
void Array<T>::clear(T defaultValue){
	len=0;
	for(int i=0;i<max_length;i++){
		data[i]=defaultValue;
	}
}
template<class T>
void Array<T>::setDefaultValue(T _value){
	for(int i=0;i<max_length;i++){
		data[i]=_value;
	}
}
template<class T>
int Array<T>::index(T element){
	for(int i=0;i<len;i++){
		if(data[i]==element){
			return i;
		}
	}
}
template<class T>
void Array<T>::setLength(int _len,T defaultValue){
	max_length=_len;
	len=0;
	data=new T[max_length];
	for(int i=0;i<max_length;i++){
		data[i]=defaultValue;
	}
	arrayMade=true;
}
template<class T>
Array<T>::~Array(){
	delete [] data;
}
template<class T>
void Array<T>::push(T element){
	data[len++]=element;
}
template<class T>
void Array<T>::pop(int i){
	len--;
}
template<class T>
void Array<T>::splice(int index,int _len){
	for(int i=index;i<len;i++){
		data[i]=data[i+_len];
	}
	len-=_len;
}
template<class T>
int Array<T>::length(){
	return len;
}
template<class T>
void Array<T>::print(){
	if(len>=1){
		cout<<"[ ";
		cout<< data[0];
		for(int i=1;i<len;i++){
			cout<<", "<< data[i];
		}
		cout<<"]"<<"\n";
	}
	else{
		cout<<"array is empty"<<"\n";
	}
	
}
template<class T>
int Array<T>::maxElementIndex(){
	T max=data[0];
	int index=0;
	for(int i=1;i<len;i++){
		if(max<data[i]){
			max=data[i];
			index=i;
		}
	}
	return index;
}
template<class T>
int Array<T>::minElementIndex(){
	//int min=INT_
	T min=data[0];
	int index=0;
	for(int i=1;i<len;i++){
		if(min>data[i]){
			min=data[i];
			index=i;
		}
	}
	return index;
}
template<class T>
T Array<T>::max(){
	T max=data[0];
	for(int i=1;i<len;i++){
		if(max<data[i]){
			max=data[i];
		}
	}
	return max;
}
template<class T>
T Array<T>::min(){
	T min=data[0];
	for(int i=1;i<len;i++){
		if(min>data[i]){
			min=data[i];
		}
	}
	return min;
}
template<class T>
void Array<T>::remove(T element){
	for(int i=0;i<len;i++){
		if(element==data[i]){
			splice(i,1);
			break;
		}
	}
}
template<class T>
bool Array<T>::contains(T element){
	bool found=false;
	for(int i=0;i<len;i++){
		if(element==data[i]){
			found=true;
			return found;
		}
	}
	return found;
}
template<class T>
void Array<T>::reverse(){
	T *temp=new T[len];
	for(int i=0;i<len;i++){
		temp[i]=data[i];
	}
	for(int i=0;i<len;i++){
		data[len-1-i]=temp[i];
	}
	delete [] temp;
}
template<class T>
void Array<T>::copyFrom(Array<T> &a,T defaultValue){
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
