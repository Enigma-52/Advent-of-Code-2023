#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<long long> v;

    int f = 0;
    long long curr = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ':')
        {
            f = 1;
            i++;
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9' && f == 1)
        {
            curr = (curr * 10) + (s[i] - 48);
        }
        if ((s[i] == ' ' || i + 1 == s.length()) && f == 1)
        {
            v.push_back(curr);
            curr = 0;
        }
    }
    vector<int> check(v.size(), 0);
    int flag = 0;
    curr = 0;
    long long dest = 0, src = 0, range = 0;
    int cnt = 0;
    for (int i = 0; i < 207; i++)
    {
        string p;
        getline(cin, p);
        if (p[0] >= 'a' && p[0] <= 'z')
        {
            flag = 0;
        }
        for (int j = 0; j < p.length(); j++)
        {
            if (p[j] == ':')
            {
                flag = 1;
                break;
            }
            if (flag)
            {
                if (p[j] >= '0' && p[j] <= '9')
                {
                    curr = (curr * 10) + (p[j] - 48);
                }
                if ((p[j] == ' ' || j + 1 == p.length()))
                {
                    if (cnt == 0)
                    {
                        dest = curr;
                        cnt++;
                        curr = 0;
                    }
                    else if (cnt == 1)
                    {
                        src = curr;
                        curr = 0;
                        cnt++;
                    }
                    else if (cnt == 2)
                    {
                        range = curr;
                        cnt = 0;
                        curr = 0;
                    }
                }
            }
        }
        if (p.length() > 0 && isdigit(p[0]))
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] >= src && v[j] <= (src + range - 1) && check[j] != 1)
                {
                    v[j] = (v[j] - src) + dest;
                    check[j] = 1;
                }
            }
        }
        else
        {
            for (int k = 0; k < v.size(); k++)
            {
                check[k] = 0;
            }
        }
        curr = 0;
    }
    long long m = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < m)
        {
            m = v[i];
        }
    }
    cout << endl;
    cout << m << endl;
}
