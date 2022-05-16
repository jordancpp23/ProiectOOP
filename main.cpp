#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

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
    const std::string& GetNume() const
    {
        return nume;
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
        os << "Numele artistului: " << art.nume << ", Varsta artistului: " << art.varsta <<
            ", Instrumentul muzical: " << art.instr << "\n";
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
    double durata;
public:
    Piesa(const std::string &nume_ = "Nameless song", double durata_ = 0) : nume(nume_), durata(durata_) {}
    friend std::istream& operator >> (std::istream &is, Piesa &p)
    {
        getline(is, p.nume);
        is >> p.durata;
        return is;
    }
    friend std::ostream& operator << (std::ostream &os, const Piesa& p)
    {
        os << "Numele piesei: " << p.nume << ", Durata piesei: ";
        os << (int)p.durata << " minute si " << (int) 100 * (p.durata - (int)p.durata) << " secunde\n";
        return os;
    }
    const std::string& GetNume() const
    {
        return nume;
    }
    double GetDurata() const
    {
        return durata;
    }
    ~Piesa() = default;
};

class Album{
    std::string nume;
    double durata;
    std::vector <Piesa> tracks;
public:
    Album(const std::string &nume_ = "Untitled Unmastered", const std::vector<Piesa> &tracks_ = {}, double durata_ = 0) : nume(nume_), durata(durata_),
                                                                                      tracks(tracks_) {
        for (auto &piesa : tracks)
            durata = AdunaDurate(durata, piesa.GetDurata());
    }
    double AdunaDurate(double x, double y) // nu prea ii e locul aici dar nu prea am unde altundeva sa o bag
    {
        double s1 = 100 * (x - (int) x);
        double s2 = 100 * (y - (int) y);
        if (s1 + s2 - 60 <= 1e-9) // improvizatie pt floating point
        {
            x = 1.0 * ((int)x + (int)y);
            x++;
            x += (s1 + s2 - 60) / 100;
        }
        else x += y;
        return x;
    }

    void AdaugaPiesa(const Piesa &p)
    {
        tracks.push_back(p);
        durata = AdunaDurate(durata, p.GetDurata());
    }

    friend std::ostream &operator<<(std::ostream &os, const Album &album) {
        os << "Numele albumului: " << album.nume << "\n";
        os << "Durata albumului: " << (int)album.durata << " minute si " << 100 * (album.durata - (int)album.durata) << " secunde\n";
        os << "Tracklist:\n";
        for (size_t i = 0; i < album.tracks.size(); i++)
            os << (i + 1) << ". " << album.tracks[i];
        return os;
    }

    ~Album() = default;
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
    Artist a1{"James Hetfield", "Chitara ritmica", 58};
    Piesa p1{"Master of Puppets", 7.20};
    Piesa p2{"Disposable Heroes", 5.30};
    Piesa p3{"Damage Inc.", 3.50};
    Piesa p4{"bonus track", 3.2};
    std::vector<Piesa> temp;
    temp.push_back(p1);
    temp.push_back(p2);
    temp.push_back(p3);
    temp.push_back(p4);
    Album m1("Master of Puppets", temp);
    std::cout << m1;
    return 0;
}
