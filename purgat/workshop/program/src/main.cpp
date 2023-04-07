#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    string fname1 = "Jon";
    Client c(fname1, "Arbuckle", "0123456789", nullptr);
    fname1.assign("Doc Boy");
    cout << c.getFirstName() << endl;

    string fname2 = "Garfield";
    c.setFirstName(fname2);
    fname2.assign("Liz");
    cout << c.getFirstName() << endl;

    return 0;
}