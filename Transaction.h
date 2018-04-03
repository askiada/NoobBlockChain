/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Transaction.h
 * Author: Alexandre
 *
 * Created on 3 avril 2018, 16:33
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstdint>
#include <string>

class Transaction{
public:
    Transaction(std::string fromAddr, std::string toAddr, uint32_t amount);
    std::string fromAddr;
    std::string toAddr; 
    uint32_t amount;
};

#endif /* TRANSACTION_H */

