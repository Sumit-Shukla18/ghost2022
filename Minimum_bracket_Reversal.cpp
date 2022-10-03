/*For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.*/


#include<bits/stdc++.h>
int countBracketReversals(string input) {
    stack<char>s;
    
    for(int i=0;i<input.size();i++){
        if (input[i] == '}' && !s.empty()) {
            if (s.top() == '{')
                s.pop();
            else
                s.push(input[i]);
        }
        else{
            s.push(input[i]);
        }      
    }
    
    int length = s.size();
    if(length %2 !=0){
        return -1;
    }
    int n = 0;
    while (!s.empty() && s.top() == '{') {
        s.pop();
        n++;
    }
    return (length / 2 + n % 2);
}
