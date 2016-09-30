#include "metro.h"

using namespace std;

void
add_transit(Station* station, Station* destination)
{
    // TODO: добавить переход со станции `station` на станцию `destination`.
    Transit* transit= new Transit;
    transit->next =nullptr;
    transit->destination = destination;
    if ( station->transits.last != nullptr)
    {
        station->transits.last->next= transit;}
    else
    {
        station->transits.first = transit;
    }
station->transits.last = transit;
}
