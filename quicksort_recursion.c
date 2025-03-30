#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int inp[], int boarder_l, int boarder_r){//Сортирует массив через quicksort без рекурсии
    if(inp == NULL || boarder_l<boarder_r){
        int middle = (boarder_r+boarder_l)/2;
        int bad_left = boarder_l, bad_right = boarder_r, good_left, good_right;
        while(good_left < middle){ //Сортируем массив относительно центрального элемента справа
            while(inp[bad_left] <= inp[middle] && bad_left < middle){
                bad_left++;
            }
            if(bad_left == middle){break;}
            good_left = bad_left+1;
            while(inp[good_left] >= inp[middle] && good_left < middle){
                good_left++;
            }
            if(good_left == middle){break;}
            swap(inp[good_left], inp[bad_left]);
            good_left++;
            bad_left++;
        }
        if(bad_left != middle){
            assert(good_left = middle);
            swap(inp[good_left], inp[bad_left]);
            middle = bad_left;
        }
        while(good_right < middle){ //Сортируем массив относительно центрального элемента слева
            while(inp[bad_right] >= inp[middle] && bad_right > middle){
                bad_right--;
            }
            if(bad_right == middle){break;}
            good_right = bad_right+1;
            while(inp[good_right] <= inp[middle] && good_right > middle){
                good_right--;
            }
            if(good_right == middle){break;}
            swap(inp[good_right], inp[bad_right]);
            good_right++;
            bad_right++;
        }
        if(bad_right != middle){
            assert(good_right = middle);
            swap(inp[good_right], inp[bad_right]);
            middle = bad_right;
        }
        //Запускаем сортировки справа и слева
        if(middle - boarder_l > 2){
            quicksort(inp, boarder_l, middle-1);
        }
        if(boarder_r - middle > 2){
            quicksort(inp, middle+1, boarder_r);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int inp[n];
    for (int i=0; i<n; i++){
        scanf("%d", &inp[i]);
    }
    quicksort(inp, 0, n-1);
    for (int i=0; i<n; i++){
        printf("%d", inp[i]);
    }
    return 0;
}