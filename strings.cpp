#include  "strings.hpp"

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int stringSimilarity(string s) {
    auto z = z_function(s);
    
    int sum = 0;
    for (int n : z)
        sum += n;
    
    return sum + s.length();
}

inline const int toInteger(const char c){ return c - '0';}
bool isPalindrome(string s){
    
    for(int l=0, r=s.length()-1; l<s.length()/2; ++l,--r){
        if(s[l]!=s[r])
            return false;
    }
    
    return true;
}

string richieRich(string s, int n, int k){    
    int kc = k;
    
    string tmp = s;    
    int diffs = 0;
    for(int l=0, r=n-1; l<n/2; ++l, --r){
        if(tmp[l] != tmp[r])
            diffs++;
    }
    
    if(diffs > k)
        return "-1";
    
    for(int l=0, r=n-1; l<n/2 && kc > 0; ++l, --r){
        if(tmp[l] != tmp[r]){
            
        }
    }
    
    
    for(int l=0, r=n-1; l<n/2 && kc > 0; ++l, --r){
        
        if(!isPalindrome(tmp)){
            int l_num = toInteger(tmp[l]), r_num = toInteger(tmp[r]);
            
        }
        else{
            if(kc >= 2){
                if(tmp[l] != '9' && tmp[r] != '9'){
                    tmp[r] = tmp[l] = '9';
                    kc-=2;
                }
                else if(tmp[l] == '9' || tmp[r] == '9'){
                    tmp[l] = '9';
                    tmp[r] = '9';
                    kc--;
                }
            }
            else{
                if(tmp[l] != tmp[r]){
                    int l_num = toInteger(tmp[l]), r_num = toInteger(tmp[r]);
                    int max = std::max(l_num, r_num);

                    tmp[l] = tmp[r] = (char)(max + 48);
                    kc--;
                }
            }
        }
    }
    
    if(kc){
        if(n%2 != 0){
            tmp[n/2] = '9';
        }
    }
    
    if(isPalindrome(tmp))
        return tmp;
    
    return "-1";
}

int anagram(string s){
    if(s.length() % 2 != 0)
        return -1;
    
    std::string diff, inter, un;
    int size = s.length();
    string lp = s.substr(0, size / 2);
    string rp = s.substr(size / 2, size / 2);
    
    std::sort(lp.begin(), lp.end());
    std::sort(rp.begin(), rp.end());

    std::set_union(lp.begin(), lp.end(), rp.begin(), rp.end(), std::back_inserter(un));
    std::set_intersection(lp.begin(), lp.end(), rp.begin(), rp.end(), std::back_inserter(inter));
    
    std::set_difference(un.begin(), un.end(), inter.begin(), inter.end(), std::back_inserter(diff));
    
    return diff.length();
}

int makingAnagrams(string s1, string s2){    
    std::string diff, inter, un;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(un));
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(inter));
    
    std::set_difference(un.begin(), un.end(), inter.begin(), inter.end(), std::back_inserter(diff));
    
    return diff.length();
}

string gameOfThrones(string s){
    std::map<char,int> dict;
    for(char c: s){
        auto it = dict.find(c);
        if(it != dict.end())
           dict[c]++;
        else
           dict[c]=1; 
    }

    bool valid = true;
    int count = 0;
    for(auto kv : dict){
        if(s.length() % 2 == 0){
            if(kv.second % 2 != 0){
                valid = false;
                break;
            }
        }else{
            if(kv.second % 2 != 0){
                count++;
                if(count > 1){
                    valid = false;
                    break;
                }
            }
        }
    }
    
    return valid ? "YES" : "NO";
}

std::unordered_multiset<int> weightedUniformString(string s){
    int len = s.length(), sum = 0;
    std::unordered_multiset<int> weights;

    char prev = '\0';
    for(int i=0; i<len; i++){
        int w = s[i] - 'a' + 1;
        
        if(prev == s[i])
            sum += w;
        else
            sum = w;
        
        weights.insert(sum);
        prev = s[i];
    }
    
    return weights;
}

