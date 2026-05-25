#include "Client.h"

Client::Client(std::string name, int id) 
    : name(name), id(id) {}

Client::~Client() {}

void Client::createPortfolio(const std::string& portfolioName) {
    portfolios.push_back(Portfolio(portfolioName));
}

void Client::deletePortfolio(const std::string& portfolioName){
    for (auto it = portfolios.begin(); it != portfolios.end(); ++it){
        if (it->getPortfolioName() == portfolioName){
            portfolios.erase(it);
            return;
        }
    }
}

Portfolio* Client::getPortfolio(const std::string& portfolioName){
    for (auto& portfolio : portfolios) {
        if (portfolio.getPortfolioName() == portfolioName) {
            return &portfolio;
        }
    }
    return nullptr;
}

void Client::viewAllPortfolios(){
    (void)portfolios;
}

std::string Client::getName() const {
    return name;
}

int Client::getId() const {
    return id;
}
