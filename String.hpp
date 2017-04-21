//
// Created by den on 13.04.17.
//
//
#ifndef NewMap_STRING_HPP
#define NewMap_STRING_HPP


#include <cstring>
#include <iostream>

class String {
private:
    char* str;
public:
    String();
    String(char* NewStr);
    ~String();
    String (String& elem);
    bool operator > (const String& right);
    bool operator < (const String& left);
    bool operator == (const String& right);
    String& operator= (const String& right);
    friend std::ostream & operator << (std::ostream &s, const String &elem);
    friend std::istream& operator >> (std::istream &s, String &elem);
    friend String& operator+ (String& left,String& right);
    char *getStr() const;
    void StrCpy(char* str2);
    int StrCmp(char* s);
    int StrLen(char* Str2);
};

String::String():
str(0)
{}

String::~String() {
delete[] str;
}

String::String(String &elem) {
    StrCpy(elem.str);
}
bool String::operator>(const String &right){
    return (StrCmp(right.getStr()) > 0);
}

bool String::operator<(const String &right) {
    return (StrCmp(right.getStr()) < 0);
}

char *String::getStr() const {
    return str;
}

String::String(char *NewStr) {
    std::cout << "NewStr----\n";
    str = new char [strlen(NewStr)];
    strcpy(str, NewStr);
}

bool String::operator==(const String &right) {
    return (!StrCmp(right.getStr()));
}

String &String::operator=(const String &right) {
    delete[] str;
    str = new char[strlen(right.getStr())];
    StrCpy(right.getStr());
}

std::ostream & operator <<(std::ostream& s, const String &elem) {
    s << elem.getStr();
    return s;
}

std::istream &operator>>(std::istream &s, String &elem) {
    char* k = new char[256];
    s >> k;
    delete [] elem.str;
    elem.str = new char [strlen(k)+1];
    elem.StrCpy(k);
    delete[] k;
    return s;
}


String &operator+ (String& left, String &right) {
    size_t n;
    n =  (strlen(right.str) + strlen(left.str));
    char* key = new char[n + 1];
    for (int i = 0; i < n; i++){
        if(i < strlen(left.str)){
            key[i] = left.str[i];
        } else {
            key[i] = right.str[(i - strlen(left.str))];
            key[n] = '\0';
        }

    }
    left.StrCpy(key);
    delete[] key;
    return left;
}

void String::StrCpy(char *str2){
    size_t n =  strlen(str2);
    str = new char[n+1];
    for(int i = 0; i < n; i++)
        str[i] = str2[i];
    str[n] = '\0';
}

int String::StrCmp(char * s) {
    if(StrLen(str) > StrLen(s))
        return 1;
    if(StrLen(str) < StrLen(s))
        return -1;
    if(StrLen(str) == StrLen(s)){
        for(int i = 0; i < StrLen(str); i++){
            if(str[i] > s[i])
                return 1;
            if(str[i] < s[i])
                return -1;
            if(str[i] == s[i])
                continue;
        }
        return 0;
    }


}

int String::StrLen(char* Str2) {
    int i = 0;
    while(Str2[i]) {
            if(Str2[i]) {
                i++;
            } else {
                break;
        }
    }
    return i;
}
#endif //NewMap_STRING_HPP
