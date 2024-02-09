#include <stdio.h>
#define N 10
#define swap(a, b) \
    do             \
    {              \
        int tmp;   \
        tmp = a;   \
        a = b;     \
        b = tmp;   \
    } while (0)

void bubble_sort(int D[], int n);
void view_array(int D[], int n);
void view_exchanged_index(int D[], int n, int j);

int main(void)
{
    int data[10] = {42, 33, 78, 19, 46, 63, 25, 11, 54, 17};

    printf("以下の配列をソートします。\n");
    view_array(data, N);
    printf("-------------------------------------");

    printf("\n");
    bubble_sort(data, N);

    printf("-------------------------------------\n");
    printf("以下がソート後の配列です。\n");
    view_array(data, N);

    return 1;
}

void bubble_sort(int D[], int n)
{
    for (int i = 0; i < n - 1; i = i + 1)
    {
        for (int j = n - 1; j >= i + 1; j = j - 1)
        {
            if (D[j] < D[j - 1])
            {
                swap(D[j - 1], D[j]);
                view_exchanged_index(D, n, j);
                printf("\n");
            }
            else
            {
                view_array(D, n);
                printf("\n");
            }
        }
    }
}

void view_array(int D[], int n) // ソース結果をターミナルに出力
{
    printf("data={");
    for (int i = 0; i < N; i++)
    {
        printf("%d,", D[i]);
    }
    printf("}");
    printf("\n");
}

void view_exchanged_index(int D[], int n, int j) // 交換された値に[]をつける
{
    printf("data={");
    for (int i = 0; i < N; i++)
    {
        if (i == j || i == (j - 1))
        {
            printf("[%d],", D[i]);
        }
        else
        {
            printf("%d,", D[i]);
        }
    }
    printf("}");
    printf("\n");
}
