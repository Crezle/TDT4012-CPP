#include "task1.h"

void vectorIterator (std::vector<std::string> v) {

    std::vector<std::string>::iterator str; 
    for (str = v.begin(); str != v.end(); str++) {
        std::cout << *str << std::endl;
    }
}

// 1b)

void reverseVectorIterator (std::vector<std::string> v) {

    std::vector<std::string>::reverse_iterator str; 
    for (str = v.rbegin(); str < v.rend(); str++) {
        std::cout << *str << std::endl;
    }
}

// 1c)

void replace (std::vector<std::string>& v, std::string old, std::string replacement) {

    std::vector<std::string>::iterator str;
    for (str = v.begin(); str < v.end(); str++) {
        if (*str == old) {
            *str = replacement;
        }
    }
}

// 1d)

void setIterator (std::set<std::string> s) {

    std::set<std::string>::iterator str;
    for (str = s.begin(); str != s.end(); str++) {
        std::cout << *str << std::endl;
    }
}
void reverseSetIterator (std::set<std::string> s) {

    std::set<std::string>::reverse_iterator str; 
    for (str = s.rbegin(); str != s.rend(); str++) {
        std::cout << *str << std::endl;
    }
}

void setReplace (std::set<std::string>& s, std::string old, std::string replacement) {

    for (std::set<std::string>::iterator str = s.begin(); str != s.end(); str++) {
        if (*str == old) {
            str = s.erase(str);
            str = s.insert(str, replacement);
        }
    }
}

// VIKTIG Å VITE: ITERATOR PEKER TIL EN POSISJON I EN TYPE LISTE F.eks.: vektorer,
// når en slik liste som et SET mister sitt element må vi gjøre om iteratorpekeren om til neste element
// samtidig når vi får et nytt element må vi flytte iteratoren til dette nye elementet. 