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
      output << "Transit to station "<< *current<<endl;
      current=current->next;
    }
    return output;
}

ostream&
operator<<(ostream& output, const Line& line) {
    output << "line "<< line.name<<"\"\n";
    Station* current = line.stations.first;
    while (current)
    {
      output <<"Station "<< *current<<endl;
    current=current->next;
    }
    // TODO: печатать линию.
    return output;
}

ostream&
operator<<(ostream& output, const Scheme& scheme) {
    Line* current = scheme.first;
    output<<"scheme metro "<<endl;
    while (current)
    {
     output<<"Line "<< *current <<endl;

    current=current->next;
    }
    // TODO: печатать схему.
    return output;
 }
