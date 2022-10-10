#include <bits/stdc++.h>
using namespace std;
 
#define ff(i,n) for(ll i=0; i<n; i++)
#define ll long long

void solve()
{
    ll n;
    ll x = 3;
        cin>>n;
    ll a[n];
    if(n>18) cout<<"NO";
    else {
    ll res = pow(3,n);
        cout<<"YES\n"<<"1 ";
        if(n>1)
        for(ll i=2; i<=n; i++) {
            
            cout<<x<<" ";
            x*=3;
        }
    }
    cout<<"\n";
        
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
