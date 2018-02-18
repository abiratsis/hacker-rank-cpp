#include "arrays.hpp"

vector<int> leftRotation(vector<int> a, int d) {  
    
    for(int i = 0; i < d; ++i){
        int pop = a[i];
        a.push_back(pop);
    }
    a.erase(a.begin(), a.begin() + d);
    
    return a;
}

int solveBalancedArray(vector<int> a){
    if(a.size() % 2!= 0)
        return 0;
    
    int leftSum = 0, rightSum = 0;;
    for(int i=0; i<a.size(); i++){
        if(i < a.size()/2)
            leftSum += a[i];
        else
            rightSum += a[i];
    }
    
    return abs(leftSum - rightSum);
}
