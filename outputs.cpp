#include <bits/stdc++.h>
using namespace std;
template <typename b,typename a>
ostream& operator << (ostream& o, pair<a,b> p) {
  o << "(" << p.first << "," << p.second << ")";
  return o;
}

template <typename T>
ostream& operator << (ostream& o, vector<T> v) {
  o << "[";
  for (auto a : v) {
    o << a << ",";
  }
  o << "]";
  return o;
}

template <typename T>
ostream& operator << (ostream& o, set<T> v) {
  o << "{";
  for (auto a : v) {
    o << a << ",";
  }
  o << "}";
  return o;
}

ostream& operator << (ostream& o, bool b) {
  if (b == true)
    o << "true";
  else
    o << "false";
  return o;
}

template <typename T>
ostream& operator << (ostream& o, multiset<T> v) {
   o << "{";
   for (auto it = v.begin();it != v.end();it++) {
     o << *it << ",";
  }
  o << "}";
  return o;
}


template <typename T,typename U>
ostream& operator << (ostream& o, unordered_map<T,U> m) {
  o << "{";
  for (auto it = m.begin();it != m.end();it++) {
     o << *it << ",";
  }
  o << "}";
  return o;
}


template <typename T,typename U>
ostream& operator << (ostream& o, map<T,U> m) {
  o << "{";
  for (auto it = m.begin();it != m.end();it++) {
     o << *it << ",";
  }
  o << "}";
  return o;
}
