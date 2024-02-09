#include <stdio.h>

int transfer(char index);
int main(void){

    char T[] = "iwanttoplaytenniswithyou";
    char P[] = "you";
    int S[25];//小文字のアルファベット分だけ確保
    int i;
    int j;
    int T_numbe = 24;//テキストの文字数;
    int P_number = 3;//パターンの文字数
    int judge_count = 0;//比較回数をカウント
    char bin;//テキストのi番目の文字を記憶
   

    for(int i=0; i < 25; i++){
        S[i] = P_number;
    }

    for(int i=0; i < P_number; i++){
        if(i < P_number - 1)
        S[transfer(P[i])] = P_number - i - 1;
    }

    i = 0;

    while(i < T_numbe - P_number+1){
        printf("%d番目\n",i);
        j = P_number-1;
        bin = T[i + j];
        while((T[i+j]) == P[j] && (j >= 0)){
            judge_count ++;
            printf("%s\n",T);
        for(int k=0; k < i+j; k++)//一致するところに+を表示
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
            j = j -1;
        }
        if (j == -1){
            printf("一致したindexは%dでした。\n", i);
            printf("比較回数は%dでした。\n",judge_count);
            return 0;
        }
        else { 
          printf("%s\n",T);
          for(int k=0; k < i+j; k++)//一致するところに+を表示
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
         i = i + S[transfer(bin)];
         judge_count ++;}
    }
    printf("一致しませんでした。\n");
    return 0;
}

int transfer(char index_char){
    int index = index_char;
    index = index - 97;
    return index;
}
