#include "hellonet.h"
/*
 * At this point in time, this is just a playground file where I goof around and see what works
 * Created by Derek Rodriguez on 12/10/2017
 * Last edited by:
 */

int runHelloNetTests() {
    //constructor test
    std::cout << "Creating NN with spec: [4,3,2]" << std::endl;
    unsigned long config[3]= {4, 3, 2}; //four nodes in the input layer, three in the hidden layer, and two in the output
    auto *test = new HelloNet(3, config);
    std::cout << "Here are weight tables:" << std::endl;
    test->dumpWeightTables(); //dump weight matrix for debugging


    //forward propagation test
    std::cout << "testing network with data = < 1.00000, 1.00000, 1.00000, 1.00000>" << std::endl;
    std::vector<float> testData = {1.0f, 1.0f, 1.0f, 1.0f}; //dummy test data, should come out garbage until trained
    test->parse(testData);
    std::string fPropOutput = "<";
    for (auto &&result : testData) fPropOutput += std::to_string(result) + ", "; //concatenate output to line
    fPropOutput += ">";
    std::cout << "RESULT:\t" + fPropOutput << std::endl;

}

int main() {
    runHelloNetTests();
}