/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Block.h
 * Author: Alexandre
 *
 * Created on 3 avril 2018, 14:22
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <iostream>
#include <vector>
#include "Transaction.h"

class Block{
public:
    //Hash of the previous block
    std::string prev_hash;
    Block(const std::vector<Transaction>& transactions);
    std::string GetHash();
    void MineBlock(uint32_t difficulty);
    std::vector<Transaction> transactions;
private:
    int64_t _nonce;
    std::string _hash;
    time_t _time;
    //The output string cannot be changed
    std::string _CalculateHash() const;
};

#endif /* BLOCK_H */

