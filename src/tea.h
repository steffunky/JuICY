/**
 * *
 * * @File : tea.h
 * *
 * * @Authors : Steffunky
 * *
 * * @Date : 06/04/2015
 * *
 * * @Version : V0.1
 * *
 * * @Synopsis : Header de classe avec des méthodes statiques pour crypter les fichiers
 * **/
#ifndef __TEA_H__
#define __TEA_H__
#include <string>
class TEA {
    protected :
        static const int m_DELTA = 0x9e3779b9;
        static unsigned Str4toLong(std::string line);
        static unsigned LongtoStr4(std::unsigned line);
        static std::string Code(unsigned[] v,unsigned[] k);
        static std::string Decode(unsigned[] v,unsigned[] k); 
    public :
        static std::string encrypt(std::string value, std::string key);
        static std::string decrypt(std::string value, std::string key);
}
