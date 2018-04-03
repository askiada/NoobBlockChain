/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexandre
 *
 * Created on 3 avril 2018, 14:22
 */

#include "Blockchain.h"


int main() {
    Blockchain b_chain = Blockchain();

    /*std::cout << "Mining block 1..." << std::endl;
    bChain.AddBlock(Block(1, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    bChain.AddBlock(Block(2, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    bChain.AddBlock(Block(3, "Block 3 Data"));*/

    b_chain.AddTransaction(Transaction("addr1", "addr2", 100));
    b_chain.AddTransaction(Transaction("addr2", "addr1", 50));
    
    std::cout << "Starting the miner..." << std::endl;
    b_chain.MinePendingTransactions("AlexSki");
    
    std::cout << "balance of AlexSki : " << b_chain.GetBalance("AlexSki") << std::endl;
    
    
    std::cout << "Starting the miner again..." << std::endl;
    
    b_chain.MinePendingTransactions("AlexSki");
    
    std::cout << "balance of AlexSki : " << b_chain.GetBalance("AlexSki") << std::endl;
    
    
    
    return 0;
}

