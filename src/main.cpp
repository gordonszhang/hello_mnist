#include "hellonet.h"
/*
 * At this point in time, this is just a playground file where I goof around and see what works
 */

int runHelloNetTests() {
    //constructor test
    std::cout << "Creating NN with spec: [4,3,2]" << std::endl;
    unsigned long config[3]= {4, 3, 2};
    auto *test = new HelloNet(3, config);
    std::cout << "Here are weight tables:" << std::endl;
    test->dumpWeightTables();


    //forward propagation test
    std::cout << "testing network with data = < 1.00000, 1.00000, 1.00000, 1.00000>" << std::endl;
    std::vector<float> testData = {1.0f, 1.0f, 1.0f, 1.0f};
    test->parse(testData);
    std::string fPropOutput = "<";
    for (auto &&result : testData) fPropOutput += std::to_string(result) + ", ";
    fPropOutput += ">";
    std::cout << "RESULT:\t" + fPropOutput << std::endl;

}

int main() {
    runHelloNetTests();
}