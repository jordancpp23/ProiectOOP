#include <iostream>
#include <vector>
#include <set>
#include "artist.h"
#include "piesa.h"
#include "album.h"
#include "concert.h"
#include "trupa.h"
/*class Artist_Solo : Artist{
    //todo t2
};*/

int main() {
    Piesa p1{"Master of Puppets", 7.20};
    Piesa p2{"Disposable Heroes", 5.30};
    Piesa p3{"Damage Inc.", 3.50};
    Piesa p4{"bonus track : Blitzkrieg", 3.2}; // va fi clasa mostenita
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
    Concert c1{"Bucuresti", {23, 5, 2022}, "Rock in Giulesti"};
    t1.ProgrameazaConcert(c1);
    std::cout << t1;
    t1.AfisConcerte(std::cout);
    Piesa p5{"Holy Wars...The Punishment Due", 6.36};
    Piesa p6{"Take No Prisoners", 3.28};
    Piesa p7{"Hangar 18", 5.14};
    Piesa p8{"Five Magics", 5.41};
    temp = {p5, p6, p7, p8};
    Album m3{"Rust In Peace", temp, 0, 1990};
    Artist a6{"Dave Mustaine", "Chitara ritmica", 59};
    Artist a7{"Dirk Verbeuren", "Tobe", 35};
    Artist a8{"James Lomenzo", "Chitara bass", 48};
    Artist a9{"Kiko Loureiro", "Chitara lead", 41};
    Trupa t2{"Megadeth", "Thrash Metal", 1983, {m3}, {}, {a6, a7, a8, a9}};
    t1.CheckSimilarity(t2);
    if (t2.CautaPiesa(p1))
        std::cout << "Trupa a scris piesa!\n";
    else std::cout << "Wrong band / wrong song!\n";
    return 0;
}
