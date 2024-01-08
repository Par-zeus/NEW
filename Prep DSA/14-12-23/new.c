#include<stdio.h>

int n,i,j,val=1;
int main()
{
for(i=1;i<=n;i++)
{
    j=n;
    if(i%2==0)
    {
        while(j>1)
        {
            val*=j;
            j=j/2;
        }
    }
}
printf("%d",val);
}