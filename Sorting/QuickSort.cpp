int part(vector<int>& a, int left, int right) {
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] < a[right]) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}

void quicksort(vector<int>& a, int left, int right) {
    if (left < right) {
        int pivot = part(a, left, right);
        quicksort(a, left, pivot - 1);
        quicksort(a, pivot + 1, right);
    }
}
