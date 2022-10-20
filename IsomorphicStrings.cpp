#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    vector<int>v1,v2;
    map<char,int>mp;
    for(int i=0;i<s.size();i++){
        if(mp.find(s[i])!=mp.end()){
            v1.push_back(mp[s[i]]);
        }
        else{
            mp[s[i]]=i;
            v1.push_back(mp[s[i]]);
        }
    }
    map<char,int>mpi;
    for(int i=0;i<t.size();i++){
        if(mpi.find(t[i])!=mpi.end()){
            v2.push_back(mpi[t[i]]);
        }
        else{
            mpi[t[i]]=i;
            v2.push_back(mpi[t[i]]);
        }
    }
    return v1==v2;
}
    
int main(){
    string s = "egg";
    string t = "add";
    if(isIsomorphic(s,t)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
	return 0;
}
