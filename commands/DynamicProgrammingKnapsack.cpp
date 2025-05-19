//
// Created by deniz on 5/19/2025.
//

#include "DynamicProgrammingKnapsack.h"

#include <chrono>

#include "../data_structures//TruckProblemInstance.h"
#include  "../algorithms//DPKnapsack.h"

void DynamicProgrammingKnapsack::execute(Context *context, std::vector<std::string> args) {
    try {
        const auto instance = context->get<TruckProblemInstance *>("instance");

        vector<int> weights = (*instance)->getWeights();
        vector<int> values = (*instance)->getProfits();
        int capacity = (*instance)->getCapacity();

        vector<int> selectedItems;
        int bestValue = 0;
        auto start = std::chrono::high_resolution_clock::now();
        dpKnapsack(capacity, weights, values, bestValue, selectedItems);
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        cout << "Max value: " << bestValue << endl;
        cout << "Selected items: ";
        for (auto item: selectedItems) {
            cout << item << " ";
        }
        cout << endl;
        std::cout << "[INFO] Command executed in " << duration.count() << " ms\n";
    } catch (...) {
        cout << "Error getting registry from context." << endl;
    }
}
