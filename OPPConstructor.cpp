#include<iostream>
using namespace std;
class Shape {
private:
 int x;
 int y;
public:
 Shape(int i, int j); // Constructor
};

Shape::Shape(int i = 0, int j = 0) {
 x = i;
 y = j;
 cout << "Constructor called";
}

int main()
{
 Shape s1, s2;
 return 0;
}

