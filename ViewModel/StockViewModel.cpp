#include "StockViewModel.h"

#include <utility>

StockViewModel::StockViewModel(std::shared_ptr<Service::INetworkService> networkService)
    : networkService(std::move(networkService)) {
}

[[nodiscard]] int StockViewModel::getStock(const std::string& symbol) const {
    return networkService->getStock(symbol);
}
