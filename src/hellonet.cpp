//
// Created by Derek Rodriguez on 12/12/2017.
//

#include "hellonet.h"

HelloNet::HelloNet(int layer_count, int *layer_array): num_layers(layer_count), layerData(layer_array) {
    //instantiate weight tables
    weights.resize(num_layers-1); // one table per layer
    for (int i = 1; i < num_layers; ++i) {
        weights[i-1].resize(layer_array[i]); // one row per neuron in current row
        for (int j = 0; j < layer_array[i]; ++j) {
            weights[i-1][j].resize(layer_array[i-1]); // one entry in the row per input connection
        }
    }

    //fill weight tables with randomness
    for (auto &&layer : weights) {
        for (auto &&destination : layer) {
            for (auto &&sourceWeight : destination) {
                sourceWeight = float(arc4random()%100-200)/100.0f;
            }
        }
    }

    //allocate space biases
    biases.resize(num_layers-1);
    for (int i = 1; i < num_layers; ++i) {
        biases[i-1].resize(layer_array[i]);
    }

    //fill bias vectors with randomness
    for (auto &&layer : biases) {
        for (auto &&neuron_bias : layer) {
            neuron_bias = float(arc4random()%100-200)/100.0f;
        }
    }
}

std::vector<float> HelloNet::forwardProp(std::vector<float> &inputs) {
    std::vector<float> activations; //activation
    for (int layer = 0; layer < weights.size(); ++layer) {  //for each layer, get table
        for (int neuron = 0; neuron < weights[layer].size(); ++neuron) { //for each table, get row of weights
            float h = biases[layer][neuron];  //hypothesis h = b + ∑wa
            for (int i = 0; i < weights[layer][neuron].size(); ++i) { //compute ∑wa and add to b
                h += weights[layer][neuron][i]*inputs[i];
            }
            activations.push_back(activate(h));
        }
        inputs = activations; //activations from current layer become inputs to next layer
        activations.clear(); //clean out activations
    }

    return inputs;
}



float HelloNet::backProp(float *training_input) {
    return 0;
}

float HelloNet::activate(float h) {
    return tanhf(h);
}

float HelloNet::actPrime(float h) {
    return 1/(coshf(h)*coshf(h));
}

void HelloNet::gradientDescent(int epochs, float learn_rate, float **training_data) {

}
