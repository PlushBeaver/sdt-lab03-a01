#include "metro.h"

#include <iostream>

using namespace std;

ostream&
operator<<(ostream& output, const Transit& transit) {
    // TODO: печатать переход.
    output <<"transit to station "<<transit.destination->name;
    return output;
}

ostream&
operator<<(ostream& output, const Station& station) {
    // TODO: печатать станцию.
    output << "station\" " <<station.name<<"\"\n";
    Transit* current = station.transits.first;
    while (current)
    {
      output << *current <<endl;
      current=current->next;
    }
    return output;
}

ostream&
operator<<(ostream& output, const Line& line) {
    // TODO: печатать линию.
    return output;
}

ostream&
operator<<(ostream& output, const Scheme& scheme) {
    // TODO: печатать схему.
    return output;
}
