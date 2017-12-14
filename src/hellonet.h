/*
 * Created by Derek Rodriguez on 12/12/2017
 * The constructor for the Neural Network.
 */

#ifndef HELLO_MNIST_HELLONET_H
#define HELLO_MNIST_HELLONET_H
#endif HELLO_MNIST_HELLONET_H
#include <cstdlib>
#include <random>
#include <vector>
#include <iostream>

class HelloNet{
private:
    //array of weighs
    std::vector<std::vector<std::vector<float>>>  weights;

    //array of bias vectors
    std::vector<std::vector<float>> biases;

    //the number of layers in the neural net
    int num_layers;

    //the amount of neurons in each layer in array form
    int  *layerData;
public:
    /*
     * HelloNet takes a list of ints, each int being the count of neurons in each layer
     * arg_count: amount of layers i.e. amount of ints in array
     * arg_list: array of ints
     */
    HelloNet(int layer_count, int *layer_array);

    //print the weight tables to stdout
    void dumpWeightTables();

    //recursively compute output of neural network and write output back to data vector
    void forwardProp(std::vector<float> &data);

    //perform back propagation algorithm on a single training sample
    float backProp(float *training_input);

    //activation function applied to hypothesis h
    float activate(float h);

    //derivative of activation function
    float actPrime(float h);

    //train the NN using gradient descent
    void gradientDescent(int epochs, float learn_rate, float **training_data);


};
