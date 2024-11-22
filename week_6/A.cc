#include <iostream>

const int N = 14;
bool line[N];
bool diagonal[2 * N - 1];
bool diagonal2[2 * N - 1];
int ans[N];
int n;
int count = 0;

void dfs(int row) {
  if (row == n) 
  {
    count++;
    if(count > 3)
    {
        return;
    }
    for (int i = 0; i < n; i++) 
    {
      std::cout << ans[i]<< " ";
    }
    std::cout << std::endl;
    return;
  }
  for (int i = 0; i < n; i++) 
  {
    if (line[i] == false && diagonal[row + i] == false && diagonal2[-row + i + n - 1] == false) 
    {
      line[i] = diagonal[row + i] = diagonal2[-row + i + n - 1] = true;
      ans[row] = i + 1;
      dfs(row + 1);
      line[i] = diagonal[row + i] = diagonal2[-row + i + n - 1] = false;
    }
  }
}

int main() {
  std::cin >> n;
  dfs(0);
  std::cout << count << std::endl;
  return 0;
}