#include <iostream>
#include <cmath>
#define PI 3.1416
using namespace std;
typedef struct my{
    double centre[2],point[2],r,c,a;
} circle;

circle display(circle cir);

circle set_values(circle cir);

circle put_centre_point(circle cir);

int main(){
    circle cir;
    cir=put_centre_point(cir);
    cir=set_values(cir);
    display(cir);
}
circle put_centre_point(circle cir){
    cout << "Enter the centre x cordiinate of the circle: ";
    cin  >> cir.centre[0];
    cout << "Enter the centre y cordiinate of the circle: ";
    cin  >> cir.centre[1];
    cout << "Enter the x corinate of a point in the circle: ";
    cin  >> cir.point[0];
    cout << "Enter the y corinate of a point in the circle: ";
    cin  >> cir.point[1];
    return cir;
}
circle set_values(circle cir){
    cir.r= sqrt(pow(cir.centre[0]-cir.point[0],2)+pow(cir.centre[1]=cir.point[1],2));
    cir.c=cir.r*2*PI;
    cir.a=PI*pow(cir.r,2);
    return cir;
}
circle display(circle cir){
    cout << "Radius: " << cir.r << endl;
    cout << "Circumference: " << cir.c << endl;
    cout << "Area" << cir.a << endl;
}

