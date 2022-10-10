#include <bits/stdc++.h>
using namespace std;
 
#define ff(i,n) for(ll i=1; i<=n; i++)
#define ll long long

int solve()
{
    ll n;
    cin>>n;
    // if(n==3) 
    ff(i,n){
        if(i==n) cout<<1<<" ";
        for(ll j=n; j>1; j--){
            cout<<j<<" ";
            if(j == i+1) cout<<1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
 return 0;
 }
