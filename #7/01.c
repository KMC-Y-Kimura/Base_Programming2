#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(10 * sizeof(int));
    
    if (arr == NULL) {
        printf("メモリ確保失敗\n");
        return 1;
    }
    
    // 2. 値を代入
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }
    
    // 3. 値を表示
    printf("配列の内容:\n");
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d (アドレス: %p)\n", i, arr[i], (void *)&arr[i]);
    }
    
    // 4. メモリを解放
    free(arr);
    arr = NULL;
    
    printf("\nメモリ解放完了\n");
    printf("sizeof(int) = %zu バイト\n", sizeof(int));
    printf("確保したメモリ = 10 * %zu = %zu バイト\n", sizeof(int), 10 * sizeof(int));
    
    return 0;
}