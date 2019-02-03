#include<math.h>

class Vector2f{
	public:
		Vector2f(float x1,float y1);
		float x,y;
		void reflect(Vector2f vec);
		void normalize();
		void scalar(float scale);
	//	Vector2f operator+(Vector2f);
	//	Vector2f operator-(Vector2f);
	//	Vector2f operator*(float);
};
Vector2f::Vector2f(float x1=0.0,float y1=0.0){
	x=x1;
	y=y1;
}
void Vector2f::reflect(Vector2f vec){
	if(vec.x==1.0 && vec.y==0.0){
		x=x*-1;
		}
	if(vec.x==0.0 && vec.y==1.0){
		y=y*-1;
		}	
	}
void Vector2f::normalize(){
	x=(x*x)/sqrt((x*x)+(y*y));
}
void Vector2f::scalar(float scale=1){
	x*=scale;
	y*=scale;
}
/*
Vector2f Vector2f::operator+(Vector2f temp){
	Vector2f thisguy(0.0,0.0);
	thisguy.x=x+temp.x;
	thisguy.y=y+temp.y;
	return thisguy;
}
Vector2f Vector2f::operator-(Vector2f temp){
	Vector2f thisguy(0.0,0.0);
	thisguy.x=x-temp.x;
	thisguy.y=y-temp.y;
	return thisguy;
}
Vector2f Vector2f::operator*(float value){
	Vector2f thisguy(0.0,0.0);
	thisguy.x=value*thisguy.x;
	thisguy.y=value*thisguy.y;
	return thisguy;
}
*/

