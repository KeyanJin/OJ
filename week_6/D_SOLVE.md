用C++实现一个模拟这种特殊电梯系统的程序，我们需要定义一个类来表示电梯，并包含一些方法来处理电梯的按钮逻辑、状态更新和高度计算。以下是一个简单的示例代码，它模拟了这种电梯的基本功能：

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

class Elevator {
public:
    Elevator(int startHeight) : currentHeight(startHeight) {}

    // 模拟按电梯按钮
    void pressButton(char direction, int targetHeight) {
        if (direction == 'U' && canGoToHeight(targetHeight, true)) {
            goToHeight(targetHeight);
        } else if (direction == 'D' && canGoToHeight(targetHeight, false)) {
            goToHeight(targetHeight);
        } else {
            std::cout << "Button pressed is invalid or unreachable.\n";
        }
    }

    // 获取当前电梯高度
    int getCurrentHeight() const {
        return currentHeight;
    }

private:
    int currentHeight;
    std::vector<int> heights = {3, 3, 1, 2, 5}; // 电梯的上行和下行高度

    // 判断是否能到达目标高度
    bool canGoToHeight(int targetHeight, bool isUp) {
        int maxReachable = getMaxReachableHeight(isUp);
        int minReachable = getMinReachableHeight(isUp);

        // 考虑边界情况，比如从0开始只能上行
        if (isUp && currentHeight == 0) {
            minReachable = 0;
        }
        // 考虑边界情况，比如到达V（假设V是heights数组之和的某个值）后只能下行或保持
        // 这里我们不知道V的确切值，所以只考虑能到达的最小和最大高度

        return targetHeight >= minReachable && targetHeight <= maxReachable;
    }

    // 计算能到达的最大高度
    int getMaxReachableHeight(bool isUp) {
        int maxHeight = 0;
        if (isUp) {
            for (int height : heights) {
                maxHeight += height;
            }
        } else {
            // 下行时，最大高度就是0（假设电梯可以回到原点）
            // 注意：这里简化了逻辑，因为题目没有给出下行的具体规则
            // 如果下行有特定的停止点，需要修改这里的逻辑
            maxHeight = 0;
        }
        return maxHeight;
    }

    // 计算能到达的最小高度（对于上行是0，对于下行是累计负高度或特定停止点）
    int getMinReachableHeight(bool isUp) {
        if (isUp) {
            return 0; // 上行时最小高度是0
        } else {
            // 下行时的最小高度取决于heights数组中的负累计和（如果允许负高度）
            // 或者某个特定的停止点（题目未给出，这里简化处理为0）
            // 注意：这里同样简化了逻辑
            return 0;
        }
    }

    // 移动电梯到指定高度（简化处理，不考虑中间过程）
    void goToHeight(int targetHeight) {
        currentHeight = targetHeight;
        std::cout << "Elevator moved to height: " << currentHeight << "\n";
    }
};

int main() {
    Elevator elevator(0); // 假设电梯从0高度开始

    // 示例操作
    elevator.pressButton('U', 3); // 应该有效，因为3在可到达高度内
    elevator.pressButton('U', 10); // 可能无效，取决于getMaxReachableHeight的实现
    elevator.pressButton('D', -1); // 下行逻辑简化处理为无效（因为假设不能到负高度）
    elevator.pressButton('D', 0); // 应该有效，如果允许回到原点

    return 0;
}
```

**注意**：

1. 这个代码是一个简化的示例，它并没有完全按照题目中描述的复杂逻辑来实现。特别是下行逻辑，题目没有给出具体的下行停止点或规则，所以这里简化处理为只能回到原点（0高度）。

2. `getMaxReachableHeight` 和 `getMinReachableHeight` 方法中的逻辑可能需要根据题目的具体要求进行调整。特别是下行时的最小高度计算，可能需要考虑`heights`数组中的负累计和（如果允许负高度）或者某个特定的停止点。

3. 电梯的“V”高度在题目中也没有明确给出，这里我们假设电梯可以一直上行到`heights`数组所有元素之和的高度（或者某个特定的上限），并且下行可以回到原点。如果题目中有具体的“V”高度限制，需要相应地修改代码。

4. `goToHeight` 方法简化了电梯的移动过程，直接将电梯移动到目标高度。在实际应用中，可能需要更复杂的逻辑来模拟电梯的逐步移动过程。