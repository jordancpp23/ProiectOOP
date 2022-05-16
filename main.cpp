#include <iostream>
#include <vector>
#include <string>
#include <set>

class Artist {
    std::string nume;
    std::string instr;
    int varsta;
public:
    explicit Artist(const std::string &nume_ = "John Doe", const std::string &instr_ = "Voce", const int varsta_ = 18)
    : nume(nume_), instr(instr_), varsta(varsta_) {}

    Artist(const Artist &other) : nume(other.nume), instr(other.instr), varsta(other.varsta){}

    Artist& operator = (const Artist& other)
    {
        this -> nume = other.nume;
        this -> instr = other.instr;
        this -> varsta = other.varsta;
        return *this;
    }
    /*const std::string& GetNume() const
    {
        return nume;
    }*/
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
    int an_aparitie;
public:
    explicit Album(const std::string &nume_ = "Untitled Unmastered", const std::vector<Piesa> &tracks_ = {}, double durata_ = 0, int an = 0) : nume(nume_), durata(durata_),
                                                                                      tracks(tracks_), an_aparitie(an) {
        for (auto &piesa : tracks)
            durata = AdunaDurate(durata, piesa.GetDurata());
    }
    double AdunaDurate(double x, double y) // nu prea ii e locul aici dar nu prea am unde altundeva sa o bag
    {
        double s1 = 100 * (x - (int) x);
        double s2 = 100 * (y - (int) y);
        if (s1 + s2 - 60 >= 1e-6) // improvizatie pt floating point
        {

            x = 1.0 * ((int)x + (int)y);
            x++;
            x += (s1 + s2 - 60) / 100;
        }
        else x += y;
        return x;
    }
    double ScadeDurate(double x, double y)
    {
        double s1 = 100 * (x - (int) x);
        double s2 = 100 * (y - (int) y);
        ///std::cout << x << " " << y << " " <<s1 << " " << s2 << "\n";
        if (s1 - s2 < 0)
        {
            x = (int) (x - y);
            x += (0.6 - (s2 - s1) / 100);
        }
        else x -= y;
        return x;
    }
    void AdaugaPiesa(const Piesa &p)
    {
        tracks.push_back(p);
        durata = AdunaDurate(durata, p.GetDurata());
    }

    void ScoatePiesa(const Piesa &p)
    {
        unsigned pos = 2000000000;
        for (unsigned i = 0; i < tracks.size(); i++)
            if (tracks[i].GetNume() == p.GetNume())
                pos = i;
        if (pos == 2e9)
        {
            std::cout << "Piesa " << p.GetNume() << " nu se afla pe album!\n";
            return;
        }
        tracks.erase(tracks.begin() + pos);
        durata = ScadeDurate(durata, p.GetDurata());
    }
    /*const std::string& GetNume() const
    {
        return nume;
    }
    double GetDurata() const
    {
        return durata;
    }*/
    friend std::ostream &operator<<(std::ostream &os, const Album &album) {
        os << "Numele albumului: " << album.nume << "\n";
        os << "Durata albumului: " << (int)album.durata << " minute si " << 100 * (album.durata - (int)album.durata) << " secunde\n";
        os << "Tracklist:\n";
        for (unsigned i = 0; i < album.tracks.size(); i++)
            os << (i + 1) << ". " << album.tracks[i];
        std::cout << "\n\n";
        return os;
    }

    bool operator<(const Album &other) const {
        return an_aparitie < other.an_aparitie;
    }

    ~Album() = default;
};

class Concert{
    std::string locatie;
    std::string data;
    std::string nume;
public:
    Concert(const std::string &locatie_ = "Neanuntat", const std::string &data_ = "29 Februarie",
            const std::string &nume_ = "nu stiu") :
                locatie(locatie_), data(data_), nume{nume_}{}

   /* const std::string& getLocatie() const {
        return locatie;
    }

    const std::string& getData() const {
        return data;
    }*/

    friend std::ostream &operator<<(std::ostream &os, const Concert &concert){
        os << "Concertul " << concert.nume << " are loc in " << concert.locatie <<
            " la data de " << concert.data << "\n";
        return os;
    }

    friend class Trupa;
};

class Trupa {
    std::string nume;
    std::string genre;
    int an_infiintare;
    std::set <Album> discografie;
    std::vector <Concert> concerte;
    std::vector <Artist> membri;
public:
    Trupa(const std::string &nume_ = "Placeholder", const std::string &genre_ = "Pop", const int an = 0, const std::set<Album> &discografie_ = {},
          const std::vector<Concert> &concerte_ = {}, const std::vector<Artist> &membri_ = {}) : nume(nume_), genre(genre_),
            an_infiintare(an), discografie(discografie_), concerte(concerte_), membri(membri_) {}

    void AdaugaAlbum(const Album &album)
    {
        discografie.insert(album);
    }
    void ProgrameazaConcert(const Concert &concert)
    {
        for (auto &c : concerte)
            if (c.nume == concert.nume)
            {
                std::cout << "Concertul este deja programat!\n";
                return;
            }
            else if (c.data == concert.data)
            {
                std::cout << "Trupa are un alt concert programat pe aceeasi data!\n";
                return;
            }
        concerte.push_back(concert);
    }
    void AdaugaMembru(const Artist &artist)
    {
        membri.push_back(artist);
    }
    void StergeMembru(const Artist &artist)
    {
        unsigned pos = 2000000000;
        for (unsigned i = 0; i < membri.size(); i++)
            if (membri[i].nume == artist.nume)
                pos = i;
        if (pos == 2e9)
        {
            std::cout << "Artistul " << artist.nume << " nu face parte din trupa!\n";
            return;
        }
        membri.erase(membri.begin() + pos);
    }
    void AfisAlbume(std::ostream &os) const
    {
        os << "Numarul albumelor: " << discografie.size() << "\n";
        os << "Lista albumelor, in ordine cronologica:\n";
        int cnt = 1;
        for (auto &it : discografie)
            os << cnt << ". " << it, ++cnt;
    }
    void AfisMembri (std::ostream &os) const
    {
        os << "Membrii trupei sunt: \n";
        for (auto &mem : membri)
            os << mem;
    }
    friend std::ostream& operator<< (std::ostream &os, const Trupa& band)
    {
        os << "Numele trupei: " << band.nume << ", Anul infiintarii: " << band.an_infiintare << ", Genul muzical: "
                << band.genre << "\n\n";
        band.AfisMembri(os);
        os << "\n";
        band.AfisAlbume(os);
        return os;
    }
    ~Trupa() = default;
};


int main() {
    Piesa p1{"Master of Puppets", 7.20};
    Piesa p2{"Disposable Heroes", 5.30};
    Piesa p3{"Damage Inc.", 3.50};
    Piesa p4{"bonus track : Blitzkrieg", 3.2};
    std::vector<Piesa> temp = {p1, p2, p3, p4};
    Album m1{"Master of Puppets", temp, 0, 1986};
    m1.AdaugaPiesa({"Breadfan", 3.5});
    //std::cout << m1;
    m1.ScoatePiesa(p1);
    temp.clear();
    temp.push_back({"Fight fire with fire", 4.05});
    temp.push_back({"Ride the Lightning", 3.45});
    temp.push_back({"Escape", 5});
    Album m2{"Ride the lightning", temp, 0, 1984};
    std::set <Album> alb;
    alb.insert(m1);
    Artist a1{"James Hetfield", "Chitara ritmica", 58};
    Artist a2{"Lars Ulrich", "Tobe", 55};
    Artist a3{"Rob Trujillo", "Chitara bass", 42};
    Artist a4{"Kirk Hammett", "Chitara lead", 57};
    Artist a5{"Jason Newsted", "Chitara bass", 59};
    std::vector <Artist> mem = {a1, a2, a3, a4};
    Trupa t1{"Metallica", "Thrash Metal", 1981, alb, {}, mem};
    t1.AdaugaAlbum(m2);
    t1.AdaugaMembru(a5);
    t1.StergeMembru(a5);
    Concert c1{"Bucuresti", "23 mai 2022", "Rock in Giulesti"};
    t1.ProgrameazaConcert(c1);
    std::cout << t1;
    return 0;
}
