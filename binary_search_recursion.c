#include <stdio.h>

//Находит самое левое вхождение числа в массиве
int binary_search(int inp[], int l, int r, int goal){
    if(inp == NULL || l>r){
        return -1;
    }
    if(l==r){
        if(inp[l] == goal){
            return l;
        }
        return -1;
    }
    int middle= (l+r)/2;
    if(inp[middle] < goal){
        return binary_search(inp,  middle + 1, r, goal);
    }
    else {
        return binary_search(inp,  l, middle, goal);
    }
}
int main() {
    int n, goal;
    scanf("%d", &n);
    int inp[n];
    for (int i=0; i<n; i++){
        scanf("%d", &inp[i]);
    }
    scanf("%d", &goal);
    int out = binary_search(inp, 0, n-1, goal);
    printf("%d", out);
    return 0;
}
