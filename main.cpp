#include <iostream>
#include <vector>
#include <string>

class Artist {
    std::string nume;
    std::string instr;
    int varsta;
public:
    Artist(const std::string &nume_ = "John Doe", const std::string &instr_ = "Voce", const int varsta_ = 18)
    : nume(nume_), instr(instr_), varsta(varsta_) {}

    Artist(const Artist &other) : nume(other.nume), instr(other.instr), varsta(other.varsta){}

    Artist& operator = (const Artist& other)
    {
        this -> nume = other.nume;
        this -> instr = other.instr;
        this -> varsta = other.varsta;
        return *this;
    }
    std::string GetNume (const Artist &art) // exemplu getter
    {
        return art.nume;
    }
    friend std::istream& operator >> (std::istream &is, Artist &art)
    {
        getline(is, art.nume);
        getline(is, art.instr);
        is >> art.varsta;
        return is;
    }
    friend std::ostream& operator << (std::ostream &os, const Artist& art)
    {
        os << "Numele artistului: " << art.nume << " , Varsta artistului: " << art.varsta <<
            " , Instrumentul muzical: " << art.instr << "\n";
        return os;
    }
    ~Artist() = default;
    friend class Trupa;
};

class Artist_Solo : Artist{
    //todo t2
};

class Piesa{
    std::string nume;
    double durata; //cum s-ar putea reprezenta mai bine?
public:
    Piesa(const std::string &nume, double durata_) : nume(nume), durata(durata_) {}
    ~Piesa() = default;
};

class Album{
public:
};

class Concert{

};

class Trupa {
    std::string nume;
    std::string genre;
    std::vector <Album> discografie;
    std::vector <Concert> concerte;
    std::vector <Artist> membri;
public:
    Trupa(const std::string & nume_ = "Placeholder", const std::string &genre_ = "Pop") : nume(nume_), genre(genre_) {}

};


int main() {
    Artist a1;
    std::cin >> a1;
    std::cout << a1;
    return 0;
}
