#include <iostream>
#include <vector>

using namespace std;

class OrderedStream {
private:
  int ptr = 1;
  vector<string> data;
public:
  OrderedStream(int n): data(n+1) {}

  vector<string> insert(int id, string value) {
    vector<string> result;
    data[id] = value;
    if (ptr == id) {
      while(ptr < data.size() && !data[ptr].empty()) {
        result.push_back(data[ptr++]);
      }
    }
    return result;
  }
};