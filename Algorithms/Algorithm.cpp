// Algorithm.cpp
#include "Algorithm.h"
#include <iostream>

using namespace std;

Algorithm::Algorithm() {
	this->value = 0.0;
}

void Algorithm::setTest(double value) {
	this->value = value;
}

void Algorithm::printValue() {
	cout << "Test Value:" << this->value << endl;
}