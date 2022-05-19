#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <iostream>
using std::cout; using std::endl;

int main(){

    unique_ptr<string> p1(new string ("Stegosaurus"));

    unique_ptr<string> p2(p1.release());
    cout << *p2 << endl;

    unique_ptr<string> p3(new string("Trex"));

    p2.reset(p3.release());
    cout << *p2 << endl;

    if(p1)
        cout << "p1 not null? " << endl;
    if(p3)
        cout << "p3 not null?" << endl;
    cout << *p2 << endl;
}