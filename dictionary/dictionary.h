#define MAX_CHAR_LENGTH 20
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
#ifndef DICTONARY_H
#define DICTONARY_H
template <class Key ,class Value>
class Dictionary{
	private:
		Value *value;
		Key *key;
		int len;
		int max_length;
	public:
		void view();
		int length();
		Dictionary(int _length,Key k_default,Value v_default);
		Dictionary(int _length);
		//Dictionary();
		Key getKeys();
		Value getValues();
		Key minElementIndexUsingValuesOf(Dictionary &temp);
		Key minElementKey();
		Value minElementValue();
		int minElementindex();
		void splice(int index,int _len);
		void print();
		void setLength(int _length,Key k_default,Value v_default);
		Value &operator[](Key _key);
		void add(Key _key, Value _value);
		~Dictionary();
	protected:
};
template <class Key ,class Value >
Dictionary< Key,Value >::Dictionary(int _length,Key k_default,Value v_default){
	len=0;
	max_length=_length;
	value=new Value[max_length];
	key=new Key[max_length];
	for(int i=0;i<max_length;i++){
		key[i]=k_default;
		value[i]=v_default;
	}
	if(!value && !key){
		cout<<"successful"<<"\n";
	}
}
template <class Key ,class Value >
Dictionary< Key,Value >::Dictionary(int _length){
	len=0;
	max_length=_length;
	value=new Value[max_length];
	key=new Key[max_length];
	if(!value && !key){
		cout<<"successful"<<"\n";
	}
}
template <class Key ,class Value >
void Dictionary< Key ,Value >::setLength(int _length,Key k_default,Value v_default){
	len=0;
	max_length=_length;
	value=new Value[max_length];
	key=new Key[max_length];
		for(int i=0;i<max_length;i++){
		key[i]=k_default;
		value[i]=v_default;
	}
//	for(int i=0;i<max_length;i++){
//		key[i]=new char[MAX_CHAR_LENGVH];//20
//	}
	if(!value && !key){
		cout<<"successful"<<"\n";
	}
}
template <class Key ,class Value >
Dictionary<Key , Value >::~Dictionary(){
	delete [] value;
	//for(int i=0;i<max_length;i++){
	//	delete [] key[i];
	//}
	delete [] key;
}
template <class Key ,class Value >
Value &Dictionary<Key,Value >::operator[](Key _key){
	for(int i=0;i<len;i++){
		if(_key==key[i]){
			return value[i];
		}
	}	
}
template <class Key ,class Value >
void Dictionary< Key ,Value >::add(Key _key, Value _value){
	//strcpy(key[len],_key);
	key[len]=_key;
	value[len]=_value;
	len++;
}
template <class Key ,class Value >
int Dictionary<Key , Value >::length(){
	return len;
}
template <class Key ,class Value >
void Dictionary< Key ,Value >::view(){
	for(int i=0;i<len;i++){
	//	cout<<"  "<<value[i]<<" ";
	//	puts(key[i]);
	}
}
template <class Key ,class Value >
void Dictionary< Key ,Value >::print(){
	cout<<"{ \n";
	for(int i=0;i<len;i++){
		cout<< key[i] << " : "<<value[i]<<"\n";
	}
	cout<<"} \n";	
}
template <class Key ,class Value >
void Dictionary< Key ,Value >::splice(int index,int _len){
	for(int i=i;i<len;i++){
		key[i]=key[i+_len];
		value[i]=value[i+_len];
	}
	len-=_len;
}
template <class Key ,class Value >
Key Dictionary< Key ,Value >::minElementIndexUsingValuesOf(Dictionary &temp){
	
	Value min=INT_MAX;
	for(int i=0;i<temp.len;i++){
		if(min>value[temp.value[i]]){
			min=value[temp.value[i]];
		}
	}

	/*
	Key min=INT_MAX;
	for(int i=0;i<temp.len;i++){
		if(min>value[temp.key[i]]){
			min=value[temp.key[i]];
		}
	}
		*/
}
template <class Key ,class Value >
Key Dictionary< Key ,Value >::minElementKey(){
	Value min=value[0];
	int index=0;
	for(int i=0;i<len;i++){
		if(min>value[i]){
			min=value[i];
			index=i;
		}
	}
	return key[index];
	/*
	Key min=INT_MAX;
	for(int i=0;i<temp.len;i++){
		if(min>value[temp.key[i]]){
			min=value[temp.key[i]];
		}
	}
	*/
}
template <class Key ,class Value >
Value Dictionary< Key ,Value>::minElementValue(){
	Value min=value[0];
	int index=0;
	for(int i=0;i<len;i++){
		if(min>value[i]){
			min=value[i];
			index=i;
		}
	}
	return value[index];
}
template <class Key ,class Value >
int Dictionary< Key ,Value >::minElementindex(){
	Value min=value[0];
	int index=0;
	for(int i=0;i<len;i++){
		if(min>value[i]){
			min=value[i];
			index=i;
		}
	}
	return index;
}
#endif
/*
private:
		int *value;
		char **key;
		int len;
		int max_length;
	public:
		void view();
		int getLength();
		Dictionary(int _length);
		int operator[](char *_key);
		void add(char *_key, int _value);
		~Dictionary();
	protected:
};
Dictionary::Dictionary(int _length){
	len=0;
	max_length=_length;
	value=new int[max_length];
	key=new char*[max_length];
	for(int i=0;i<max_length;i++){
		key[i]=new char[MAX_CHAR_LENGVH];//20
	}
	if(!value && !key){
		cout<<"successful"<<"\n";
	}
}

Dictionary::~Dictionary(){
	delete [] value;
	for(int i=0;i<max_length;i++){
		delete [] key[i];
	}
	delete [] key;
}
int Dictionary::operator[](char *_key){
	for(int i=0;i<len;i++){
		if(strcmp(_key,key[i])==0){
			return value[i];
		}
	}	
}
void Dictionary::add(char *_key, int _value){
	strcpy(key[len],_key);
	value[len]=_value;
	len++;
}
int Dictionary::getLength(){
	return len;
}
void Dictionary::view(){
	for(int i=0;i<len;i++){
		cout<<"  "<<value[i]<<" ";
		puts(key[i]);
	}
}
*/

