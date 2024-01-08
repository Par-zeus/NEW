#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 7, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int c=0;
    int x = 13;
    int sum = 0;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            sum = arr[i] + arr[j];
            if (sum == x)
            {
                printf("Foundsum");
                c=1;
                break;
            }
        }
    }
    if(c!=1)
    {
        printf("\nElement not found");
    }else{
        printf("\nElement found");
    }
        return 0;
}