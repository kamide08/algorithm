#include <stdio.h>
#define N 10

void insertion_sort(int D[], int n);
void view_array(int D[], int n);
void view_exchanged_index(int D[], int n, int index);

int main(void)
{
    int data[N] = {42, 33, 78, 19, 46, 63, 25, 11, 54, 17};

    printf("以下の配列をソートします。\n");
    view_array(data, N);
    printf("-------------------------------------");

    printf("\n");
    insertion_sort(data, N);

    printf("-------------------------------------\n");
    printf("以下がソート後の配列です。\n");
    view_array(data, N);

    return 1;
}

void insertion_sort(int D[], int n)
{
    int j;
    int x;
    for (int i = 1; i < n; i++)
    {
        x = D[i];
        j = i;
        while ((D[j - 1] > x) && (j > 0))
        {
            D[j] = D[j - 1];
            view_exchanged_index(D, n, j);
            printf("\n");
            j--;
        }
        D[j] = x;
        view_exchanged_index(D, n, j);
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

void view_exchanged_index(int D[], int n, int index)
{
    printf("data={");
    for (int i = 0; i < n; i++)
    {
        if (i == index)
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
