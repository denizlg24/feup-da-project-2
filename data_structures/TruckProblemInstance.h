//
// Created by deniz on 5/9/2025.
//

#ifndef TRUCKPROBLEMINSTANCE_H
#define TRUCKPROBLEMINSTANCE_H


#include <vector>

struct Pallet {
    int id;
    int weight;
    int profit;
};

class TruckProblemInstance {
private:
    int capacity;
    int numPallets;
    std::vector<Pallet> pallets;

public:
    TruckProblemInstance(int cap, int n) : capacity(cap), numPallets(n) {
    }

    void setCapacity(int cap) { capacity = cap; }
    void setNumPallets(int n) { numPallets = n; }

    void addPallet(const Pallet &pallet) {
        pallets.push_back(pallet);
    }

    int getCapacity() const { return capacity; }
    int getNumPallets() const { return numPallets; }
    const std::vector<Pallet> &getPallets() const { return pallets; }

    std::vector<int> getWeights() const {
        std::vector<int> weights;
        for (const auto &pallet: pallets) {
            weights.push_back(pallet.weight);
        }
        return weights;
    }

    std::vector<int> getProfits() const {
        std::vector<int> profits;
        for (const auto &pallet: pallets) {
            profits.push_back(pallet.profit);
        }
        return profits;
    }
};


#endif //TRUCKPROBLEMINSTANCE_H
