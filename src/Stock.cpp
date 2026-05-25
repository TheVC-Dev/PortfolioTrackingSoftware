#include "Stock.h"
#include <iostream>
//#include <curl/curl.h>
//#include <nlohmann/json.hpp>

//using json = nlohmann::json;

int Stock::diversificationCount = 0;

// helper to hanfle the data stream from the curl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s){
    size_t newLength = size * nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

Stock::Stock(std::string ticker, int NumOfShares, double avgSharePrice)
    :ticker(ticker), avgSharePrice(avgSharePrice), currSharePrice(0.0), lastUpdateTime(0), priceInitialized(false){
        diversificationCount++;
    }
Stock::~Stock(){
    diversificationCount--;
}

//lazy load helpers
void Stock::ensurePriceLoaded(){
    if(!priceInitialized || isCacheExpired()){
        refreshPrice();
    }
}


//API call 
void Stock::refreshPrice(){
    /*
     * TODO:
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
    */
}

bool Stock::isPriceInitialized() const {
    return priceInitialized;
}

bool Stock::isCacheExpired() const{
    return (std::time(nullptr) - lastUpdateTime) > CACHE_DURATION_SEC;
}

// getters ////////////////

double Stock::getTotalValue(){
    return 0.0;
}

double Stock::getValueChange(){
    //TODO:
    //ensurePriceLoaded();
    //return (currSharePrice - avgSharePrice) * stockCount;
    return 0.0;
}

double Stock::getPercentChange(){
    //TODO:
    //ensurePriceLoaded()
    //return (currSharePrice/avgSharePrice) - 1;
    return 0.0;
}

std::string Stock::getTicker() const {
    return ticker;
}

int Stock::getNumOfShares() const {
    return numOfShares;
}

double Stock::getAvgSharePrice() const {
    return avgSharePrice;
}

double Stock::getCurrSharePrice(){
    return 0.0;
}

//setters ////////////////
void Stock::setNumOfShares(int shares) {
    (void)shares;
}

void Stock::setAvgShare(double price){
    (void)price;
}


void Stock::display(){
    ensurePriceLoaded();
    std::cout << "Ticker: " << getTicker() << std::endl;
};
