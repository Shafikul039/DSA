void merg(int left, int right, int mid) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];
    L[n1] = R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L[i] <= R[j]) a[k] = L[i++];
        else a[k] = R[j++];
    }
}

void mergesort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merg(left, right, mid);
}
