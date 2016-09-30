#include "metro.h"

#include <iostream>

using namespace std;

int
main() {
    Station s;
     s.transits.first=nullptr;
     s.transits.last=nullptr;
     s.name="Station";
     add_transit(&s,&s);
    //cout <<read_word(cin) <<endl;
    //Scheme scheme = parse_scheme(cin);
    //cout << scheme << endl;
    cout << s <<endl;
    return 0;
}
