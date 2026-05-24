#include <iostream>
#include <cassert>
#include "../src/Client.h"


//create client and portfolio
void createClientandPort(){
    client client("Tim", 101);
    client.createPortfolio("Tech Stocks");
}

void stockOps(){
    portfolio* myPort = client.getPortfolio("Tech Stocks");
    if(myport){
        myPort->addStock("Appl", 15, 150.0);
        myport->modifyStock("Appl", 15, 145.0);
        myPort->displayPortfolio();
        myport->deleteStock();
    }
}

int main(){
    createClientandPort();
    stockOps();

    return 0;
}


