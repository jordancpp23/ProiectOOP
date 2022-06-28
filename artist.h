
#ifndef OOP_ARTIST_H
#define OOP_ARTIST_H
#include <string>
#include <iostream>
class Artist {
    std::string nume;
    std::string instr;
    int varsta;
public:
    explicit Artist(const std::string &nume_ = "John Doe", const std::string &instr_ = "Voce", const int varsta_ = 18);

    Artist(const Artist &other);

    Artist& operator = (const Artist& other);

    [[nodiscard]] const std::string& GetNume() const;

    friend std::istream& operator >> (std::istream &is, Artist &art);

    friend std::ostream& operator << (std::ostream &os, const Artist& art);

    ~Artist() = default;
};
#endif //OOP_ARTIST_H
