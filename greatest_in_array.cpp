#include<iostream>
using namespace std;
int main(){
    int a[10],n,g=0;
    cout<<"input no. of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        if(g<a[j]){
            g=a[j];
        }
    }
    cout<<"The gretest number is: "<<g<<endl;;
    return 0;
}