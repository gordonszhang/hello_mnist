//
// Created by Derek Rodriguez on 12/12/2017.
//
#include <random>
#include "hellonet.h"

HelloNet::HelloNet(int layer_count, int *layer_array): num_layers(layer_count), layerData(layer_array) {
    //instantiate weight tables
    weights = new float**[num_layers];
    for (int layer = 0; layer < num_layers-1; ++layer) {  //a table for every layer
        weights[layer] = new float*[layer_array[layer+1]]; //input layer doesn't need weights so skip layer 0
        for (int destination =0; destination < layer_array[layer]; ++destination){  //a row for every neuron in that row
            //ternary operator is to handle input layer
            weights[layer][destination] = new float[layer_array[(layer != 0 ? layer - 1 : 1)]];
            for (int source = 0; source < layer_array[layer]; ++source){ //each entry is the weight of the incoming signal
                weights[layer][destination][source] = layer != 0 ? float(float(random() % 200 - 100) / 100.0) : 1.0F;
            }
        }
    }

    //instantiate bias vectors for each layer
    biases = new float*[num_layers-1];
    for (int layer = 0; layer < num_layers-1; ++layer) {
        biases[layer] = new float[layer_array[layer+1]];  //input layer doesn't have any biases
        for(int i =0; i < layer_array[layer]; ++i){
            biases[layer][i] = float(float(random()%200-100)/100.0);
        }
    }

}

HelloNet::~HelloNet() {
}

float HelloNet::forwardProp(float *input_vector, int size) {
    return 0;
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
    return 1/(1+exp(-h));
}

float HelloNet::actPrime(float h) {
    return activate(h)*(1-activate(h));
}

void HelloNet::gradientDescent(int epochs, float learn_rate, float **training_data) {

}
