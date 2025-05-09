//
// Created by deniz on 5/9/2025.
//

#include "CreateProblemInstance.h"

#include "../csv_parser/CSVParser.h"
#include "../data_structures/TruckProblemInstance.h"


void CreateProblemInstance::execute(Context *context, std::vector<std::string> args) {
    if (args.size() != 3) {
        if (args.size() == 2) {
            cout << "Correct usage --> create_problem <TruckAndPallets> <Pallets>, missing Pallets." << endl;
            return;
        }
        if (args.size() == 1) {
            cout << "Correct usage --> create_problem <TruckAndPallets> <Pallets>, missing TruckAndPallets and Pallets."
                    << endl;
        }
    } else {
        CSVParser parser;
        if (!parser.loadCSV(args[1])) {
            cout << "Failed to load truck data file." << endl;
            return;
        }

        const auto &rows = parser.getData();
        if (rows.empty() || rows[0].size() < 2) {
            cout << "Invalid truck data format." << endl;
            return;
        }

        int capacity = std::stoi(rows[0][0]);
        int numPallets = std::stoi(rows[0][1]);
        auto *instance = new TruckProblemInstance(capacity, numPallets);
        if (!parser.loadCSV(args[2])) {
            cout << "Failed to load pallets file." << endl;
            return;
        }

        const auto &pallets = parser.getData();
        for (const auto &pallet: pallets) {
            if (pallet.size() < 3) continue;

            int id = std::stoi(pallet[0]);
            int weight = std::stoi(pallet[1]);
            int profit = std::stoi(pallet[2]);

            instance->addPallet({id, weight, profit});
        }

        context->set("instance", instance);
        cout << "Successfully created a truck problem instance with " << instance->getNumPallets() <<
                " pallets and a capacity of " << instance->getCapacity() << "." << endl;
    }
}
