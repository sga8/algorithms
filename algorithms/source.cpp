#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int MAX_N = 500050;

int N;
int arr1[MAX_N];

int Q;
int arr2[MAX_N];

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &arr2[i]);
	}
}

int binarySearch(int s, int e, int val) {
	if (s > e) return -1;
	int m = (s + e) / 2;

	if (arr1[m] > val) {
		return binarySearch(s, m - 1, val);
	}
	else if (arr1[m] < val) {
		return binarySearch(m + 1, e, val);
	}
	else {
		return m;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	input();
	int ret = -1;
	for (int i = 0; i < Q; i++) {
		ret = binarySearch(0, N - 1, arr2[i]);
		printf("%d ", ret);
	}
	return 0;
}