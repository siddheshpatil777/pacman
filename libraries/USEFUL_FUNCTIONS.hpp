#include<stdlib.h>
#include<math.h>
#include<time.h>

int randomInt(int min,int max){
	/*
	unsigned int seedval;
	time_t t;
	seedval=(unsigned)time(&t);	
	srand(seedval);
	*/
	return rand()%(max-min)+min;
}
float randomFloat(float min,float max){
	int _min=1000*ceil(min);
	int _max=1000*ceil(max);
	int _x=randomInt(0,1000);
	float x=_x;
	float value=(((rand()%(_max-_min))+min)/1000)+(x/1000);
	return value;
}
float map(float x,float x_min,float x_max,float y_min,float y_max){
	float value=(( ( (y_max-y_min)/(x_max-x_min) )*x)+y_min);
	//if(value>y_max)
	return value;
}
int integer(char value){
	int z=value;
	return (value-48);
	
}


