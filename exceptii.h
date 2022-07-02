#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H
#include <stdexcept>

class eroare_aplicatie : public std::runtime_error {
public:
    explicit eroare_aplicatie(const std::string &msg) : runtime_error(msg) {}
};

class eroare_album : public eroare_aplicatie {
public:
    explicit eroare_album(const std::string &msg) : eroare_aplicatie(msg) {}
};

class eroare_trupa : public eroare_aplicatie {
public:
    explicit eroare_trupa(const std::string &msg) : eroare_aplicatie(msg) {}
};

#endif //OOP_EXCEPTII_H
