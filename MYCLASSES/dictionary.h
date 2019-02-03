#define MAX_CHAR_LENGTH 20
#include"array.h"
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
		Dictionary();
		Dictionary(int _length,Key k_default,Value v_default);
		Dictionary(int _length);
		void removeWithValue(Value v);
		Key &getKey(int index) const;
		Value &getValue(int index) const;
		Key minElementKeyUsingValuesOf(Array<Key> &temp);
		Key minElementKey(Array<Value> exclude);
		Value minElementValue();
		int minElementindex();
		void splice(int index,int _len);
		void print();
		void clear(Key _key,Value _value);
		void setLength(int _length,Key k_default,Value v_default);
		Value &operator[](Key _key);
		Key &operator()(Value _value);
	//	Dictionary<Key,Value>(Dictionary<Key,Value> &right);
	//	Dictionary< Key ,Value> operator=(Dictionary< Key,Value> right);
		const Dictionary<Key,Value> &operator=(const Dictionary<Key,Value> &other){
   			if(this == &other) return *this; 
   			delete[] key; 
			delete[] value; // freeing previously used memory
   			key = new Key[other.len];
   			value = new Value[other.len];
   			len = other.len;
 			memcpy(key, other.key, sizeof(int) * len);
 			memcpy(value, other.value, sizeof(int) * len);
  			return *this;
		}
		Dictionary<Key,Value>(const Dictionary<Key,Value> &other){
			key = new Key[other.len];
   			value = new Value[other.len];
   			len = other.len;
   			memcpy(key, other.key, sizeof(int) * len);
   			memcpy(value, other.value, sizeof(int) * len);
		}
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
void Dictionary< Key ,Value >::clear(Key _key,Value _value){
	len=0;
	for(int i=0;i<max_length;i++){
		key[i]=_key;
		value[i]=_value;
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
	for(int i=0;i<len;i++){
		key[i]=key[i+_len];
		value[i]=value[i+_len];
	}
	len-=_len;
}
template <class Key ,class Value >
Dictionary< Key ,Value >::Dictionary(){
}
template <class Key ,class Value >
Key Dictionary<Key,Value>::minElementKeyUsingValuesOf(Array<Key> &temp){
	Value min;
	int index;
	for(int i=0;i<len;i++){
		if(temp.contains(key[i])){
			min=value[i];
			index=i;
			break;
		}
	}
	for(int i=0;i<len;i++){
		if(min>value[i] && temp.contains(key[i])){
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
Key Dictionary< Key ,Value >::minElementKey(Array<Value> exclude){
	Value min=value[0];
	int index=0;
	for(int i=0;i<len;i++){
		if(min>value[i] && exclude.contains(value[i]==false)){
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
template <class Key ,class Value >
Value &Dictionary< Key ,Value >::getValue(int index)const{
	return value[index];
}
template <class Key ,class Value >
Key &Dictionary< Key ,Value >::getKey(int index)const{
	return key[index];
}
/*
template <class Key ,class Value >
Dictionary<Key,Value>& Dictionary< Key,Value>::operator=(Dictionary< Key,Value> &right){

	int len=this->len;
	this->len=right.len;
	right.len=len;
	swap(this->key,right.key);
	swap(this->value,right.value);
	swap(this,right);
	
	return *this;
}
*/
/*
template <class Key ,class Value >
Dictionary< Key,Value> Dictionary< Key,Value>::operator=(Dictionary< Key,Value> right){
	int len=this->len;
	this->len=right.len;
	right.len=len;
	swap(this->value,right.value);
	swap(this->key,right.key);
	return *this;
}

*/
template <class Key ,class Value >
void Dictionary< Key ,Value>::removeWithValue(Value v){
	for(int i=0;i<len;){
		if(v=value[i]){
			splice(i,1);
		}
		else{
			i++;
		}
	}
}

template <class Key ,class Value >
Key &Dictionary< Key ,Value >::operator()(Value _value) {
	for(int i=0;i<len;i++){
		if(_value==value[i]){
			return key[i];
		}
	}
//	return nullptr;
}
/*
template <class Key ,class Value >
Dictionary< Key ,Value>::Dictionary(Dictionary<Key,Value> &right){
	int len=this->len;
	this->len=right.len;
	right.len=len;
	swap(this->value,right.value);
	swap(this->key,right.key);
}
*/
#endif


