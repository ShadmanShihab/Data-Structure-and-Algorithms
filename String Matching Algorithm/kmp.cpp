//kmp
//O(m + n)
#include <bits/stdc++.h>
using namespace std;

#define Max 10000
int failure[Max];

int build_failure_function(string pattern, int m)
{
    failure[0] = 0;
    failure[1] = 0;

    for(int i=2; i<=m; i++)
    {
        int j = failure[i-1];

        while(true)
        {
            if(pattern[j] == pattern[i-1])
            {
                failure[i] = j + 1;
                break;
            }
            if(j == 0)
            {
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
}

bool kmp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();

    build_failure_function(pattern, m);

    int i = 0;
    int j = 0;

    while(true)
    {
        if(i == n)
            return false;

        if(text[i] == pattern[j])
        {
            i++;j
            j++;
            if(j == m)
                return true;
        }
        else
        {
            if(j == 0)
                i++;
            else
                j = failure[j];
        }
    }
    return false;
}

int main()
{
    string text, pattern;
    cin>>text>>pattern;

    if(kmp(text, pattern))
        cout<<"Pattern found\n";
    else
        cout<<"Pattern not found\n";
}
