#include <stdio.h>
double get_array_avg(int values[], int n); // int* values , int values[] 모두 가능하다
void print_array(int values[], int n);

int main()
{
    int values[5] = {10, 20, 30, 40, 50};
    print_array(values, 5);
    printf("get_array_avg()호출\n");
    printf("배열 원소들의 평균 = %lf\n", get_array_avg(values, 5));
    return 0;
}

void print_array(int values[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", values[i]);
    }
    printf("]\n");
}

double get_array_avg(int values[], int n)
{
    double average = 0;
    for (int i = 0; i < n; i++)
    {
        average += values[i];
    }
    return average / n;
}