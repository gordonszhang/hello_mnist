#include <iostream>
#include <vector>
/*
 * At this point in time, this is just a playground file where I goof around and see what works
 */
int main() {
    std::vector<std::vector<std::vector<int>>> weights;
    int layer_array[3] = {4,3,2};
    int num_layers = 3;
    weights.resize(num_layers-1); // one table per layer
    for (int i = 1; i < num_layers; ++i) {
        weights[i-1].resize(layer_array[i]); // one row per neuron in current row
        for (int j = 0; j < layer_array[i]; ++j) {
            weights[i-1][j].resize(layer_array[i-1]); // one entry in the row per input connection
        }
    }

    for (auto &&layer : weights) {
        for (auto &&destination : layer) {
            for (auto &&source : destination) {
                source = random() % 100;
            }
        }
    }

    std::string test = "";
    for (auto &&layer : weights) {
        test += "NEW TABLE\n";
        for (auto &&destination : layer) {
            for (auto &&source : destination) {
                test += std::to_string(source) + "\t";
            }
            test += "\n";
        }
        test += "\nXXXXX\n";
    }

    std::cout<<test<<std::endl;




}