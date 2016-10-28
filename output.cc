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
      output <<"Transit to station "<< current->destination->name<<endl;
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
      output <<"Station "<< current->name <<endl;
      if (current->transits.first != nullptr)
      {
      Transit* tekus = current->transits.first;
       while (tekus)
       {
       output <<"transit to station "<<tekus->destination->name <<endl;
       tekus= tekus->next;
       }
      }
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
     output<<"Line "<< current->name <<endl;
      Station* tekus = current->stations.first;
      while (tekus)
    {
      output <<"Station "<< tekus->name <<endl;
      if (tekus->transits.first != nullptr)
      {
      Transit* tekus1 = tekus->transits.first;
       while (tekus1)
       {
       output <<"transit to station "<<tekus1->destination->name<<endl;
       tekus1= tekus1->next;
       }
      }
      tekus=tekus->next;
    }
    current=current->next;
    }
    // TODO: печатать схему.
    return output;
}
