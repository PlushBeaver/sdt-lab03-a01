#include "metro.h"

#include <iostream>

using namespace std;

int
main() {
    Scheme scheme = parse_scheme(cin);
    cout << scheme << endl;
    return 0;
}
