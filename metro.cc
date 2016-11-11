#include "metro.h"

using namespace std;

void append_station(Line& line, Station* station);
void detach_station(Line& line, Station* station);

Station*
find_station(Line& line, const string& name) {
	// TODO: ������ �� ����� `line` ������� ��� ���������

	Station *tmp = line.stations.first;

	if (tmp == nullptr)
	{
		return nullptr;
	}

	do
	{
		if (tmp->name == name)
		{
			return tmp;
		}

		tmp = tmp->next;
	} while (tmp != line.stations.last);

	return nullptr;
}

void
move_to_end(Line& line, Station* station) {
	detach_station(line, station);
	append_station(line, station);
}

Station*
add_station(Line& line, const string& name) {
	// TODO: ������� ����� ������� ��� ��������� `name`.
	Station *station = new Station;
	station->name = name;
	station->next = nullptr;
	station->transits.first = station->transits.last = nullptr;
	//		  station->line = &line;
	// TODO: �������� ��������� ������� � ����� ����� `line`.
	append_station(line, station);
	return station;
}

Station*
get_station(Line& line, const string& name) {
	// TODO: ����� ��� �������� �� ����� `line` ������� ��� ��������� `name`.
	Station *tmp_station_ptr = find_station(line, name);
	if (tmp_station_ptr == nullptr)
	{
		tmp_station_ptr = add_station(line, name);
	}
	return tmp_station_ptr;
}

void
append_station(Line& line, Station* station) {
	// TODO: ��������� ������� `station` � ����� ����� `line`.
	if (line.stations.first == nullptr)
	{
		line.stations.first = station;
	}
	else
	{
		line.stations.last->next = station;
	}
	line.stations.last = station;
	station->line = &line;
}
//wegw
void // � �� ����� ���� �������, ��� ������� ���� �� ���� �����?
	 // ��� ��� �� ���� ����� ������ ���� �������?
	detach_station(Line& line, Station* station) {
	// TODO: ����������� ������� `station` �� ����� `line`:
	// TODO:    * ������ ������� � ������ ������� ������;
	if (station == line.stations.first)
	{
		line.stations.first = line.stations.first->next;
	}
	// TODO:    * ����� ����� ����� �������, �������������� ��������,
	else
	{
		Station *tmp_station_ptr = line.stations.first;
		while (tmp_station_ptr->next != station)
		{
			tmp_station_ptr = tmp_station_ptr->next;
		}
		// TODO:      �. �. ���������� � ���������.
		tmp_station_ptr->next = station->next;
		// TODO:        - ���� ������� �������� ���������, ��������� `last`.
		if (station == line.stations.last)
		{
			line.stations.last = tmp_station_ptr;
		}
	}

	delete station;
}


