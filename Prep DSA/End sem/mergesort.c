#include<stdio.h>
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void merger(int a[],int low,int mid,int high)
{
    int b[high-low+1];
    int i,j,k=0;

    i=low;
    j=mid+1;

    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;i++;
        }
        else{
            b[k]=a[j];
            k++;j++;
        }
    }

    while(i<=mid)
    {
         b[k]=a[i];
        k++;i++;
    }

     while(j<=high)
    {
         b[k]=a[j];
        k++;j++;
    }

   for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = b[k];
    }
}
void mergesort(int a[],int low,int high)
{   
    if(low<high){
    int mid=low+(high-low)/2;

    mergesort(a,low,mid);
    mergesort(a,mid+1,high);

    merger(a,low,mid,high);
    }

}
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;

    for(int j=low;j<=high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,high);
    return i+1;
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);

        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}
int bin_search(int a[],int low,int high,int x)
{
    if(low<=high)
    {
    int mid=low+(high-low)/2;
        if(a[mid]<x)
        {
            return bin_search(a,mid+1,high,x);
        }
        else if(a[mid]>x)
        {
            return bin_search(a,low,mid-1,x);
        }
        else return mid;
    }
    
    else{
        return -1;//  printf("\nElement %d found at position %d ",x,i+1);
    }
}
int main(){
    
    int a[10],n,low,high,result,x;
    printf("\nEnter size of array:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        printf("\nEnter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nOriginal Array: ");
     print(a,n);
    
    low=0;
    high=n-1;

    // mergesort(a,low,high);
    quicksort(a,low,high);
    printf("\nSorted Array: ");
    print(a,n);

    printf("\nEnter element to be found:");
    scanf("%d",&x);

    result=bin_search(a,low,high,x);
    if(result!=-1) printf("\n Element %d found at index %d ",x,result);
    else printf("\nElement %d not found",x);

    return 0;
}