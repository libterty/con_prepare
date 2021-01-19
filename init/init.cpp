#include <iostream>

using namespace std;
typedef long long unsigned int ll;
int main() 
{
  ll i, j, k, t, ip;
  cin>>t;
  while (t--)
  {
    /* code */
    string s, s2;
    ll c0 = 0;
    for(i = 0; i < s.size(); i++) 
    {
      if(s[i] == '0') c0++;
    }
    if(min(c0, (s.length() - c0)) % 2 == 0)
    {
      cout << "Hello\n";
    }
    else
    {
      cout << "World\n";
    }
  }
  return 0;
}