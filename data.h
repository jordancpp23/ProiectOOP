//
// Created by iorda on 6/28/2022.
//

#ifndef OOP_DATA_H
#define OOP_DATA_H
#include <iostream>

class Data{
    int zi, luna, an;
public:
    Data(int zi_ = 30, int luna_ = 02, int an_ = 1900);

    friend std::istream& operator >> (std::istream &is, Data &d);

    friend std::ostream& operator << (std::ostream &os, const Data& d);

    bool operator < (const Data &other) const;

    bool operator == (const Data &other) const;

    ~Data() = default;
};

#endif //OOP_DATA_H
