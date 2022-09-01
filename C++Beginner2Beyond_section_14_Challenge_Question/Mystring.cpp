#include <iostream>
#include <cstring>
#include <string>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy_s(str, get_length(), s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy_s(source.str, get_length(), str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) noexcept
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) noexcept {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy_s(str, get_length(), rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) noexcept {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

bool Mystring::operator==(const Mystring& other) const{
    for (int i = 0; i < get_length(); i++)
        if (&str[i] == &other.str[i]) {
        }
        else
            return false;

    return true;
};

bool Mystring::operator!=(const Mystring& other) const{
    for (int i = 0; i < get_length(); i++)
        if (&str[i] != &other.str[i]) {
        }
        else
            return true;

    return false;
};

bool Mystring::operator<(const Mystring& other) const{
    int temp = 0, temp2 = 0;
    for (int i = 0; i < get_length(); i++)
        temp += str[i];

    for (int i = 0; i < other.get_length(); i++)
        temp2 += other.str[i];

    if (temp < temp2)
        return true;
    else
        return false;

};

bool Mystring::operator>(const Mystring& other) const{
    int temp = 0, temp2 = 0;
    for (int i = 0; i < get_length(); i++)
        temp += str[i];

    for (int i = 0; i < other.get_length(); i++)
        temp2 += other.str[i];

    if (temp > temp2)
        return true;
    else
        return false;
};

Mystring& Mystring::operator+=(const Mystring& other){
    *this = *this + other;
    return *this;
};

Mystring& Mystring::operator+(const Mystring& other) const{
    char* temp = new char[std::strlen(str) + std::strlen(other.str) + 1];
    strcpy_s(temp,get_length(), str);
    strcat_s(str, sizeof(str), other.str);
    Mystring tempObj{ temp };
    delete[] temp;
    return tempObj;
};

Mystring& Mystring::operator-() const{
    char* temp = new char[std::strlen(str)+ 1];
    strcpy_s(temp, get_length(), str);
    for (int i = 0; i < get_length(); i++)
        temp[i] = tolower(temp[i]);

    Mystring tempObj{ temp };
    delete[] temp;
    return tempObj;
};

Mystring& Mystring::operator*(int n) const{
    char* temp = new char[std::strlen(str) *n];
    strcpy_s(temp, get_length(), str);
    for (int i = 0; i < n; i++)
        strcat_s(str, sizeof(str), str);

    Mystring tempObj{ temp };
    delete[] temp;
    return tempObj;

};

Mystring& Mystring::operator*=(int n) {
    *this = *this * n;
    return *this;
}

Mystring& Mystring::operator++() { 
    for (size_t i = 0; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}


Mystring Mystring::operator++(int) {
    Mystring temp(*this);      
    operator++();                   
    return temp;               
}