//calculating x^n
//O(logn)
#include <bits/stdc++.h>
using namespace std;

int Pow(int x, int n)
{
    int y;

    if(n == 0)
        return 1;

    else if(n % 2 == 0)
    {
        y = Pow(x, n/2);
        return y * y;
    }
    else
        return x * Pow(x, n-1);
}
int main()
{
    int x, n;
    scanf("%d %d", &x, &n);

    int res = Pow(x, n);
    printf("%d^%d  =  %d\n",x, n, res);

    return 0;
}
