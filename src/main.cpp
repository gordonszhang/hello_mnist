#include "hellonet.h"
#include <thread>
#include "mnist_parser.h"
/*
 * At this point in time, this is just a playground file where I goof around and see what works
 * Created by Derek Rodriguez on 12/10/2017
 * Last edited by:
 */

void generateToyDataset(std::vector<std::vector<double>> &data, std::vector<std::vector<double>> &labels){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0); //feel free to change distribution and range



    for (auto &&datum : data) { //generate vectors
        for (int i = 0; i < data.size(); ++i) {
            datum[i] = dist(mt);
        }
    }

    for (int j = 0; j < data.size(); ++j) { //for every vector, if magnitude is longer than 1, label is 1
        int sqSum = 0;
        for (auto &&component : data[j]) { //I'm sorry everything is @!#%? dynamic
            sqSum += component*component;
        }
        labels[j][0] = sqSum > 1 ? 1 : 0; //no need for sqrt because 1^2 == 1
    }

}

void runHelloNetTests(int trainingSetSize) { //train simple neural net to separate unit vectors from non-unit vectors
    //construct network
    std::cout << "Creating NN with spec: [2,2,1]" << std::endl;
    std::vector<unsigned long> config = {2, 2, 1}; //two inputs, two hidden, and one output
    auto *test = new HelloNet(config, 0.5, 0);
    std::cout << "Here are the weight tables:" << std::endl;
    test->dumpWeightTables(); //dump weight matrix for debugging


    //forward propagation test
    std::cout << "propagating through = < 1, 1 >" << std::endl;
    std::vector<double> sample = {1, 1}; //dummy data
    test->parse(sample);
    std::string fPropOutput = "<";
    for (auto &&result : sample) fPropOutput += std::to_string(result) + ", "; //concatenate output to line
    fPropOutput += ">";
    std::cout << "RESULT:\t" + fPropOutput << std::endl; // as long as it's not zero we're good.

    //now time to generate training data and labels for testing backprop
    //first instantiate/allocate containers and threads
    std::cout << "buidling training set" << std::endl;
    unsigned long numCores = std::thread::hardware_concurrency(); //get ideal number of threads for program
    unsigned long loadPerThread = trainingSetSize / numCores; //calculate load per thread
    std::vector<std::thread> threadPool;
    std::vector<std::vector<std::vector<double>>> perThreadDataPointContainers, perThreadLabelContainers;

    //allocate containers for each thread
    threadPool.resize(numCores);
    perThreadDataPointContainers.resize(numCores);
    perThreadLabelContainers.resize(numCores);
    for (int i = 0; i < numCores; ++i) {
        perThreadDataPointContainers[i].resize(loadPerThread);
        perThreadLabelContainers[i].resize(loadPerThread);
        for (auto &&dataPoint : perThreadDataPointContainers[i]) {
            dataPoint.resize(config[0]); //individual data points are the size of input layer
        }
        for (auto &&label : perThreadLabelContainers[i]) {
            label.resize(config.back()); //labels are size of output layer
        }
    }
    std::cout << "sizes:\t" << threadPool.size() << '\t' //DEBUG
              << perThreadDataPointContainers.size() << '\t'
              << perThreadLabelContainers.size() << std::endl;

    for (int j = 0; j < numCores; ++j) {
        threadPool[j] = std::thread(generateToyDataset, std::ref(perThreadDataPointContainers[j]), std::ref(perThreadLabelContainers[j]));
    }




}

int main(int argc, char** argv) {
    runHelloNetTests(atoi(argv[1]));
}