//
// Created by deniz on 5/13/2025.
//

#include "KnapsackBacktrack.h"

void backtrack(const std::vector<int> &weights, const std::vector<int> &values, int capacity,
               int index, int currentWeight, int currentValue, std::vector<int> &currentSolution, int &maxValue,
               int &minWeight,
               std::vector<int> &bestSolution) {
    int n = weights.size();


    //UN-TIE
    //Among solutions with the same value, prefer the one that uses less weight.
    //Rationale: Leaves more capacity unused → more efficient use of the truck, more room for other cargo.
    if (index == n) {
        if (currentWeight <= capacity) {
            if (currentValue > maxValue) {
                maxValue = currentValue;
                minWeight = currentWeight;
                bestSolution = currentSolution;
            } else if (currentValue == maxValue && currentWeight < minWeight) {
                minWeight = currentWeight;
                bestSolution = currentSolution;
            }
        }
        return;
    }

    currentSolution[index] = 0;
    backtrack(weights, values, capacity, index + 1, currentWeight, currentValue, currentSolution, maxValue, minWeight,
              bestSolution);


    if (currentWeight + weights[index] <= capacity) {
        currentSolution[index] = 1;
        backtrack(weights, values, capacity, index + 1,
                  currentWeight + weights[index],
                  currentValue + values[index],
                  currentSolution, maxValue, minWeight, bestSolution);
    }
}
