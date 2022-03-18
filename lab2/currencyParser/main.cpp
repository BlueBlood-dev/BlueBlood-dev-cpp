#include <iostream>
#include <curl/curl.h>
#include "nlohmann\json.hpp"
#include <sys/unistd.h>
#include "GetRequest.cpp"

void printMedium(std::map<std::string, std::vector<double>> dataStorage) {
    for (auto currency: dataStorage) {
        std::sort(currency.second.begin(), currency.second.end());
        std::cout << "Medium for " << currency.first << " is " << currency.second[currency.second.size() / 2]
                  << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;
}

void printAverage(std::map<std::string, std::vector<double>> dataStorage) {
    for (auto currency: dataStorage) {
        double sum = 0;
        for (auto value: currency.second)
            sum += value;
        std::cout << "Average for " << currency.first << " is " << sum / currency.second.size() << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;
}


int main() {
    std::map<std::string, std::vector<double>> currencyHandler;
    std::cout << "Enter the period, u want to make requests\n";
    int period;
    std::cin >> period;
    try {
        if (period < 10)
            throw std::invalid_argument("period should be bigger than 10 secs");
        if (period % 10 != 0)
            period -= period % 10;

        while (period) {
            nlohmann::json currencies = nlohmann::json::parse(
                    GetRequest("https://www.cbr-xml-daily.ru/daily_json.js").getJson());

            for (const auto &value: currencies["Valute"]) {
                currencyHandler[value["Name"].get<std::string>()].push_back(
                        value["Value"].get<double>() / value["Nominal"].get<int>());
                std::cout << value["Name"].get<std::string>() << " стоит "
                          << value["Value"].get<double>() / value["Nominal"].get<int>() << " рублей\n";
            }
            period -= 10;

            std::cout << "-----------------------------------------------------------------\n";
            if (period)//else sleeping after all requests are made when period is already zero
                sleep(10);
        }
    } catch (std::exception &exp) {
        std::cout << exp.what() << std::endl;
    }

    printMedium(currencyHandler);
    printAverage(currencyHandler);
}
