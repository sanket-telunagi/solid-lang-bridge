#include <iostream>
using namespace std ;

int main()
{
    int num ; 
    cin >> num ; 
    if (num % 2 == 0) {
        if ((num / 2) % 2 == 0 ) {
            cout << "YES" << endl ;
        }else {
            cout << "NO" << endl ;
        }
    }else {
        cout << "NO" << endl ;
    }
    return 0 ;
}