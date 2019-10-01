#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>


using namespace std;
vector<int> res;

int arr[10];
int check[10];
vector<int> v;

void go(int index, int n, int m){
    
    if(index == m){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(check[i] == 1){
            continue;
        }
        
        check[i] = 1;
        v.push_back(i);
        go(index+1,n,m);
        check[i] = 0;
        v.pop_back();
        
        
    }
    
    
}
int main(void){
    
    int n,m = 0;
    memset(check,0,sizeof(check));
    cin >> n >> m;

    go(0,n,m);
    return 0;
}
