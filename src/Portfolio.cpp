#include "Portfolio.h"
#include <iostream>

Portfolio::Portfolio(std::string name) : portfolioName(name) {}

std::string Portfolio::getPortfolioName() const {
    return portfolioName;
}

void Portfolio::addStock(const std::string& ticker, int shares, double avgPrice) {
    (void)ticker;
    (void)shares;
    (void)avgPrice;
}

void Portfolio::modifyStock(const std::string& ticker, int newShares, double newAvgPrice) {
    (void)ticker;
    (void)newShares;
    (void)newAvgPrice;
}

void Portfolio::deleteStock(const std::string& ticker) {
    (void)ticker;
}

void Portfolio::updateAllPrices(){}

double Portfolio::getTotalPortfolioValue(){
    return 0.0;
}

void Portfolio::displayPortfolio(){}

const std::vector<Stock>& Portfolio::getStocks() const {
    static const std::vector<Stock> empty_vector;
    return empty_vector;
}
