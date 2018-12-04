//insertion sort
//O(n2)
#include <bits/stdc++.h>
using namespace std;

int num[1000005];
int n;

void insertion_sort()
{
    int temp, j, i;

    for(i=1; i<=n; i++)
    {
        temp = num[i];
        j = i - 1;

        while(j >= 1 && num[j] > temp)
        {
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = temp;
    }
}

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &num[i]);

    insertion_sort();

    printf("Sorted array: \n");
    for(int i=1; i<=n; i++)
        printf("%d\n", num[i]);

    return 0;
}
