#include <iostream>
using namespace std;

int main()
{
    int red = 12;
    int green = 13;
    int blue = 14;
    int k=100;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        int r=0,g=0,b=0,curr=0;
        string s;
        getline(cin,s);
        int f=0;
        int check=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==':')
            {
                f=1;
                continue;
            }
            if(f)
            {
                char c=s[j];
                if(c>='0' && c<='9')
                {
                    curr=(curr*10) + (c-48);
                }
                else
                {
                    if(c=='r')
                    {
                        r=max(curr,r);
                        curr=0;
                    }
                    if(c=='g')
                    {
                        g=max(curr,g);
                        curr=0;
                    }
                    if(c=='b')
                    {
                        b=max(curr,b);
                        curr=0;
                    }
                }
            }
        }
        cout << "red: " << r << "blue: " << b << "green: " << g << endl;
        /*Part 1 : 
        
            if(r>red || b>blue || g>green)
            {
                check=1;
            }
            if(check==0)
            {
                sum+=i;
                sum+=1;
            }
        
        */  
        
        // Part 2 : sum= sum + (r*g*b);
    }
    cout << sum << endl;
}
