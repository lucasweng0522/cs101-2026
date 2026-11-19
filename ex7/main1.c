#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:");
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    if (n < 1) n = 1;
    if (n > 5) n = 5;

    srand((unsigned int)time(NULL));

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        perror("無法開啟 lotto.txt");
        return 1;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
 
    if (time_str != NULL) {
        for (int i = 0; time_str[i] != '\0'; i++) {
            if (time_str[i] == '\n') {
                time_str[i] = '\0';
                break;
            }
        }
    }

    fprintf(fp, "= lotto649 =\n");
    fprintf(fp, "%s\n", time_str ? time_str : "");

    for (int i = 1; i <= 5; i++) {
        if (i <= n) {
            int used[70] = {0}; 
            int nums[7];
            int count = 0;

            while (count < 7) {
                int r = (rand() % 69) + 1;
                if (!used[r]) {
                    used[r] = 1;
                    nums[count++] = r;
                }
            }

            fprintf(fp, "[%d]:", i);
            for (int j = 0; j < 7; j++) {
                fprintf(fp, " %02d", nums[j]);
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "[%d]: --\n", i);
        }
    }

    fprintf(fp, "csie@CGU\n");
    fclose(fp);

    printf("以為您購買的%d組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
