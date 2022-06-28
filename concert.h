//
// Created by iorda on 6/28/2022.
//

#ifndef OOP_CONCERT_H
#define OOP_CONCERT_H
#include <string>
#include <iostream>
#include "data.h"

class Concert{
    std::string locatie;
    Data data{};
    std::string nume;
public:
    explicit Concert(const std::string &locatie_ = "Unknown", const Data &data_ = Data(), const std::string &nume_ = "Untitled");
    friend std::istream& operator >> (std::istream &is, Concert &c);
    friend std::ostream& operator << (std::ostream &os, const Concert& c);
    [[nodiscard]] const std::string& GetNume() const;
    const Data & GetData() const;
    bool operator < (const Concert &other) const;
    //const std::string& getLocatie() const;
    ~Concert() = default;


};

#endif //OOP_CONCERT_H
