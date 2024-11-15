#include <cstdio>
#include <iostream>

void dfs(int pos, int n, int *arr, bool *vis) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            printf("%5d", arr[i]);
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            arr[pos] = i + 1;
            dfs(pos + 1, n, arr, vis);
            vis[i] = false;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    bool vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }
    dfs(0, n, arr, vis);
    return 0;
}