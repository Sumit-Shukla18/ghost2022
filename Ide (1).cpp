#include <bits/stdc++.h>
using namespace std;
 
#define ff(i,n) for(ll i=0; i<n; i++)
#define ll long long

int solve()
{
    ll n, r=0, g=0, b=0, t=0;
    n=6;
    string a;
        ff(i,n) {
            cin>>a[i];
            if(a[i]=='r') r++;
            else if(a[i]=='g') g++;
            else if(a[i]=='b') b++;
            else if(a[i]=='R'&& r!=0) t++;
            else if(a[i]=='B'&& b!=0) t++;
            else if(a[i]=='G'&& g!=0) t++;
            else
            t=-1;
        }
        if(t==3) cout<<"YES\n";
        else cout<<"NO\n";
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
