#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    float distance(int xc, int yc, int x, int y) {
        return sqrt((xc - x) * (xc - x) + (yc - y) * (yc - y));
    }
    
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) {
            return true; 
        }
        
        
        if (distance(xCenter, yCenter, x1, y1) <= radius || 
            distance(xCenter, yCenter, x1, y2) <= radius || 
            distance(xCenter, yCenter, x2, y1) <= radius || 
            distance(xCenter, yCenter, x2, y2) <= radius) {
            return true; 
        }

     
        if (xCenter >= x1 && xCenter <= x2 && 
            (abs(yCenter - y1) <= radius || abs(yCenter - y2) <= radius)) {
            return true; 
        }
        
        if (yCenter >= y1 && yCenter <= y2 && 
            (abs(xCenter - x1) <= radius || abs(xCenter - x2) <= radius)) {
            return true; 
        }
        
        return false; 
    }
};
