#include<bits/stdc++.h>
using namespace std;

int check(int arr[], int n, vector<int> &v, int index, int sum, int x) {
    if(index == n) {
        if(sum == x) {
            cout<<"[{";
            for(int i=0; i<v.size(); i++) {
                
                if(i == v.size()-1) cout<<v[i];
                else cout<<v[i]<<",";
                
            }
                cout<<"}]\n";
                return 1;
        }
        else return 0;
    }

    v.push_back(arr[index]);
    x += arr[index];
    int first = check(arr, n, v, index+1, sum, x);
    x -= arr[index];
    v.pop_back();
    int second = check(arr, n, v, index+1, sum, x);
    return (first+second);
}

int main() {
    int arr[] = {1,2,1,0};
    int n = 4;
    int sum = 2;
    vector<int> v;
    cout<<check(arr, n, v, 0, sum, 0);
    return 0;
}