#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include <string>
#include "stock.h"

class Portfolio{
private:
    std::string portfolioName;
    std::vector<Stock> stocks;
public:
    Portfolio(std::string name);

    std::string getPortfolioName() const;

    //Stock ops
    void addStock(const std::string& ticker, int shares, double avgPrice);
    void modifyStock(const std::string& ticker, int newShares, double newAvgPrice);
    void deleteStock(const std::string& ticker);

    //updating funcs
    void updateAllPrices();
    double getTotalPortfolioValue();
    void displayPortfolio();

    const std::vector<stock>& getStocks() const;
};

#endif
