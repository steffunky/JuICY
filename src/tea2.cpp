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
    //TODO:: ENCRYPT
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
        
