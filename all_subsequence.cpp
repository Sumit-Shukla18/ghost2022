#include<bits/stdc++.h>
using namespace std;

void check(int arr[], int n, vector<int> &v, int index, int sum, int x) {
    if(index == n) {
        if(sum == x) {
            
            cout<<"[{";
            for(int i = 0; i<v.size(); i++) {
                if(i == v.size()-1) cout<<v[i];
                else cout<<v[i]<<",";
            }
            cout<<"}]\n";
        }
        return;
    }

    v.push_back(arr[index]);
    x += arr[index];
    check(arr, n, v, index+1, sum, x);
    x -= arr[index];
    v.pop_back();
    check(arr, n, v, index+1, sum, x);
}

int main() {
    int arr[] = {1,2,1,0};
    int n = 4;
    int sum = 2;
    vector<int> v;
    check(arr, n, v, 0, sum, 0);
    return 0;
}