//
// Created by iorda on 6/28/2022.
//

#include "data.h"

Data::Data(int zi_, int luna_, int an_) : zi(zi_), luna(luna_), an(an_) {}

std::istream &operator>>(std::istream &is, Data &d) {
    is >> d.zi >> d.luna >> d.an;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Data &d) {
    os << d.zi << "." << d.luna << "." << d.an << "\n";
    return os;
}

bool Data::operator<(const Data &other) const {
    if (an < other.an) return true;
    if (an == other.an) {
        if (luna < other.luna) return true;
        if (luna == other.luna)
            if (zi < other.zi) return true;
    }
    return false;
}

bool Data::operator==(const Data &other) const {
    return zi == other.zi && luna == other.luna && an == other.an;
}