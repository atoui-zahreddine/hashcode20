
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
        ifstream inDataSet(fileInput,ios::out);
        if(!inDataSet){
            cout<<"unable to open the file !!"<<endl;
        }{
            inDataSet>>nbrBooks;
            inDataSet>>nbrLibrary;
            inDataSet>>nbrDays;
            for(int i=0;i<nbrBooks;i++){
                int x;
                inDataSet>>x;
                books.push_back(x);
            }
            for (int i=0;i<nbrLibrary;i++){
                int lnbrBook,ldaysSignUp,shipPerDay;
                inDataSet>>lnbrBook;
                inDataSet>>ldaysSignUp;
                inDataSet>>shipPerDay;
                vector<int>lbooks;
                for(int j=0;j<lnbrBook;j++){
                    int x;
                    inDataSet>>x;
                    lbooks.push_back(x);
                }
                Library library(lnbrBook,ldaysSignUp,shipPerDay,lbooks);
                librarys.push_back(library);
            }
            inDataSet.close();
        }

    }

    friend ostream &operator<<(ostream &os, const Input &input) {
        os << "nbrBooks: " << input.nbrBooks << " nbrLibrary: " << input.nbrLibrary << " nbrDays: " << input.nbrDays<<endl;
        for(int i=0;i<input.librarys.size(); i++){
            os<<input.librarys[i];
        }
        return os;
    }
};

int main() {
    Input input("a_example.txt","submition.txt");
    cout<<input;
    return 0;
}
