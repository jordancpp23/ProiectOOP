#include <iostream>
#include <vector>
#include <memory>
//#include <set>
#include "artist.h"
#include "piesa.h"
#include "album.h"
//#include "concert.h"
#include "trupa.h"
#include "single.h"
#include "cover.h"

int main() {
    Trupa t{"DiamondHead", "NWOBHM", 1976, {}, {}, {Artist{"BUTCHER", "voce", 50}}};
    Single p1{"Master of Puppets", 7.19, 250'000, {12, 11, 1985}};
    Piesa p2{"Disposable Heroes", 5.30};
    Piesa p3{"Damage Inc.", 3.50};
    std::shared_ptr<Trupa> band_ptr = std::make_shared<Trupa>(t);
    auto ptr2 = band_ptr;
    Cover p4{"Am I Evil?", 2.5, ptr2};
    std::vector<std::shared_ptr<Piesa>> temp;
    temp = {std::make_shared<Single>(p1),
            std::make_shared<Piesa>(p2),
            std::make_shared<Piesa>(p3),
            std::make_shared<Cover>(p4)};
    Album m1{temp, "Master of Puppets", 0,  1986};
    Single p5{"The Thing That Should Not Be", 5.55, 125'000, {1, 1, 1986}};
    m1.AdaugaPiesa(p5);
    m1.ScoatePiesa(p2);
    ///std::cout << m1;
    temp.clear();
    temp.emplace_back(std::make_shared<Piesa>("Fight fire with fire", 4.05));
    temp.emplace_back(std::make_shared<Single>("Creeping Death", 5.25, 600'000, Data{5, 3, 1984}));
    auto ptr3(band_ptr);
    temp.emplace_back(std::make_shared<Cover> ("Lightning to the Nations", 3.2, ptr3));
    Album m2{temp, "Ride the lightning", 0, 1984};
    std::set <Album> alb;
    alb.insert(m2);
    Artist a1{"James Hetfield", "Chitara ritmica", 58};
    Artist a2{"Lars Ulrich", "Tobe", 55};
    Artist a3{"Rob Trujillo", "Chitara bass", 42};
    Artist a4{"Kirk Hammett", "Chitara lead", 57};
    Artist a5{"Jason Newsted", "Chitara bass", 59};
    std::vector <Artist> mem = {a1, a2, a3, a4};
    Trupa t1{"Metallica", "Thrash Metal", 1981, alb, {}, mem};
    t1.AdaugaAlbum(m1);
    t1.AdaugaMembru(a5);
    t1.StergeMembru(a5);
    Concert c1{"Bucuresti", {23, 5, 2022}, "Rock in Giulesti"};
    t1.ProgrameazaConcert(c1);
    std::cout << t1;
    t1.AfisConcerte(std::cout);
    Piesa p6{"Take No Prisoners", 3.28};
    Piesa p7{"Hangar 18", 5.14};
    Piesa p8{"Five Magics", 5.41};
    Single p9{"Holy Wars...The Punishment Due", 6.36, 1'000'000, Data{5, 10, 1990}};
    temp = {std::make_shared<Piesa>(p5),
            std::make_shared<Piesa>(p6),
            std::make_shared<Piesa>(p7),
            std::make_shared<Single>(p5)};
    Album m3{temp, "Rust In Peace", 0, 1990};
    Artist a6{"Dave Mustaine", "Chitara ritmica", 59};
    Artist a7{"Dirk Verbeuren", "Tobe", 35};
    Artist a8{"James Lomenzo", "Chitara bass", 48};
    Artist a9{"Kiko Loureiro", "Chitara lead", 41};
    Trupa t2{"Megadeth", "Thrash Metal", 1983, {m3}, {}, {a6, a7, a8, a9}};
    t1.CheckSimilarity(t2);
    if (t2.CautaPiesa(p1))
        std::cout << "Trupa a scripts piesa!\n";
    else std::cout << "Wrong band / wrong song!\n";
    /*std::shared_ptr<Piesa> p9 = std::make_shared<Single>("Holy Wars...The Punishment Due", 6.36);
    p9 -> AfisarePiesa(std::cout);
    dynamic_cast<Single&> (*p9).DoSomething();*/
    return 0;
}
