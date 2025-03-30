#include <stdio.h>
#include <assert.h>

//Находит самое левое вхождение числа в массиве
int binary_search(int inp[], int l, int r, int goal){
    if(inp == NULL || l>r){
        return -1;
    }
    int middle;
    while(l!=r){
        assert(l<r);
        middle = (l+r)/2;
        if(inp[middle] < goal){
            l = middle + 1;
        }
        else{
            r = middle;
        }
    }
    assert(l==r);
    if(inp[l] == goal){
        return l;
    }
    return -1;
}
int main() {
    int n, goal;
    scanf("%d", &n);
    int inp[n];
    for (int i=0; i<n; i++){
        scanf("%d", &inp[i]);
    }
    scanf("%d", &goal);
    int out = binary_search(inp, 0, n, goal);
    printf("%d", out);
    return 0;
}