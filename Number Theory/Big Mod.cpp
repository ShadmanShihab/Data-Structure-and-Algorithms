//Big Mod
#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int x, n, m;
    scanf("%d %d %d", &x, &n, &m);

    int res = mod(x, n, m);
    printf("%d^%d %% %d  =  %d\n",x, n, m, res);

    return 0;
}
