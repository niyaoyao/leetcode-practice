// Sort.h
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
class Sort
{
public:
  Sort();
  ~Sort();

  void description() {
    cout << "Sort Base Class" << endl;
  }

  static void sort(std::vector<double> &v) {
    time_t start = time(0);
    cout << "Sort Begin: " << start << endl;



    time_t end = time(0);
    cout << "Sort End: " << end << "\nDuration: " << end - start << endl;

  }

  static bool isSorted(std::vector<double> &v) {
    for (int i = 0; i < v.size(); ++i)
    {
      if (Sort::less(v.at(i), v.at(i - 1)))
      {
        return false;
      }
    }

    return true;
  }

protected:
  static bool less(double x, double y) {
    return x < y;
  }

  static void exchange(std::vector<double> &v, int i, int j) {
    double temp = v.at(i);
    v.at(i) = v.at(j);
    v.at(j) = temp;
  }

  static void show(std::vector<double> &v) {
    cout << "Array: " << endl;
    for (std::vector<double>::iterator i = v.begin(); i != v.end(); ++i)
    {
      cout << *i << "\t";
    }
    cout << "" << endl;
  }

};


class SelectionSort:public Sort
{
public:
  SelectionSort();
  ~SelectionSort();
  void description();
  static void sort(std::vector<double> &v) {
    time_t start = time(0);
    show(v);
    cout << "Sort Begin: " << start << endl;

    int size = v.size();
    for (int i = 0; i < size; ++i)
    {
      int min = i;
      for (int j = i+1; j < size; ++j)
      {
        if (less(v.at(j), v.at(min)))
        {
          min = j;
        }
      }
      exchange(v, i, min);
    }

    time_t end = time(0);
    cout << "Sort End: " << end << "\nDuration: " << end - start << endl;
    show(v);
  }
};