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

void push_heap(int T[], int x);
int delete_maximum(int T[]);
void view_array(int array[], int n);
void view_array_heap(int array[]);

int size = 0;

int main(void)
{
    int data[N] = {42, 33, 78, 19, 46, 63, 25, 11, 54, 17};
    int T[N + 1];

    printf("以下の配列をソートします。\n");
    view_array(data, N);
    printf("-------------------------------------\n");

    printf("ヒープ配列に挿入\n");
    printf("----------------\n");
    for (int i = 0; i < N; i = i + 1)
    {
        push_heap(T, data[i]);
        view_array_heap(T);
        printf("\n");
        printf("\n");
    }

    printf("ヒープ配列からdata配列に挿入\n");
    printf("----------------------------\n");
    for (int i = 0; i < N; i = i + 1) //
    {
        data[i] = delete_maximum(T);
        view_array_heap(T);
        printf("ヒープの根が%dにかわりました", T[1]);
        printf("\n");
        printf("\n");
    }

    printf("-------------------------------------\n");
    printf("以下がソート後の配列です。\n");
    view_array(data, N);

    return 1;
}

void push_heap(int T[], int x)
{
    size++;
    T[size] = x;
    int k = size;

    while ((T[k] > T[k / 2]) && (k > 1))
    {
        swap(T[k], T[k / 2]);
        k = k / 2;
    }
}

int delete_maximum(int T[])
{
    int output;
    int k = 1;
    output = T[1];

    T[1] = T[size];
    T[size] = 0;
    size--;
    while (2 * k <= size) // 子をもつか判定
    {
        if (2 * k == size) // 子が一つの場合
        {
            if (T[k] < T[2 * k])
            {
                swap(T[k], T[2 * k]);
                k = 2 * k;
            }
            else
            {
                return output;
            }
        }
        else // 子が2つの場合
        {
            int big;
            if (T[2 * k] > T[2 * k + 1])
            {
                big = 2 * k;
            }
            else
            {
                big = 2 * k + 1;
            }
            if (T[k] < T[big])
            {
                swap(T[k], T[big]);
                k = big;
            }
            else
            {
                return output;
            }
        }
    }
    return output;
}

void view_array(int array[], int n)
{
    printf("data={");
    for (int i = 0; i < N; i++)
    {
        printf("%d,", array[i]);
    }
    printf("}");
    printf("\n");
}

void view_array_heap(int array[])
{
    printf("T={");
    for (int i = 1; i <= size; i++)
    {
        printf("%d,", array[i]);
    }
    printf("} ");
}
