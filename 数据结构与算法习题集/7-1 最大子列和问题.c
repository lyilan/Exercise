/*
 * @Author: lyilan
 * @Date: 2021-04-01 01:08:01
 * @Description: for my ying~
 */
#include <stdio.h>

int main()
{
    int K;
    scanf("%d", &K); //序列元素数

    int Max_sum = 0, sum = 0, e;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &e);
        sum += e;
        if (sum < 0)
            sum = 0; //如果连续的序列和为负数，直接舍弃
        else if (sum > Max_sum)
            Max_sum = sum; //如果序列和大于Max，更新Max
    }
    printf("%d", Max_sum);
    return 0;
}