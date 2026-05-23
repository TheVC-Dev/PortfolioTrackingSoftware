#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "portfolio.h"

class Client{
    std::string name;
    int id;

    Portfolio* portfolios;
    int portfolioCount;
    int capacity;

public:
    Client(std::string& name, int id, int capacity);
    ~Client();

    // portfolio management
    void createPortfolio(std::string portfolioName);
    void deletePortfolio(int portfolioIndex);

    // stock ops
    void addStockToPortfolio(int portfolioIndex, const std::string& ticker, int numofShares, double avgSharePrice);
    void modifyStockInPortfolio(int portfolioIndex, const std::string& ticker, int numofShares, double avgSharePrice);
    void addStockToPortfolio(int portfolioIndex, int stockIndex);

    void veiwAllPortfolios() const;
    void update:AllPortfolioPrices(); 

    //getters
    int getPortfolioCount() const;
    Portfolio* getPortfolios() const;
    std::string getName() const;
    int getId() const;
};

#endif
