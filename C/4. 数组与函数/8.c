//顺序查找int search(int arr[], int n, int key);
#include <stdio.h>
int search(int arr[], int n, int key);
int main(void)
{
    int n, arr[100], key, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &key);
    search(arr, n, key) == -1 ? printf("Not found!") : printf("Found!");
    return 0;
}
//函数功能：按顺序查找法找值为key的数组元素，若找到则返回x在数组中的下标位置，否则返回-1
int search(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}