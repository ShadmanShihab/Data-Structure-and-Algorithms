//Big Mod
#include <bits/stdc++.h>
using namespace std;

//1
mod(int x, int n, int m)
{
    int y;

    if(n == 0)
        return 1;

    else if(n % 2 == 0)
    {
        y = mod(x, n/2, m);
        return (y * y) % m;
    }
    else
        return ( (x%m) * mod(x, n-1, m)) % m;
}

//2
int bigMod(int a, int n, int m)
{
    if(n == 0)
        return 1;

    int x = bigMod(a, n/2, m);
    x = (x * x) %  m;

    if(n % 2 == 1)
        x = (x * a) % m;

    return x;
}


int main()
{
    int x, n, m;
    scanf("%d %d %d", &x, &n, &m);

    int res = mod(x, n, m);
    printf("%d^%d %% %d  =  %d\n",x, n, m, res);

    return 0;
}
