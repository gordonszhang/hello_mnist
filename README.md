# Hello MNIST
A basic implementation of an artificial neural network in C++ that performs basic OCR, 
inspired by this wonderful [YouTube series created by 3Blue1Brown](http://3b1b.co/neural-networks)
and Michael Neilsen's _[Neural Networks and Deep Learning](http://neuralnetworksanddeeplearning.com/)_. 
The code can be found [here](https://github.com/mnielsen/neural-networks-and-deep-learning).

## So... What does the code do?
The neural network trains on about 60,000 labelled hand-drawn characters from a NIST dataset (hence
the name). You can then feed it a new hand labelled character in hopefully it will properly identify it.

## Why would anyone care about _this_ repo? 
The main reasons I bothered to code this are:
* To get more comfy with C++ and CMake. 
* To have a convenient codebase I can use for learning more C++ stuff
* To have a starting point for learning to implement CUDA kernels. 
* To gather my own experimental data on how NN architecture, training algorithms, and other hyperparameters affect the 
performance of the neural net on the MNIST dataset. 

For people breaking into the ML/Deep Learning scene with a strong C++ background, this could be a nice aid to 
Neilsen's Python code. 

On top of that, this neural network could easily be re-purposed for another dataset or to solve another problem. If 
you really like my code for whatever reason, you could also hypothetically use this as the basis for building some more 
state-of-the-art stuff. 