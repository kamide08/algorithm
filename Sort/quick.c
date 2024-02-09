#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define swap(a, b) \
    do             \
    {              \
        int tmp;   \
        tmp = a;   \
        a = b;     \
        b = tmp;   \
    } while (0)

void view_array(int D[], int n);
void view_exchanged_index(int D[], int n, int index_1, int index_2);
int partition(int D[], int left, int right);
void quick_sort(int D[], int left, int right);

int main(void)
{
    srand((unsigned)time(NULL));
    int data[N] = {42, 33, 78, 19, 46, 63, 25, 11, 54, 17};

    printf("以下の配列をソートします。\n");
    view_array(data, N);
    printf("-------------------------------------\n");

    quick_sort(data, 0, (N - 1));
    printf("-------------------------------------\n");
    printf("以下がソート後の配列です。\n");
    view_array(data, N);

    return 1;
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

void view_exchanged_index(int D[], int n, int index_1, int index_2)
{
    printf("data={");
    for (int i = 0; i < n; i++)
    {
        if (i == index_1 || i == index_2)
        {
            printf("[%d],", D[i]);
        }
        else
        {
            printf("%d,", D[i]);
        }
    }
    printf("}");
}

int partition(int D[], int left, int right)
{
    int k = rand() % (right - left + 1) + left;

    swap(D[k], D[right]);
    printf("-------------------------------------\n");
    view_exchanged_index(D, N, k, right);
    printf("%dが基準値、left:%d、right:%d", D[right], left, right);
    printf("\n");
    printf("\n");
    int i = left;
    int j = right - 1;
    while (i <= j)
    {
        while (D[i] < D[right])
        {
            i++;
        }
        while ((D[j] >= D[right]) && j >= i)
        {
            j--;
        }
        if (i < j)
        {
            swap(D[i], D[j]);
            view_exchanged_index(D, N, i, j);
            printf("\n");
            printf("\n");
        }
    }
    swap(D[i], D[right]);
    view_exchanged_index(D, N, i, right);
    printf("\n");
    printf("\n");
    return i;
}

void quick_sort(int D[], int left, int right)
{
    int pivot_index = 0;
    if (left < right)
    {
        pivot_index = partition(D, left, right);
        quick_sort(D, left, (pivot_index - 1));
        quick_sort(D, (pivot_index + 1), right);
    }
}

