#include "stock.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int Stock::diversificationCount = 0;


// helper to hanfle the data stream from the curl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s){
    size_t newLength = size * nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

Stock::Stock(std::string ticker, double stockCount, int avgSharePrice)
    :ticker(ticker), avgSharePrice(avgSharePrice), stockCount(stockCount), currSharePrice(0.0), totalValue(0.0), valueChange(0.0), lastUpdateTime(0), PriceInitialized(false){
        diversificationCount++;
    }
Stock::~Stock(){
    diversificationCount--;
}

//lazy load helpers
void Stock::ensurePriceLoaded({
    if (!priceInitialized || isCacheExpired()){
        refreshPrice();
    }
}

time_t Stock::getLastUpdateTime(){
    return lastUpdateTime;
}

bool Stock::isPriceInitialized() const {
    return priceInitialized;
}

bool Stock::isCacheExpired() const{
    return (std::time(nullptr) - lastUpdateTime) > CACHE_DURATION_SEC;
}


//API call 
void Stock::refreshPrice(){
    CURL* curl = curl_easy_init();
    if(curl){
        std::string readBuffer;
        //will retrieve api key from .secret file
        std::string apiKey = "";
        std::string url = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + ticker + "&apiKey=" + apiKey;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        //try
        auto data = json::parse(readBuffer);
        std::string priceStr = data["Global Quote"]["05. price"];

        //if !pricestr.empty 
        currSharePrice = std::stod(priceStr);
        lastUpdateTime = std::time(nullptr);
        priceInitialized = true;

    }
}

void Stock::calcTotalValue(){
    totalValue = currPrice * stockCount;
}

int Stock::getStockinPortfolioNum(){
    return stocksinPortfolioNum;
}

std::string Stock::getTicker(){
    return ticker;
}
double Stock::getAvgStockPrice(){
    return avgStockPrice;
}

int Stock::getStockCount(){
    return stockCount;
}

double Stock::getValueChange(){
    ensurePriceLoaded();
    return (currSharePrice - avgSharePrice) * stockCount;
}

double Stock::getPercentChange(){
    ensurePriceLoaded()
    return (currSharePrice/avgSharePrice) - 1;
}

//TODO: void setNumOfShares(int), void setAvgShare(double)

void Stock::display() const{
    ensurePriceLoaded();
    std::cout << "Ticker: " << getTicker() << std::endl;
    std::cout << "Average Stock Price: " << getAvgStockPrice() << std::endl;
    std::cout << "Stock Count: " << getStockCount() << std::endl;
    std::cout << "Total Value: " << calcTotalValue() << std::endl;
    std::cout << "Value Change: " << getValueChange() << std::endl;
    std::cout << "Percent Change: " << getPercentChange() << std::endl;
}



