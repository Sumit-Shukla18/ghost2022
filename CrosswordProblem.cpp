//Q: provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
// For example, The following is an example for the input crossword grid and the word list.
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV


#include<bits/stdc++.h>
using namespace std;
char grid[10][10];

bool isValidVertical(char grid[10][10],int i,int j,string word){
    int emptyPlaces = 0;
    for(int row = i;row < 10;row++){
        if(grid[row][j] == '-'){
        	emptyPlaces++;
        }
        else if(grid[row][j] != '+'){
            if(word[emptyPlaces] == grid[row][j]){
                emptyPlaces++;
            }
            else{
                return false;
            }
        }
        else{
            break;
        }
    }
    if(emptyPlaces == word.size()){
        return true;
    }
    else{
        return false;
    }
    
}

bool isValidHorizontal(char grid[10][10],int i,int j,string word){
    int emptyPlaces = 0;
    for(int col = j;col < 10;col++){
        if(grid[i][col] == '-'){
        	emptyPlaces++;
        }
        else if(grid[i][col] != '+'){
            if(word[emptyPlaces] == grid[i][col]){
                emptyPlaces++;
            }
            else{
                return false;
            }
        }
        else{
            break;
        }
    }
    if(emptyPlaces == word.size()){
        return true;
    }
    else{
        return false;
    }
    
}

void setvertical(char grid[10][10], bool helper[],int row,int col,string word){
    for(int i=row;i<row+word.size();i++){
        if(grid[i][col] == '-'){
            grid[i][col] = word[i-row];
        	helper[i-row] = true;
        }
        else if(grid[i][col] != '+'){
            helper[i-row] = false;
        }
    }
}

void resetVertical(char grid[10][10],bool helper[],int row,int col,string word){
    for(int i=row;i<row+word.size();i++){
        if(helper[i-row] == true){
            grid[i][col] = '-';
        }
    }
}


void setHorizontal(char grid[10][10], bool helper[],int row,int col,string word){
    for(int i=col;i<col+word.size();i++){
        if(grid[row][i] == '-'){
            grid[row][i] = word[i-col];
        	helper[i-col] = true;
        }
        else if(grid[row][i] != '+'){
            helper[i-col] = false;
        }
    }
}

void resetHorizontal(char grid[10][10],bool helper[],int row,int col,string word){
    for(int i=col;i<col+word.size();i++){
        if(helper[i-col] == true){
            grid[row][i] = '-';
        }
    }
}


bool crossword(char grid[10][10],vector<string> words,int index){
    if(index == words.size()){
        //print
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
               	cout<<grid[i][j];
            }
            cout<<endl;
    	}
        return true;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(grid[i][j] == '-' || grid[i][j] == words[index][0]){
                if(isValidVertical(grid,i,j,words[index])){
                    bool helper[words[index].size()];
                    setvertical(grid,helper,i,j,words[index]);
                    bool ans= crossword(grid,words,index+1);
                    if(ans)
                        return true;
                    if(!ans){
                        resetVertical(grid,helper,i,j,words[index]);
                    }
                }
                if(isValidHorizontal(grid,i,j,words[index])){
                    bool helper[words[index].size()];
                    setHorizontal(grid,helper,i,j,words[index]);
                    bool ans= crossword(grid,words,index+1);
                    if(ans)
                        return true;
                    if(!ans){
                        resetHorizontal(grid,helper,i,j,words[index]);
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>grid[i][j];
        }
    }
    vector<string> words;
    string rawwords;
    cin>>rawwords;
    int i=0;
    string currentword = "";
    while(rawwords[i] != '\0'){
        if(rawwords[i] == ';'){
            words.push_back(currentword);
            currentword = "";
            i++;
            continue;
        }
        currentword += rawwords[i];
        i++;
    }
    words.push_back(currentword);
    crossword(grid,words,0);
    // write your code here
    return 0;
} 
