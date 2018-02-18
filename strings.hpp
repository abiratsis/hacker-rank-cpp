/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   strings.hpp
 * Author: abiratsis
 *
 * Created on January 6, 2018, 7:54 PM
 */

#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

vector<int> z_function(string s);
int stringSimilarity(string s);
string richieRich(string s, int n, int k);
bool isPalindrome(string s);
int anagram(string s);
int makingAnagrams(string s1, string s2);
string gameOfThrones(string s);
std::unordered_multiset<int> weightedUniformString(string s);
#endif /* STRINGS_HPP */

