//Write a function circle() to calculate the circumference and
//area of a circle. Call separate functions to calculate circumference
//and area within circle().
// Call circle() in main() to output the circumference 
//and area of a circle with radius 5.
#include<stdio.h>
float circumference(double r){
    return (float)2*3.14*r;
}
float area(double r){
    return (float)3.14*r*r;
}
void circle(double r){
    printf("circumference:%.2f\n",circumference(r));
    printf("area:%.2f\n",area(r));
}
int main(){
    circle(5);
    return 0;
}