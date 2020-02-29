// Sort.cpp
#include "Sort.h"
#include <iostream>

using namespace std;
Sort::Sort() {
  cout << "Sort Allocate" << endl;
}

Sort::~Sort() {
  cout << "Sort Destroy" << endl;
}

SelectionSort::SelectionSort() {
  cout << "SelectionSort Allocate" << endl;
}

SelectionSort::~SelectionSort() {
  cout << "SelectionSort Destroy" << endl;
}

void SelectionSort::description() {
  cout << "This is an algorithm class for Selection Sort." << endl;
}

