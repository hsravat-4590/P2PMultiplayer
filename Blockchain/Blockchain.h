////
// Created by hanza on 14/10/2020.
//
//
#ifndef P2PMULTIPLAYER_BLOCKCHAIN_H
#define P2PMULTIPLAYER_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain{
public:
    Blockchain();

    void AddBlock(Block bNew);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

#endif //P2PMULTIPLAYER_BLOCKCHAIN_H
