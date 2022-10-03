//You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
//You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.


#include <unordered_map> 
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, bool> um; 
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) { 
        index[arr[i]] = i; 
        if (um.count(arr[i]) == 0) {
            um[arr[i]] = true; 
        }
    }
    vector<int> ans;
    int maxlength = 1; 
    int start = 0; 
    for (int i = 0; i < n; i++) { 
        int num = arr[i];
        int currentindex = i;
        int length = 0;
        int j = arr[i];
        // Forward 
        while (um.count(j) == 1 && um[j] == true)
        { 
            um[j] = false; 
            length++;
            j++; 
        }
        // Backward 
        j = num - 1;
        while (um.count(j) == 1 && um[j] == true) {
            um[j] = false;
            length++; 
            currentindex = index[j]; 
            j--; 
        }
        if (length > maxlength) { 
            maxlength = length;
            start = currentindex; 
        }
        else if (length == maxlength) {
            if (currentindex < start) { 
                start = currentindex;
            }
        }
    }
    int startnum = arr[start]; 
    ans.push_back(startnum);
    if (maxlength > 1) {
        ans.push_back(startnum + maxlength - 1);
    }
    return ans;
    } 
