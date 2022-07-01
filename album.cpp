//
// Created by iorda on 6/28/2022.
//

#include "album.h"


Album::Album(std::vector<std::shared_ptr<Piesa>> &tracks_, const std::string &nume_, const double durata_,
             const int an_aparitie_) : tracks(std::move(tracks_)), nume(nume_), durata(durata_), an_aparitie(an_aparitie_) {
    durata = 0;
    for (const auto &piesa : tracks) {
        durata = AdunaDurate(durata, piesa->GetDurata());
    }
}

double Album::AdunaDurate(double x, double y) // nu prea ii e locul aici dar nu prea am unde altundeva sa o bag
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

double Album::ScadeDurate(double x, double y) {
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

bool Album::VerificaPiesa(const Piesa &p) const {
    for (const auto &piesa : tracks)
        if (piesa -> GetNume() == p.GetNume())
            return true;
    return false;
}

void Album::AdaugaPiesa(const Piesa &p) {
    if (VerificaPiesa(p)) {
        std::cout << "Piesa " << p.GetNume() << "se afla deja pe albumul " << nume << "!\n";
        return;
    }
    tracks.emplace_back(p.clone());
    durata = AdunaDurate(durata, p.GetDurata());
}

void Album::ScoatePiesa(const Piesa &p) {
    unsigned pos = 2'000'000'000;
    for (unsigned i = 0; i < tracks.size(); i++)
        if (tracks[i]->GetNume() == p.GetNume())
            pos = i;
    if (pos == 2e9)
    {
        std::cout << "Piesa " << p.GetNume() << " nu se afla pe albumul " << nume << "!\n";
        return;
    }
    tracks.erase(tracks.begin() + pos);
    durata = ScadeDurate(durata, p.GetDurata());
}

const std::string &Album::GetNume() const {
    return nume;
}

std::ostream &operator<<(std::ostream &os, const Album &album) {
    os << "Numele albumului: " << album.nume << "\n";
    os << "Durata albumului: " << (int)album.durata << " minute si " << 100 * (album.durata - (int)album.durata) << " secunde\n";
    os << "Tracklist:\n";
    for (unsigned i = 0; i < album.tracks.size(); i++)
        os << (i + 1) << ". " << *album.tracks[i];
    std::cout << "\n\n";
    return os;
}

bool Album::operator<(const Album &other) const {
    return an_aparitie < other.an_aparitie;
}

