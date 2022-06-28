//
// Created by iorda on 6/28/2022.
//

#include "concert.h"

Concert::Concert(const std::string &locatie_, const Data &data_, const std::string &nume_) : locatie(locatie_), data(data_), nume(nume_) {}

std::istream &operator>>(std::istream &is, Concert &c) {
    is >> c.locatie >> c.data >> c.nume;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Concert &c) {
    os << "Numele concertului: " << c.nume << "\n";
    os << "Locatia concertului: " << c.locatie << "\n";
    os << "Data concertului: " << c.data;
    return os;
}

const std::string &Concert::GetNume() const {
    return nume;
}

const Data &Concert::GetData() const {
    return data;
}

bool Concert::operator<(const Concert &other) const {
    return data < other.data;
}