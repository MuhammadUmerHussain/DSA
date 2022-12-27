#include <iostream>
using namespace std;

class idk
{
    public:
    void operator delete(void *p)
    {
        cout<<"Delete";
        free(p);
    }
};

int main ()
{
    idk *p1;

    delete(p1);


    return 0;
}



    
