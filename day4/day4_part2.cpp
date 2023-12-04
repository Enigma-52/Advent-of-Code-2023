#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k=223;
    int sum=0;
    map<int,int> mapper;
    for(int i=0;i<k;i++)
    {
        mapper[i]=1;
    }
    for(int i=0;i<k;i++)
    {
        string s;
        getline(cin,s);
        //cout << s << endl;
        int f=0;
        int g=0;
        map<string,int> mp;
        mp[""]=0;
        string p="";
        int cnt=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==':')
            {
                f=1;
            }
            if(s[j]=='|')
            {
                g=1;
            }
            if(f==1 && g==0)
            {
                char c=s[j];
                if(c>='0' && c<='9')
                {
                    p+=c;
                }
                if(c==' ' || j+1==s.length())
                {
                    mp[p]=1;
                    //cout << p << endl;
                    p="";
                }
            }
            if(f==1 && g==1)
            {
                char c=s[j];
                if(c>='0' && c<='9')
                {
                    p+=c;
                }
                if(c==' ' || j+1==s.length())
                {
                    mp[""]=0;
                    //cout << p << "  " << mp[p] << endl;
                    if(mp[p]==1)
                    {
                        cnt++;
                    }
                    p="";
                }
            }
        }
        
        for(int j=1;j<=cnt;j++)
        {
            mapper[i+j]+=mapper[i];
        }
    }
    for(auto it: mapper)
    {
        sum+=it.second;
    }
    cout << sum << endl;
}
