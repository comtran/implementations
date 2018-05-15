#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int

struct Trie {
  map<string, uint> records;

  void insert(string str) {
    uint n = str.size();
    string prefix = "";

    for (uint i = 0; i < n; i++) {
      prefix += str[i];
      if (this->records.find(prefix) == this->records.end())
        this->records[prefix] = 0;

      this->records[prefix]++;
    }
  }

  bool contains(string str) {
    return this->records.find(str) != this->records.end();
  }

  uint count(string str) {
    if (!this->contains(str)) return 0;

    return this->records[str];
  }
};

int main() {
  Trie trie;

  string contacts[] = {
    "wisnu", "pamungkas", "setyo", "danu", "vayu", "eko", "winda"
  };

  for (string contact : contacts) trie.insert(contact);

  string keywords[] = {
    "wisnu",
    "wi",
    "da",
    "pamungkaski",
    "yo"
  };

  for (string keyword : keywords) {
    cout << "How many contacts that contains starting keyword \"";
    cout << keyword << "\"? " << trie.count(keyword) << endl;
  }

  return 0;
}
