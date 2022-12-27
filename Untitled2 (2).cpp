#include <iostream>
using namespace std;

class idk
{
	int x;
    public:
    	
    	idk(int i)
    	{
    		x=i;
		}
    void *operator new(size_t size)
    {
    	void *p;
    	cout<<"Construct";
		p = malloc(size); 	
    	return p;
	}
    void operator delete(void* p)
    {
        cout<<"Delete";
        free(p);
    }
};

int main ()
{
    idk *p;
    p = new idk(10);

    delete(p);


    return 0;
}



    

