#include<bits/stdc++.h>
int romanToInt(string s) {
    // Write your code here
    unordered_map<char, int> valueOf = { { 'I' , 1 },{ 'V' , 5 }, { 'X' , 10 },{ 'L' , 50 },{ 'C' , 100 },
                                   { 'D' , 500 },{ 'M' , 1000 } };
        int n = s.size();
        int sum = valueOf[s[n-1]];
        for(int i = n-2; i >=0; i--){
            if(valueOf[s[i]] < valueOf[s[i+1]])
                sum -= valueOf[s[i]];
            else sum += valueOf[s[i]];
        } return sum;
}
