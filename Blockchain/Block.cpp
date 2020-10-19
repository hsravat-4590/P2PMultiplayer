///
// Created by Hanzalah Ravat on 14/10/2020.
//
//

#include "Block.h"
#include "../crypto/sha256.h"
#include <time.h>
#include <vector>
#include <sstream>

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn){
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    /*
    const int cstrSize = nDifficulty + 1;
    char cstr[cstrSize];
     */
    std::vector<char> cstr(nDifficulty + 1);
    for (uint32_t i = 0; i < nDifficulty; i++){
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr.begin(),cstr.end());

    do{
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0,nDifficulty) !=str);

    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
    return sha256(ss.str());
}