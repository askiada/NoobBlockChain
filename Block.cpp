/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Block.h"
#include "sha256/sha256.h"
#include <sstream>

Block::Block(const std::vector<Transaction>& transactions): transactions(transactions){
    _nonce = -1;
    _time = time(nullptr);
    _hash = _CalculateHash();
}

std::string Block::GetHash(){
    return _hash;
}

void Block::MineBlock(uint32_t difficulty) {
    char cstr[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';
 
    std::string str(cstr);
 
    do {
        _nonce++;
        _hash = _CalculateHash();
    } while (_hash.substr(0, difficulty) != str);
 
    std::cout << "Block mined: " << _hash << std::endl;
}

inline std::string Block::_CalculateHash() const {
    std::stringstream ss;
    
    ss  << _time;
    
    for(std::vector<Transaction>::const_iterator  it = transactions.begin(); it != transactions.end(); ++it){
        ss << it->fromAddr << it->toAddr << it->amount;
    }
    
    ss  << _nonce << prev_hash;
    
    //std::cout << ss.str() << std::endl;
    
    return sha256(ss.str());
}