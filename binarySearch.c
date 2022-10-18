#include <stdio.h>
int binarySearch(int a[],int beg,int end ,int val)
{
  int mid;
  if(end>=beg)
  {
    mid=(beg+end)/2;
    if(a[mid]==val)
    {
      return mid+1;
    }
    else if(a[mid]<val)
    {
      return binarySearch(a,mid+1,end,val);
    }
    else
    {
      return binarySearch(a,beg,mid-1,val);
    }
  }
  return -1;
}
      
   
