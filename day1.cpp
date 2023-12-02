#include <iostream>
using namespace std;

int main()
{
    int k=1;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        string p="";
        cin >> p;
        int a=p[0]-48;
        int b=p[p.length()-1]-48;
        a=a*10;
        a=a+b;
        sum+=a;
    }
    cout << sum << endl;
}

//5334
