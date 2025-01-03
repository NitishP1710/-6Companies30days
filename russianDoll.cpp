#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int binarySearch(vector<int>& lis, int target) {
        int left = 0, right = lis.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (lis[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }
        return left; 
    }
     //array is sorted such that if width are same then sort height decresing else sort height in increasing
    static bool comparator(pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first)
            return p1.second > p2.second; 
        return p1.first < p2.first;      
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int>> env;
        for (auto e : envelopes) {
            env.push_back({e[0], e[1]});
        }

        
        sort(env.begin(), env.end(), comparator);
        for(auto e:env){
            cout<<e.first<<" "<<e.second<<endl;
        }
        
        vector<int> heights;
        for (auto e : env) {
            heights.push_back(e.second);
        }
    
        vector<int> lis;
        for (int h : heights) {
            int pos = binarySearch(lis, h);
            if (pos == lis.size()) {
                lis.push_back(h); 
             } else {
                lis[pos] = h; 
             }
        }

        return lis.size();
    }
};
