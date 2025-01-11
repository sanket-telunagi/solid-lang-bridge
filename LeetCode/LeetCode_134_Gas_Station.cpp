#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    There are n gas stations along a circular route, 
    where the amount of gas at the ith station is gas[i].
    You have a car with an unlimited gas tank and it costs cost[i] of gas 
    to travel from the ith station to its next (i + 1)th station. 
    You begin the journey with an empty tank at one of the gas stations.
    Given two integer arrays gas and cost, 
    return the starting gas station's index if you can travel around 
    the circuit once in the clockwise direction, otherwise return -1. 
    If there exists a solution, it is guaranteed to be unique
*/

// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

//     for (int i = 0; i < gas.size(); i++)
//     {
//         int balance = 0 ;
//         {
//             if (gas[i] - cost[i] >= 0) {
//                 for (int j = i; j < gas.size(); j++)
//                 {
//                     balance += (gas[j] - cost[j]) ;
//                     if (balance < 0) break;
//                 }
//                 if (balance >= 0) {
//                     for (int k = 0; k < i; k++)
//                     {
//                         balance += (gas[k] - cost[k]) ;
//                     } 
//                 }
//                 if (balance >= 0)
//                 {
//                     return i ;
//                 }else {
//                     break ;
//                 }
                
//             }
//         }
//     }
//     return -1 ;
// }

int canCompleteCircuit(vector<int> & gas, vector<int> & cost) {
    int index = 0 , gas_sum = 0, cost_sum = 0 ;
    for (int i = 0; i < gas.size(); i++)
    {
        cost_sum += gas[i] - cost[i] ;
        gas_sum += gas[i] - cost[i] ;
        if (cost_sum < 0) {
            index = i+1 ;
            cost_sum = 0 ;
        }
    }
    return gas_sum >= 0 ? index : -1 ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> gas(n),cost(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> gas[i] ;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i] ;
    }
    
    cout << canCompleteCircuit(gas,cost) ;
    return 0 ;
}