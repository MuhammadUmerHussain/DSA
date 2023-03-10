#include <iostream>
#include <stack>
#include <conio.h> 
using namespace std;

void deleteMid(stack<char>& st, int n,
    int curr = 0)
{
    if (st.empty() || curr == n)
        return;

    char x = st.top();
    cout<<x<<" **"<<endl;
    st.pop();

    deleteMid(st, n, curr + 1);

    if (curr != x < n )
    {
    	st.push(x);
    	cout<<x<<" *"<<endl;
	}
        
}

int main()
{
    stack<char> st;

    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('99');
    st.push('6');
    st.push('7');

    deleteMid(st, st.size());

    while (!st.empty())
    {
        char p = st.top();
        st.pop();
        cout << p << " ";
    }
    return 0;
}
