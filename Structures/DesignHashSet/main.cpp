#include <iostream>

class MyHashSet {
public:
  // array of 100000 elements to store the keys

  bool arr[1000001];

  MyHashSet() {
    // initialize the array with false
    memset(arr, false, sizeof(arr));
  }

  void add(int key) {
    // set the key to true
    arr[key] = true;
  }

  void remove(int key) {
    // set the key to false
    arr[key] = false;
  }

  bool contains(int key) {
    // return the value of the key
    return arr[key];
  }
};
