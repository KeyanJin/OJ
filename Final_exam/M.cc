// #include <algorithm>
// #include <iostream>

// int ward[] = {1, -1};
// int n;
// int X;
// bool arr[10000] = {0};
// bool arr2[10000] = {0};
// int ans = 10000;
// void func(int pos, int flag)
// {
//     if (pos == n)
//     {
//         int max_i;
//         for (int i = 10000 - 1; i >= 0; i--)
//         {
//             if (arr2[i] == true)
//             {
//                 max_i = i;
//                 break;
//             }
//         }
//         int min_i;
//         for (int i = 0; i < 10000; i++)
//         {
//             if (arr2[i] == true)
//             {
//                 min_i = i;
//                 break;
//             }
//         }
//         ans = std::min(ans, max_i - min_i);
//         return;
//     }
//     for (int i = flag; i < 10000; i++)
//     {
//         if (arr[i] == true)
//         {
//             for (int j = 0; j < 2; j++)
//             {
//                 int x_ = i + X * ward[j];
//                 arr2[x_] = true;
//                 func(pos + 1, i);
//                 arr2[x_] = false;
//             }
//         }
//     }
// }
// int main()
// {
//     std::cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int index = 0;
//         std::cin >> index;
//         arr[index] = true;
//     }
//     std::cin >> X;
//     func(0, 0);
//     std::cout << ans << std::endl;
//     return 0;
// }
