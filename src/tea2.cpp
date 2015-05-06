/**
 * *
 * * @File : tea2.h
 * *
 * * @Authors : Steffunky
 * *
 * * @Date : 06/04/2015
 * *
 * * @Version : V0.1
 * *
 * * @Synopsis : Definition méthodes de tea.h, classe de crypto
 * **/
#include "tea.h"
#include <stdint.h>
static unsigned Str4toLong(std::string line){
    unsigned res = 0;
    for (unsigned i = 0; i<4;++i)
        res |= line[i] << i*8;
    return v;
}
static std::string LongtoStr4(unsigned line){
    return (std::string)(v & 0xFF) +
            (std::string)(v >> 8 & 0xFF) +
            (std::string)(v >> 16 & 0xFF) +
            (std::string)(v >> 24 & 0xFF);
}
static std::string TEA::Code(unsigned[] v, unsigned[] k){
    unsigned v0 = v[0],v1 = v[1];
    unsigned sum = 0;
    unsigned k0 = k[0],k1 = k[1], k2 = k[2], k3 = k[3];
    for(unsigned i=0;i < 32 ;++i){
        sum += m_DELTA;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }
    return std::to_string(v0) + std::to_string(v1);

}
static std::string TEA::Decode(unsigned[] v, unsigned[] k){
    unsigned v0 = v[0],v1 = v[1];
    unsigned sum = m_DELTA*32;
    unsigned k0 = k[0],k1 = k[1], k2 = k[2], k3 = k[3];
    for(unsigned i=0;i < 32 ;++i){
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= m_DELTA;
    }
    return std::to_string(v0) + std::to_string(v1);

}
static std::string TEA::Encrypt(std::string value, std::string key){
    std::vector<unsigned> tabvalues;
    unsigned[] tabkeys[5];
    std::string resultat = "";
    for(unsigned i = 0; i<4;++i)
        tabkey[i] = TEA::TEA.Str4toLong(key[i] + key[i+1] + key[i+2] + key[i+3]);
    for(unsigned i = 0; i<value.length();++i){
        tabvalues[0] = TEA::TEA.Str4toLong(value[i] + value[i+1] + value[i+2] + value[i+3]);
        tabvalues[1] = TEA::TEA.Str4toLong(value[i+4] + value[i+5] + value[i+6] + value[i+7]);
        resultat += TEA::TEA.Code(tabvalues,key);
    }
    return resultat;
}
static std::string TEA::Decrypt(std::string value, std::string key){
//TODO: Decrypter
}
    
