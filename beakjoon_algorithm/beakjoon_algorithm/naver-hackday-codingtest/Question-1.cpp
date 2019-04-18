#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int solution(vector<int> &A){
    cout << A.size();
    return 1;
    
}

int main(void){
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    int result = solution(A);
    cout << result;
    
    
}

