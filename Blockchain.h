/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Blockchain.h
 * Author: Alexandre
 *
 * Created on 3 avril 2018, 14:29
 */

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain{
public:
    Blockchain();
    void AddBlock(Block new_b);
    void MinePendingTransactions(std::string reward_addr);
    void AddTransaction(Transaction new_t);
    uint64_t GetBalance(std::string addr);
private:
    const int8_t _reward;
    uint32_t _difficulty;
    std::vector<Block> _chain;
    std::vector<Transaction> _pending_transactions;
    //The output Block cannot be changed
    Block _GetLastBlock() const;

};

#endif /* BLOCKCHAIN_H */

