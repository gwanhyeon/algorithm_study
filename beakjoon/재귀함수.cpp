
//
//  recursive_call_exam.cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 6..
//  Copyright © 2018년 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int Recursive(int num){
    
    if(num == 1 ){
        return 1;
    }else{
        return num + Recursive(num - 1);
    }

}
int main(void){
    
    int num = Recursive(3);
    cout << num << endl;
    
}
