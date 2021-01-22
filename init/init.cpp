#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef long long unsigned int ll;
typedef string str;

template<class T>
vector<T> write_vector(vector<T>& v, ll& temp, istringstream& ss) {
  while (ss >> temp)
    v.push_back(temp);
  return v;
}

int main() 
{
  string line;
  vector<ll> nums;
  ll temp;
  getline(cin, line);
  istringstream ss(line);

  nums = write_vector(nums, temp, ss);

  
  return 0;
}