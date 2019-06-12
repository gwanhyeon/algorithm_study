#include <stdio.h>


union A{
    int a;
}
union B{
    int A.a;
}
int main() {
    static int num = 100;
    int a[num];
    
    
    return 0;
}
