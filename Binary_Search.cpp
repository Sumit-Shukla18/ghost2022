#include<iostream>
using namespace std;
int binarysearch(int *a,int key,int n);
 
int main( )
{
 
             int *arr,n,key;
             cout<<"Enter how many elements :";
             cin>>n;
             arr=new int[n];
             cout<<endl<<"Enter elements : ";
             for(int i=0;i<n;i++)
             cin>>arr[i];
             cout<<endl<<"Enter the element to search :";
             cin>>key;
             int result=binarysearch(arr,key,n);
             if(result>=0)
             cout<<endl<<"Element found at"<<
             result+1<<"position";
             else cout<<endl<<"Element not found";
             return 0;
}
int binarysearch(int *arr,int key,int n)
{
             int low=0,high=n-1;
             while(low<=high)
             {
                  int middle=(low+high)/2;
                          if(key==arr[middle])
                              return middle;
                          else if(key>arr[middle])
                              low=middle+1;
                          else if(key<arr[middle])
                              high=middle-1;
             }
             return -1;
}
