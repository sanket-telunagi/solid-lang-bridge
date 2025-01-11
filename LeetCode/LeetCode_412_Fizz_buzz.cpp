#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

string numToStr(int num) {
    string str = "" ;
    while (num) {
        str.push_back((num % 10) + '0') ;
        num /= 10 ;
    }
    for (int i = 0 ; i < str.length()/2; i++) {
        swap(str[i], str[str.length() - 1- i]) ;
    }
    return str ;
}
vector<string> fizzBuzz(int n) {
    vector<string> res(n) ;
    while (n) {
        if (n % 3 == 0 and n % 5 == 0) {
            res[n -1] = ("FizzBuzz") ;
        } else if (n % 5 == 0) {
            res[n-1] = ("Buzz") ;
        } else if (n % 3 == 0) {
            res[n-1] = ("Fizz") ;
        } else {
            res[n-1] = (to_string(n)) ;
        }
        n-- ;
    }
    
    return res ;
}

int main()
{
    int n ;
    cin >> n ;
    for (string it : fizzBuzz(n)) {
        cout << it << " " ;
    }
    return 0 ;
}