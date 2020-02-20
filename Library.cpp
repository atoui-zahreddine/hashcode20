//
// Created by Zahreddine on 20/02/2020.
//

#include <fstream>
#include "Library.h"

Library::Library(int nbrBook, int daysSignUp,
        int shipPerDay,
        const vector<int> &books)
        : nbrBook(nbrBook),
        daysSignUp(daysSignUp),
        shipPerDay(shipPerDay),
        books(books) {

}

ostream &operator<<(ostream &os, const Library &library) {
    os << "nbrBook: " << library.nbrBook << " daysSignUp: " << library.daysSignUp << " shipPerDay: "
       << library.shipPerDay<<endl;
    for(int i=0;i<library.books.size();i++){
        os<<library.books[i]<<" ";
    }
    ofstream output("output.txt");
    os<<endl;
    return os;
}
