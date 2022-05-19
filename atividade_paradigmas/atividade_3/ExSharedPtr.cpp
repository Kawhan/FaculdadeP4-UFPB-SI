#include <string>
using std::string;

#include <memory>
using std::shared_ptr;

#include <iostream>
using std::cout; using std::endl;

int main(){
    shared_ptr<string> p1=std::make_shared<string>("Stegosaurus");

    shared_ptr<string> p2(p1);
    cout << *p2 << endl;

    shared_ptr<string> p3=std::make_shared<string>("Trex");

    p2 = (p3);
    cout << *p2 << endl;

    if(p1)
        cout << "p1 not null? " << p1.use_count() << endl;
    if(p3)
        cout << "p3 not null?" << p3.use_count() << endl;
    cout << *p2 << endl;
}