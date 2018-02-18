#include <cstdlib>
#include <iostream>
#include "lists.hpp"
#include "arrays.hpp"
#include "strings.hpp"

using namespace std;
//std::unordered_set<int> weightedUniformString(string s)

int solution(vector<int> &A){
    if(A.size() == 0)
        return 0;
    
}



int main(int argc, char** argv) {
    string s;
    cin >> s;
    int n;
    cin >> n;
    
    auto weights = weightedUniformString(s);
    auto end = weights.end();
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if(weights.find(x) != end)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
