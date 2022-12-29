#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
void Lap(int A[5001], int& L, int& I, int& J, int P) {
	do {
		J = J + 1;
	} while (P <= A[J]);
	if (A[J] > 0) {
		A[I] = A[J];
		I = I + 1;
		A[J] = A[I];
		Lap(A, L, I, J, P);
	}
}
void StacklessQuicksort(int A[5001], int N) {
	int L, J, I;
	int P;
	A[N + 1] = -1;
	for (L = 1; L <= N; L++) {
		while (A[L] > 0) {
			J = L; I = L; P = A[L];
			Lap(A, L, I, J, P);
			P = -P; A[I] = P;
		}
		A[L] = -A[L];
	}
}
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[5001];
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		StacklessQuicksort(arr, n);
		int x;
		int y = INT_MAX;
		for (int i = 1; i <= n - 1; i++)
		{
			int x = arr[i + 1] - arr[i];
			y = min(y, x);
		}
		cout << y << endl;
	}
	return 0;
}
