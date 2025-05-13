//
// Created by deniz on 5/13/2025.
//

#ifndef KNAPSACKBACKTRACK_H
#define KNAPSACKBACKTRACK_H
#include <vector>


void backtrack(const std::vector<int> &weights, const std::vector<int> &values, int capacity,
               int index, int currentWeight, int currentValue, std::vector<int> &currentSolution, int &maxValue, int& minWeight,
               std::vector<int> &bestSolution);


#endif //KNAPSACKBACKTRACK_H
