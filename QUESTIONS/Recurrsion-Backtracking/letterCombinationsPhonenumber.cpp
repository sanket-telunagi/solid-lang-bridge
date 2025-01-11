/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
    Return the answer in any order.

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Input: digits = ""
    Output: []

    Input: digits = "2"
    Output: ["a","b","c"]
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

void genCominations(string &digits, vector<string> &out, unordered_map<char,string> &mapping,string &combination,int index){
    // base condition
    if(index == digits.size()) {
        if(combination.size() != 0) out.push_back(combination) ;
        return ;
    }

    // Procesing 
    for (char i : mapping[digits[index]]){  // each letter in first digit map
        combination.push_back(i);
        genCominations(digits,out,mapping,combination,index+1) ;
        combination.pop_back() ;
    }
}

vector<string> letterCombinations(string &digits) {
    unordered_map<char,string> mapping = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> ans ;
    string combination = "" ;
    genCominations(digits,ans,mapping,combination,0) ; // starting index 0
    return ans ;
}

int main() {
    string s ;
    cin >> s ;
    vector<string> ans ;
    ans = letterCombinations(s) ;
    for (auto it : ans){
        cout << it << " " ;
    }
    return 0 ;
}