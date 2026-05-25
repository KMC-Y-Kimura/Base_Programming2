#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pin;
    int duration;
} LedPattern;

int main(void) {
    int n;
    int sum_duration = 0;

    printf("LED パターンを何個登録しますか？: ");
    scanf("%d", &n);

    LedPattern *patterns = malloc(n * sizeof(LedPattern));

    if (patterns == NULL) {
        fprintf(stderr, "メモリ確保に失敗しました\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("パターン%d — ピン番号: ", i + 1);
        scanf("%d", &patterns[i].pin);
        printf("パターン%d — 点灯時間(ms): ", i + 1);
        scanf("%d", &patterns[i].duration);
        sum_duration += patterns[i].duration;
    }

    printf("\n--- 登録した LED シーケンス ---\n");
    for (int i = 0; i < n; i++) {
        printf("パターン%d: ピン%dを%dms点灯\n",
               i + 1, patterns[i].pin, patterns[i].duration);
    }

    free(patterns);
    patterns = NULL;

    printf("\nプログラム終了\n");
    printf("合計点灯時間: %dms\n", sum_duration);
    return 0;
}