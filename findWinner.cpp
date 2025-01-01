#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1); 
        int j = 0;
        while (v.size() > 1) {
            
            j = (j + k - 1) % v.size(); 
            v.erase(v.begin() + j); 
        }
        return v[0]; 
    }
};
