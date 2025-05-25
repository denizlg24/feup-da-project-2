//
// Created by deniz on 5/9/2025.
//

#ifndef TRUCKPROBLEMINSTANCE_H
#define TRUCKPROBLEMINSTANCE_H


#include <vector>
/**
 * @struct Pallet
 * @brief Represents a single pallet with an identifier, weight, and profit.
 */
struct Pallet {
    int id;
    int weight;
    int profit;
};

/**
 * @class TruckProblemInstance
 * @brief Encapsulates a truck loading problem instance with pallets, capacity, and related data.
 *
 * This class manages the data related to a truck loading optimization problem,
 * including the truck's capacity, the number of pallets, and the pallets themselves.
 * It provides methods to add pallets, set/get the capacity and number of pallets,
 * and retrieve vectors of weights and profits for use in optimization algorithms.
 */
class TruckProblemInstance {
private:
    int capacity;
    int numPallets;
    std::vector<Pallet> pallets;

public:
    /**
   * @brief Constructs a new TruckProblemInstance with specified capacity and number of pallets.
   * @param cap The truck's maximum capacity.
   * @param n The number of pallets.
   */
    TruckProblemInstance(int cap, int n) : capacity(cap), numPallets(n) {
    }

    /**
       * @brief Sets the truck capacity.
       * @param cap New capacity value.
       */
    void setCapacity(int cap) { capacity = cap; }
    /**
     * @brief Sets the number of pallets.
     * @param n New number of pallets.
     */
    void setNumPallets(int n) { numPallets = n; }
    /**
        * @brief Adds a pallet to the instance.
        * @param pallet The pallet to add.
        */
    void addPallet(const Pallet &pallet) {
        pallets.push_back(pallet);
    }

    /**
        * @brief Returns the truck's capacity.
        * @return The current capacity.
        */
    int getCapacity() const { return capacity; }
    /**
    * @brief Returns the number of pallets.
    * @return The number of pallets.
    */
    int getNumPallets() const { return numPallets; }
    /**
     * @brief Returns a constant reference to the vector of pallets.
     * @return The vector of pallets.
     */
    const std::vector<Pallet> &getPallets() const { return pallets; }
    /**
         * @brief Retrieves the weights of all pallets as a vector.
         * @return A vector containing the weights of each pallet.
         */
    std::vector<int> getWeights() const {
        std::vector<int> weights;
        for (const auto &pallet: pallets) {
            weights.push_back(pallet.weight);
        }
        return weights;
    }

    /**
         * @brief Retrieves the profits of all pallets as a vector.
         * @return A vector containing the profits of each pallet.
         */
    std::vector<int> getProfits() const {
        std::vector<int> profits;
        for (const auto &pallet: pallets) {
            profits.push_back(pallet.profit);
        }
        return profits;
    }
};


#endif //TRUCKPROBLEMINSTANCE_H
