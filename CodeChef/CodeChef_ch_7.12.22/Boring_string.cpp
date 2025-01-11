#include<bits/stdc++.h>
#include <iostream>
using namespace std;

vector<string> subsets ;

void gen(string & it, string s , int i){
    if (i == s.size()) {
        subsets.push_back(it) ;
        // cout << it << endl ;
        return ;
    }
    
    // not taken
    gen(it, s, i+1) ;
    
    // taken 
    it.push_back(s[i]) ;
    gen(it, s, i+1) ;
    it.pop_back() ;
}

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while (t--) {
	    int x ;
	    string s ;
	    cin >> x >> s;
	    string empty  = "";
	    gen(empty,s,0) ;
    	unordered_map<string,int> m ;
    	for (auto it : subsets) {
    	    m[it]++ ;
    	}
    	
    	string max = "";
    	int cnt = 1 ;
    	for(auto it : m){
    	    if ((it.second-1) > cnt) {
    	        cnt = it.second ;
    	        max = it.first ;
                cout << "substring " << it.first << " " << it.second << endl ;
    	    }
    	}
    	cout <<( max.size() == 0 ? 0 : max.size() ) << endl ; 
        subsets.clear() ;
	}
	return 0;
}
