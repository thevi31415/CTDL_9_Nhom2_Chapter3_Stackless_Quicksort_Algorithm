#include <iostream>
using namespace std;
struct Record {
    char value;
    int key;
};
void xuat(Record R[], int N) {
    for (int i = 1; i <= N; i++) {
        cout << R[i].key << " ";
    }
}
void Lap(Record R[], int& L, int& I, int& J, Record& P) {
    do {
        J = J + 1;
    } while (P.key <= R[J].key);
    if (R[J].key > 0) {
        R[I] = R[J];
        I = I + 1;
        R[J] = R[I];
        Lap(R, L, I, J, P);
    }
}
void StacklessQuicksort(Record R[], int N) {
    int L, J, I;
    Record P;
    R[N + 1].key = -1;
    for (L = 1; L <= N; L++) {
        while (R[L].key > 0) {
            J = L; I = L; P = R[L];
            Lap(R, L, I, J, P);
            P.key = -P.key; R[I] = P;
        }
        R[L].key = -R[L].key;
    }
}
int main()
{
    Record A[10000];
    int N;
    cout << "Nhap so phan tu cua mang: "; cin >> N;
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 1; i <= N; i++) {
        cin >> A[i].key;
    }
    StacklessQuicksort(A, N);
    xuat(A, N);

}

