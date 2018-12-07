//lcs dp(bottom up)
//O(mn)
#include <bits/stdc++.h>
using namespace std;

int L[10001][10001];    //for printing path

int lcs(char x[], char y[], int m, int n)
{
    int i, j;

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(x[i-1] == y[j-1])
                L[i][j] = 1 + L[i-1][j-1];
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

void print_lcs(char x[], char y[], int m, int n)
{
    int index = L[m][n];
    char plcs[index+1];
    plcs[index] = '\0';

    int i=m, j=n;
    while(i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            plcs[index-1] = x[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    cout<<"LCS of "<<x<<" "<<y<<" = "<<plcs<<endl;
}
int main()
{
    char x[100001], y[100001];
    gets(x);
    gets(y);

    int m = strlen(x);
    int n = strlen(y);

    cout<<"LCS = "<<lcs(x, y, m, n)<<endl;
    print_lcs(x, y, m, n);

    return 0;
}
