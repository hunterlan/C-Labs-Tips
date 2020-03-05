#include<time.h>

#define N 5
#define K 20
void transform_and_execute(int arr[N * N]);
void fill_random(int arr[N * N]);
void transform(int arr[][N]);
void sort(int arr[N]);

int main()
{
	int start[N * N];

	fill_random(start);
	transform_and_execute(start);

	return 0;
}

void transform_and_execute(int arr[N * N])
{
	int doubleArr[N][N];

	for (int i = 0, k = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			doubleArr[i][j] = arr[k];
			k++;
		}
	}

	transform(doubleArr);

	for (int i = 0, k = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[k] = doubleArr[i][j];
			k++;
		}
	}
}

void fill_random(int arr[N * N])
{
	for (int i = 0; i < N * N; i++)
	{
		arr[i] = (5 * K) + rand() % ((20 * K) - (5 * K));
	}
}

void transform(int arr[][N])
{
	int result[N];
	int k = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				result[k] = arr[i][j];
				k++;
				break;
			}
		}
	}

	sort(result);
}

void sort(int arr[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}