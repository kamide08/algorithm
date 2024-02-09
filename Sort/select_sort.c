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

void select_sort(int D[], int n);
void view_array(int D[], int n);
void view_array_change_color(int D[], int n, int index, int max_index);
int main(void)
{
    int data[10] = {42, 33, 78, 19, 46, 63, 25, 11, 54, 17};

    /*printf("整数を10個入力してください。\n");
    for (int i = 0; i < N; i++)
    {
        int tmp;
        printf("data[%d]=", i);
        scanf("%d", &tmp);
        data[i] = tmp;
    }*/

    printf("以下の配列をソートします。\n");
    view_array(data, N);
    printf("-------------------------------------");

    printf("\n");
    select_sort(data, N);

    printf("-------------------------------------\n");
    printf("以下がソート後の配列です。\n");
    view_array(data, N);

    return 1;
}

void select_sort(int D[], int n)
{
    int max;
    int max_index;
    for (int i = n - 1; i > 0; i--)
    {
        max = D[0];
        max_index = 0;
        for (int j = 1; j <= i; j++)
        {
            if (D[j] >= max)
            {
                max = D[j];
                max_index = j;
            }
        }
        swap(D[max_index], D[i]);
        view_array_change_color(D, n, i, max_index);
        printf("\n");
    }
}

void view_array(int D[], int n)
{
    printf("data={");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", D[i]);
    }
    printf("}");
    printf("\n");
}

void view_array_change_color(int D[], int n, int index, int max_index)
{
    printf("data={");
    for (int i = 0; i < n; i++)
    {
        if (i == index || i == max_index)
        {
            printf("\x1b[31m");
            printf("%d,", D[i]);
            printf("\x1b[0m");
        }
        else
        {
            printf("%d,", D[i]);
        }
    }
    printf("}");
    printf("\n");
}
