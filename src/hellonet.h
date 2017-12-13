//
// Created by Derek Rodriguez on 12/12/2017.
//


#ifndef HELLO_MNIST_HELLONET_H
#define HELLO_MNIST_HELLONET_H
#endif HELLO_MNIST_HELLONET_H


class HelloNet{
private:
    //array of weight matrices, one for for each layer
    float ***weights;

    //array of bias vectors
    float **biases;

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

    //recursively compute output of neural network
    float forwardProp(float *input_vector, int size);

    //forwardProp with verbose prints
    float verboseFProp(float *input_vector, int size);

    //perform back propagation algorithm on a single training sample
    float backProp(float *training_input);

    //backProp with verbose printing
    int verboseBProp(float *training_input);

    //activation function applied to hypothesis h
    float activate(float h);

    //derivative of activation function
    float actPrime(float h);

    //train the NN using gradient descent
    void gradientDescent(int epochs, float learn_rate, float **training_data);

    virtual ~HelloNet();

};
