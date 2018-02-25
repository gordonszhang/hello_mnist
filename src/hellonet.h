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
    std::vector<std::vector<std::vector<double>>>  weights;

    //array of bias vectors
    std::vector<std::vector<double>> biases;

    //the number of layers in the neural net
    unsigned long num_layers;

    //the amount of neurons in each layer in array form
    unsigned long  *layerData;
public:
    /*
     * HelloNet takes a list of ints, each int being the count of neurons in each layer
     * arg_count: amount of layers i.e. amount of ints in array
     * arg_list: array of ints
     */
    explicit HelloNet(std::vector<unsigned long> layer_config);

    HelloNet(std::vector<unsigned long> layer_config, double fixed_weight, double fixed_bias);

    //print the weight tables to stdout
    void dumpWeightTables();

    //activation function applied to hypothesis h
    double activate(double h);

    //derivative of activation function
    double actPrime(double h);

    //classify input data and return result into the same variable passed in
    void parse(std::vector<double> &data);

    //perform back propagation algorithm on a single training sample
    void backProp(std::vector<double> &trainingLabel, std::vector<double> &trainingData, std::vector<std::vector<double>> &nabla_b, std::vector<std::vector<double>> &nabla_w);

    //get the "change factor", by performing a piecewise subtraction between two vectors and gets loaded into output á la C-style
    void costDerivative(std::vector<double> &expectedValues, std::vector<double> &currentValues, std::vector<double> &output);

    //train the NN using stochastic gradient descent
    void sgd(int epochs, double learn_rate, std::vector<std::vector<double>> training_data);


};
