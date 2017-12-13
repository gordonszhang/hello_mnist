//
// Created by Derek Rodriguez on 12/12/2017.
//
#include <random>
#include "hellonet.h"

HelloNet::HelloNet(int layer_count, int *layer_array): num_layers(layer_count), layerData(layer_array) {
    //instantiate weight tables
    for (int layer = 1; layer < num_layers; ++layer) {
        weights[layer] = new float*[layer_array[layer]]; //input layer doesn't need weights so skip layer 0
        for (int destination =0; destination < layer_array[layer]; ++destination){
            weights[layer][destination] = new float[layer_array[layer-1]];
            for (int source = 0; source < layer_array[layer-1]; ++source){
                //every individual weight starts at a random value
                weights[layer][destination][source] = float(float(random() % 200 - 100) / 100.0);
            }
        }
    }

    //instantiate bias vectors for each layer
    for (int layer = 0; layer < num_layers; ++layer) {
        biases[layer] = new float[layer_array[layer]];
        for(int i =0; i < layer_array[layer]; ++i){
            biases[layer][i] = float(float(random()%200-100)/100.0);
        }
    }

}

HelloNet::~HelloNet() {
    //clean up everything in one giant wonderful pass
    for (int i = 0; i < num_layers; ++i) {

    }

}

float HelloNet::forwardProp(float *input_vector, int size) {

}

float HelloNet::verboseFProp(float *input_vector, int size) {
    return 0;
}

float HelloNet::backProp(float *training_input) {
    return 0;
}

int HelloNet::verboseBProp(float *training_input) {
    return 0;
}

float HelloNet::activate(float h) {
    return 0;
}

float HelloNet::actPrime(float h) {
    return 0;
}

void HelloNet::gradientDescent(int epochs, float learn_rate, float **training_data) {

}
