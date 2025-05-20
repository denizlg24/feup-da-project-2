//
// Created by deniz on 5/19/2025.
//

#include "DPKnapsack.h"

void dpKnapsack(int capacity, const std::vector<int> &weights, const std::vector<int> &values,
                            int &bestValue, std::vector<int> &selectedItems) {
    int itemCount = weights.size();
    std::vector<std::vector<int> > dp(itemCount + 1, std::vector<int>(capacity + 1));

    for (int i = 1; i <= itemCount; ++i) {
        int curWeight = weights[i - 1], curValue = values[i - 1];
        for (int cap = 1; cap <= capacity; ++cap) {
            dp[i][cap] = dp[i - 1][cap];
            if (cap >= curWeight && dp[i - 1][cap - curWeight] + curValue > dp[i][cap]) {
                dp[i][cap] = dp[i - 1][cap - curWeight] + curValue;
            }
        }
    }

    int cap = capacity;
    for (int i = itemCount; i > 0; --i) {
        if (dp[i][cap] != dp[i - 1][cap]) {
            int idx = i - 1;
            selectedItems.push_back(idx+1);
            cap -= weights[idx];
        }
    }

    bestValue = dp[itemCount][capacity];
}
