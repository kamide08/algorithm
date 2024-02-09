#include <stdio.h>

int main(void){
  char T[] = "ABABCDEFGHA";
    char P[] = "ABC";
    char judge[11];

    int T_number = 11;
    int P_number = 3;
    int i;//テキストに対して照合を行う位置の先頭
    int j;//パターンに対して照合を行う位置の先頭
    int judge_count = 0;

    i = 0;
    while( i < (T_number - P_number +1))
    {
        printf("%d番目\n",i);
        j = 0;
        while(T[i+j] == P[j] && (j < P_number)){
             printf("%s\n",T);
        for(int k=0; k < j+i; k++)//一致するところに+を表示
         {
            printf(" ");
         }
        printf("+");
        printf("\n");
        for(int k=0; k < i; k++)//一致するところにパターンをずらす
         {
            printf(" ");
         }
        printf("%s\n\n",P);
        j++;
        judge_count ++;
        }
        if( j == P_number){
            printf("テキストindex=%dの位置にありました\n",i);
            printf("比較回数は%d回です。\n",judge_count);
            return 0;
        }
        printf("%s\n",T);
         for(int k=0; k < j+i; k++)//一致しないところに|を表示
         {
            printf(" ");
         }
         printf("|");
         printf("\n");
         for(int k=0; k < i; k++)//一致しないところにパターンをずらす
         {
            printf(" ");
         }
         printf("%s\n\n",P);
        i++;
        judge_count++;
    }
    printf("一致しない(テキスト%s)中でパターン(%s)は見つかりませんでした)\n",T,P);
    printf("比較回数は%d回です。\n",judge_count);
}
