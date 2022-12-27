#include <iostream>
using namespace std;
class Volume
	{
    float vol;
    const float pie=3.14;
    public:
    void setvol(float radius){
        vol=(4.0/3.0)*pie*(radius*radius*radius);//volume of circle formula
    }
    void setvol(float radius, float height){
        vol=pie*(radius*radius)*height;//volume of sphere formula
    }
    float getvol(){
        return vol;
    }
};
int main(){
    Volume c ,s;
    c.setvol(7.0,9.0);
    s.setvol(8.0);
    cout << "Cylinder: " << c.getvol() << endl;
    cout << "Sphere: " << s.getvol() << endl;
}
