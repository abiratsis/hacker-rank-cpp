#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include "code_sprints.hpp"


int toBase10(string sb, int base){
    int sum = 0, p = sb.length() - 1;    
    for(int i=0; i<sb.length(); i++,p--){
        sum +=  pow(base, p) * (sb[i] - '0');
    }
    
    return sum;
}

int getMagicNumber(string s, int k, int b, int m){
    int sum = 0;
    for(int i; i<=s.length() - k; i++){
        auto sub = s.substr(i, k);
        sum += toBase10(sub, b) % m;
    }    
    return sum;
}

bool cmp (int i, int j) { 
    return (__builtin_popcount (i) <__builtin_popcount(j)); 
}

int solve(int* a, int N){
    std::sort(a, a + N, cmp);
    
    int y=1, x=0, xbits = 1, xbitsmin = INT_MAX, maxi=67108864; 
    for(;y<maxi; y++){
        xbits = __builtin_popcount(y);       
        if(xbits >= xbitsmin)  
            continue;
        
        bool valid = true;
        for(int i=0; i<N; i++){
            if((y & a[i]) == false){
                valid = false;
                break;
            }
        }
         
        if(valid && xbits < xbitsmin){
            x = y;
            xbitsmin = xbits;
        }
    }
    return x;
}