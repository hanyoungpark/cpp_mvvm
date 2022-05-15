#ifndef RXCPP_STOCKVIEWMODEL_H
#define RXCPP_STOCKVIEWMODEL_H

#include <iostream>
#include <string>
#include "../Services/INetworkService.h"

namespace Service = HanyoungparkClient::NetworkService;

class StockViewModel {
public:
    explicit StockViewModel(std::shared_ptr<Service::INetworkService> networkService);
    [[nodiscard]] int getStock(const std::string& symbol) const;

private:
    std::shared_ptr<Service::INetworkService> networkService;
};


#endif //RXCPP_STOCKVIEWMODEL_H
