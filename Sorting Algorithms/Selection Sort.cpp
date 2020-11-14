//selection sort
//O(n2)
#include <bits/stdc++.h>
using namespace std;

int num[1000005];
int n;

/*
void selection_sort()
{
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(num[i] > num[j])
                swap(num[i], num[j]);
}
*/
void selection_sort()
{
    int index_min;
    for(int i=1; i<=n; i++)
    {
        index_min = i;
        for(int j=i+1; j<=n; j++)
        {
            if(ara[j] < ara[index_min])
                index_min = j;
        }
        swap(ara[i], ara[index_min]);
    }
}

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &num[i]);

    selection_sort();

    printf("Sorted array: \n");
    for(int i=1; i<=n; i++)
        printf("%d\n", num[i]);

    return 0;
}
