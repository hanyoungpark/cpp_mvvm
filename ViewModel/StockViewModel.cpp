#include "StockViewModel.h"

#include <iostream>
#include <utility>

StockViewModel::StockViewModel(std::shared_ptr<Service::INetworkService> networkService)
    : networkService(std::move(networkService)) {
}

[[nodiscard]] int StockViewModel::getStock(const std::string& symbol) const {
    return networkService->getStock(symbol);
}

void StockViewModel::executeDummyObserver() {
    networkService->requestStock("USD").subscribe([](int price) {
        std::cout << std::endl << "Async Price: " << price << std::endl;
    },
    [](){
        std::cout << "Completed" << std::endl;
    });
}
