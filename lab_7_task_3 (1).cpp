#include <iostream>
using namespace std;
class Volume{
    float volume;
    const float PI=3.14;
    public:
    void setVolume(float r){
        volume=(4.0/3.0)*PI*(r*r*r);
    }
    void setVolume(float r, float h){
        volume=PI*(r*r)*h;
    }
    float getVolume(){
        return volume;
    }
};
int main(){
    Volume c ,s;
    c.setVolume(2.0,4.0);
    s.setVolume(2.0);
    cout << "Cylinder: " << c.getVolume() << endl;
    cout << "Sphere: " << s.getVolume() << endl;
}