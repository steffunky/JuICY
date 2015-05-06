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
        static unsigned int Str4toLong(std::string line);
        static unsigned int LongtoStr(unsigned int line);
        static std::string Code(unsigned int v[],unsigned k[]);
        static std::string Decode(unsigned v[],unsigned k[]);
    public :
        static std::string Encrypt(std::string value, std::string key);
        static std::string Decrypt(std::string value, std::string key);
};
#endif

