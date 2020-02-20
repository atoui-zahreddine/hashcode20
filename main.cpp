
#include <iostream>
#include <vector>
#include "Library.h"
#include <fstream>
#include <string>

using namespace std;

class Input{
private:
    int nbrBooks,nbrLibrary,nbrDays;
    vector<int> books;
    vector<Library> librarys;
    string fileInput;
    string fileOutput;
public:
    Input(const string &fileInput, const string &fileOutput) : fileInput(fileInput), fileOutput(fileOutput) {
        ifstream inDataSet(fileInput);
        if(!inDataSet){
            cout<<"unable to open the file !!"<<endl;
        }{
            inDataSet>>nbrBooks;
            inDataSet>>nbrLibrary;
            inDataSet>>nbrDays;
            for(int i=0;i<nbrBooks;i++){
                inDataSet>>books[i];
            }
            for (int i=0;i<nbrLibrary;i++){
                int lnbrBook,ldaysSignUp,shipPerDay;
                inDataSet>>lnbrBook;
                inDataSet>>ldaysSignUp;
                inDataSet>>shipPerDay;
                vector<int>lbooks;
                for(int j=0;i<lnbrBook;i++){
                    inDataSet>>lbooks[i];
                }
                Library library(lnbrBook,ldaysSignUp,shipPerDay,lbooks);
                librarys.push_back(library);
            }
            inDataSet.close();
        }

    }
};

int main() {

    Input input("a_example.txt","submition.txt");
    return 0;
}
