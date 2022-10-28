/*
Given an array nums. We define a running sum of
an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.
Input: nums = [1,2,3,4] Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

*/


#include<bits/stdc++.h>
using namespace std;
vector<int> running_sum(vector<int> &v)
{
    //here are are creating a new vector to store the desired values
     vector<int> ans;
    int sum=0; //initialised the sum to 0
    for(int i=0;i<v.size();i++)
    {
        sum=sum+v[i]; //adding the sum to the current element of the array to get the running sum
        ans.push_back(sum); //pushing back the final value to vector ans..
    }

    return ans;//returning the vector
}
print_array(vector<int> p)
{   cout<<"required array"<<endl; //printing the output..
    for(int j=0;j<p.size();j++)
    {
        cout<<p[j]<<endl;
    }
}
int main()
{
    int n;
    cout<<"enter size of the array"<<endl;
    cin>>n;//taking the size of the array from the user
    vector<int> a(n);
    cout<<"enter elements of the array"<<endl;
    for(int i=0;i<a.size();i++)//taking in values of the array
    {
        cin>>a[i];
    }
    a=running_sum(a);//calling the running_sum function
    print_array(a);//calling the function to print the values..
}
