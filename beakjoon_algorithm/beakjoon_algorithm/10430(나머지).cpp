//
//  10430(나머지).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    
    int a,b,c;
    cin >> a >> b >> c;
    
    cout << (a+b) % c << endl;
    cout << (a%c + b%c)%c << endl;
    cout << ((a*b) % c) << endl;
    cout << (a%c * b%c) %c << endl;
    
    
}
