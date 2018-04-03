/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Transaction.h"

Transaction::Transaction(std::string fromAddr, std::string toAddr, uint32_t amount):fromAddr(fromAddr), toAddr(toAddr), amount(amount){
}

