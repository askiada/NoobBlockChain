/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Blockchain.h"

Blockchain::Blockchain():_reward(100) {
    std::vector<Transaction> v = {Transaction("", "", 0)};
    _chain.emplace_back(v);
    _difficulty = 2;
    ;
}

void Blockchain::AddBlock(Block new_b) {
    new_b.prev_hash = _GetLastBlock().GetHash();
    new_b.MineBlock(_difficulty);
    _chain.push_back(new_b);
}

void Blockchain::MinePendingTransactions(std::string reward_addr){
    Block new_b = Block(_pending_transactions);
    new_b.MineBlock(_difficulty);
    _chain.push_back(new_b);
    //Transaction* tr = new Transaction("", reward_addr, _reward);
    _pending_transactions.emplace_back(Transaction("", reward_addr, _reward));
}

void Blockchain::AddTransaction(Transaction new_t) {
    _pending_transactions.emplace_back(new_t);
}

uint64_t Blockchain::GetBalance(std::string addr){
    uint64_t balance = 0;
    for(std::vector<Block>::iterator it = _chain.begin(); it != _chain.end(); ++it){
        for(std::vector<Transaction>::iterator it2 = it->transactions.begin(); it2 != it->transactions.end(); ++it2){
            if(it2->fromAddr.compare(addr) == 0){
                balance -= it2->amount;
            }
            if(it2->toAddr.compare(addr) == 0){
                balance += it2->amount;
            }
        }
    }
    return balance;
}

Block Blockchain::_GetLastBlock() const {
    return _chain.back();
}