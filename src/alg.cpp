// Copyright 2021 NNTU-CS
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"

BST<std::string> makeTree(const char* path) {
      BST<std::string> tree;
    std::ifstream file(path);
    if (!file) {
        std::cout << "can't read file" <<"\n";
        throw std::string("can't open file!");
    }
    std::string word = "";
    while (!file.eof()) {
        char IdontWantToDoIt = file.get();
        int sym = IdontWantToDoIt;
        if ((sym >= 65 && sym <= 90) || (sym >= 97 && sym <= 122)) {
            word += tolower(sym);
        } else { if (word != "") {
                tree.Add(word);
                word = "";
            }
        }
    }
    file.close();
    return tree;
}
