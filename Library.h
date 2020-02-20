//
// Created by Zahreddine on 20/02/2020.
//

#ifndef HASHCODE_LIBRARY_H
#define HASHCODE_LIBRARY_H

#include <iostream>
#include <vector>
using namespace std;
class Library {
public:
    Library(int nbrBook, int daysSignUp, int shipPerDay, const vector<int> &books);

    int nbrBook;
    int daysSignUp;
    int shipPerDay;
    vector<int> books;

    friend ostream &operator<<(ostream &os, const Library &library);

};


#endif //HASHCODE_LIBRARY_H
