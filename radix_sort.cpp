#include <iostream>
using namespace std;

void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10]={0};
 
    for (i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;
 
    for (i=1;i<10;i++)
        count[i]+=count[i-1];
 
    for (i=n-1;i>=0;i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
         {  
          max = arr[i];
         }
    return max;
}
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void print_array(int arr[],int n)
{
    for (int i=0;i<n;i++)
        cout<<arr[i]<< " ";
}

int main()
{
    int n;
    cout<<"Enter the size :";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);
    }
    radixsort(arr, n);
    cout<<"Radix Sort: ";
    print_array(arr, n);
    return 0;
}
