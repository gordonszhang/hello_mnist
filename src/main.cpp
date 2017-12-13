#include <iostream>

/*
 * At this point in time, this is just a playground file where I goof around and see what works
 */
int main() {
    float *list;
    list = new float[10];
    for (int i = 0; i < 10; ++i) {
        list[i] = float(rand()%200-100)/100.0;
    }
    for (int j = 0; j < 10; ++j) {
        std::cout << list[j] << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}