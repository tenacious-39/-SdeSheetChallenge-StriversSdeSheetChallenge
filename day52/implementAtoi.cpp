#include<bits/stdc++.h>
int atoi(string str) {
    // Write your code here.
    int n = str.size();
    int mult = 1, num = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        mult = 1 - 2 * (str[i++] == '-'); 
    }
    while (i < n) {
        
        if(isdigit(str[i]))num  = 10 * num + (str[i] - '0');
        i++;
    }
    return num * mult;
}
