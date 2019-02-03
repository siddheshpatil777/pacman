#include "usefull.h"
int Usefull::to_int(char *value){
	int answer=0;
	int temp=0;
	char a;
	int length=strlen(value);
	for(int i=0;i<length;i++){
		char a=value[i]-48;
		temp=a;
		answer+=temp*pow(10,length-1-i);
	}
	return answer;
}
