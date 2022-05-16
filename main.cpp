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

class Durata{ //auxiliara, destul de hacky dar pare ca merge
    double minute, secunde;
public:
    Durata(double formaInitiala = 0.0, double minute_ = 0, double secunde_ = 0) :  minute(minute_),
                                                            secunde(secunde_) {
        minute = (int)formaInitiala;
        secunde = (int)100 * (formaInitiala - (int)formaInitiala);
    }
    friend Durata& operator+(Durata d1, Durata d2)
    {
        Durata *res = new Durata;
        res -> minute = (int)(d1.minute + d2.minute);
        res->secunde = d1.secunde + d2.secunde;
        if (res->secunde >= 60)
        {
            res->minute++;
            res->secunde -= 60;
        }
        res->secunde = (int) res->secunde;
        return *res;
    }
    friend Durata& operator-(Durata d1, Durata d2)
    {
        Durata *res = new Durata;
        res -> minute = (int)(d1.minute - d2.minute);
        res->secunde = d1.secunde - d2.secunde;
        if (res->secunde < 0)
        {
            res->minute--;
            res->secunde += 61;
        }
        res->secunde = (int) res->secunde;
        return *res;
    }
    friend std::istream &operator >>(std::istream &is, Durata &durata)
    {
        double formaInitiala;
        is >> formaInitiala;
        durata.minute = (int)formaInitiala;
        durata.secunde = (int)100 * (formaInitiala - (int)formaInitiala);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Durata &durata) {
        os << durata.minute << " minute si " << durata.secunde << " secunde\n";
        return os;
    }

};

class Piesa{
    std::string nume;
    Durata durata;
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
        os << p.durata;
        return os;
    }
    const std::string& GetNume() const
    {
        return nume;
    }
    Durata GetDurata() const
    {
        return durata;
    }
    ~Piesa() = default;
};

class Album{
    std::string nume;
    Durata durata;
    std::vector <Piesa> tracks;
public:
    Album(const std::string &nume_ = "Untitled Unmastered", const std::vector<Piesa> &tracks_ = {}, double durata_ = 0)
    : nume(nume_), durata(durata_), tracks(tracks_) {
        for (auto &piesa : tracks)
            durata = durata + piesa.GetDurata();
    }

    void AdaugaPiesa(const Piesa &p)
    {
        tracks.push_back(p);
        durata = durata + p.GetDurata();
    }

    friend std::ostream &operator<<(std::ostream &os, const Album &album) {
        os << "Numele albumului: " << album.nume << "\n";
        os << "Durata albumului: " << album.durata;
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
    m1.AdaugaPiesa({"Breadfan", 3.2});
    std::cout << m1;
    return 0;
}
