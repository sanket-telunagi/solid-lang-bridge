#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map <string, int> m ;
    int t ;
    cin >> t ;
    while (t--) {
        int x , marks;
        string s ;
        cin >> x >> s;
        
        if (x == 1) {
            cin >> marks ;
            m[s] += marks ;
        }
        else if (x == 2 || x == 3){
            if (x == 2) m[s] = 0 ;
            else if (x == 3) cout << m[s] << endl ;
        }
    }  
    return 0;
}



