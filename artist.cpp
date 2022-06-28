#include "artist.h"

Artist::Artist(const std::string &nume_, const std::string &instr_, const int varsta_)
        : nume(nume_), instr(instr_), varsta(varsta_) {}

Artist::Artist(const Artist &other) : nume(other.nume), instr(other.instr), varsta(other.varsta){}

Artist &Artist::operator=(const Artist &other) {
    this -> nume = other.nume;
    this -> instr = other.instr;
    this -> varsta = other.varsta;
    return *this;
}

const std::string &Artist::GetNume() const {
    return nume;
}

std::istream &operator>>(std::istream &is, Artist &art) {
    getline(is, art.nume);
    getline(is, art.instr);
    is >> art.varsta;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Artist &art) {
    os << "Numele artistului: " << art.nume << ", Varsta artistului: " << art.varsta <<
       ", Instrumentul muzical: " << art.instr << "\n";
    return os;
}