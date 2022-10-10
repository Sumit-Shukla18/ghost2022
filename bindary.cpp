#include<bits/stdc++.h>

using namespace std;

int binary_search(int a[], int size, int key) {
    int start = 0, end = size-1;
    if(a[(start+end)/2]==key) return (start+end)/2;
    else {
        while(start<end) {
            if(a[end/2]>key) {
                end/=2;
            }
            else start=end/2;

            for (int i=start; i<end/2; i++) {
                if(a[(start+end)/2]==key) return (start+end)/2;
            }
        }
        return -1;
    }
}

int main() {
    int hoi[] = {2,5,12,35,77,98};
    cout<< "35 is at place : "<<hoi[binary_search(hoi, 6, 35)];
    return 0;
}