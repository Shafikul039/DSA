void countsort(vector<int>& a) {
    int n = a.size();
    int mx = *max_element(a.begin(), a.end());
    vector<int> cnt(mx + 1, 0);
    for (int x : a) cnt[x]++;
    a.clear();
    for (int i = 0; i <= mx; i++) {
        while (cnt[i]--) a.push_back(i);
    }
}
