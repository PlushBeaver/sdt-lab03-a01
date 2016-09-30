#include "metro.h"

#include <iostream>

using namespace std;

void parse_line(
        std::istream& input, std::string& keyword, Scheme& scheme);
void parse_station(
        std::istream& input, std::string& keyword, Scheme& scheme, Line* line);
void parse_transit(
        std::istream& input, std::string& keyword, Scheme& scheme, Station* station);

Scheme
parse_scheme(istream& input) {
    Lines scheme;

    // Инициализировать схему как пустой список.
    scheme.first = nullptr;
    scheme.last = nullptr;

    // Считать первое слово.
    string keyword = read_word(input);

    // Пока последнее считанное слово — "line", разобрать описание линии.
    while (keyword == "line") {
        parse_line(input, keyword, scheme);
    }

    return scheme;
}

void
parse_line(std::istream& input, std::string& keyword, Scheme& scheme) {
    string name = read_word(input);
    Line* line = get_line(scheme, name);

    keyword = read_word(input);
    while (keyword == "station") {
        parse_station(input, keyword, scheme, line);
    }
}

void
parse_station(istream& input, string& keyword, Lines& scheme, Line* line) {
    string name = read_word(input);
    Station* station = find_station(*line, name);
    if (station != nullptr) {
        move_to_end(*line, station);
    } else {
        station = add_station(*line, name);
    }

    keyword = read_word(input);

    while (keyword == "transit") {
        parse_transit(input, keyword, scheme, station);
    }
}

void
parse_transit(istream& input, string& keyword, Scheme& scheme, Station* station) {
    read_word(input);  // to
    read_word(input);  // station
    string station_name = read_word(input);
    read_word(input);  // of
    string line_name = read_word(input);
    read_word(input);  // line

    Line* sibling_line = get_line(scheme, line_name);
    Station* sibling_station = get_station(*sibling_line, station_name);
    add_transit(station, sibling_station);

    keyword = read_word(input);
}
