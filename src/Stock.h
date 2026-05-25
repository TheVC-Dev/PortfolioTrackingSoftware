#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <ctime>

class Stock{
private:
    static int diversificationCount;
    static const int CACHE_DURATION_SEC = 1800; //30min

    std::string ticker;
    int numOfShares;
    double avgSharePrice;

    double currSharePrice;
    time_t lastUpdateTime;
    bool priceInitialized;

public:
    Stock(std::string ticker, int numOfShares, double avgSharesPrice);
    ~Stock();

    void ensurePriceLoaded();
    void refreshPrice();
    
    //lazy load helpers
    bool isCacheExpired() const;
    bool isPriceInitialized() const;

    //math metrics (call ensurePriceLoaded inside)
    double getTotalValue();
    double getValueChange(); 
    double getPercentChange();

    //getters and setters for modification
    std::string getTicker() const;
    int getNumOfShares() const;
    double getAvgSharePrice() const;
    double getCurrSharePrice();

    void setNumOfShares(int shares);
    void setAvgShare(double price);

    void display();
};
#endif
