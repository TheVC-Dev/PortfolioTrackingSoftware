#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include <string>
#include "Portfolio.h"

class Client{
private:
    std::string name;
    int id;
    std::vector<Portfolio> portfolios;

public:
    Client(std::string name, int id);
    ~Client();

    // Portfolio Ops
    void createPortfolio(const std::string& portfolioName);
    void deletePortfolio(const std::string& portfolioName);

    // interact directly w portfolio
    Portfolio* getPortfolio(const std::string& portfolioName);

    void viewAllPortfolios();

    //getters
    std::string getName() const;
    int getId() const;
};

#endif
