// Episode of stacks and Queue 

//Stack : 
/*
            LIFO - Last In First Out
            Only accesed last / top element

                | 1 |  <-- Top
                +---+
                | 2 |
                +---+
                | 3 |
                +---+
                | 4 |
                +---+

            Ops - 
                    1. Push          
                    2. Pop
                    3. Top
            
            Acessed - 
                    1. Top element
                    2. size

            STL :

                Declare : stack < data_type > veriable_name
                methods : 
                            push(ele) ;
                            pop() ;
                            empty()  -- bool retuens
                            top() -- returns top ele
*/


/*
    Queue : 
            FIFO - First In First Out

                    first
                    +---+---+---+---+---+
            OUT <---| 1 | 2 | 3 | 4 | 5 |   <--- IN
                    +---+---+---+---+---+
                                     last
            
            Ops - 
                    1. Push 
                    2. Pop
                    3. Front
                    4. 
            
            Acessed - 
                    1. Top element
                    2. size

            STL :
                Declare : queue < data_type > veriable_name 
                methods : 
                            push()
                            empty() -- bool return
                            front() -- front element return
                            pop() -- removes first element 
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    
    stack < int > s ;
    queue < int > q ;
    s.push(1) ;
    s.push(2) ;
    s.push(10) ;
    while(!s.empty()) {
        cout << s.top() << endl ;
        s.pop() ;
    }

    q.push(30) ;
    q.push(40) ;
    q.push(50) ;
    while(!q.empty()) {
        cout << q.front() << endl ;
        q.pop() ;
    }

    return 0 ;
}