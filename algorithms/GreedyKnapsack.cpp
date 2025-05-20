//
// Created by deniz on 5/19/2025.
//

#include "GreedyKnapsack.h"

#include <algorithm>
#include <iostream>

void greedyKnapsack(int capacity,
                    const std::vector<int> &weights,
                    const std::vector<int> &values,
                    int &totalValue,
                    std::vector<int> &selectedItems) {
    int n = weights.size();
    totalValue = 0;

    std::vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;

    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        double ratioA = static_cast<double>(values[a]) / weights[a];
        double ratioB = static_cast<double>(values[b]) / weights[b];
        return ratioA > ratioB;
    });

    int currentWeight = 0;
    for (int i: indices) {
        if (currentWeight + weights[i] <= capacity) {
            selectedItems.push_back(i+1);
            currentWeight += weights[i];
            totalValue += values[i];
        }
    }
}
