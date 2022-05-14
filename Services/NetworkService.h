//
// Created by HANYOUNG PARK on 5/13/22.
//

#ifndef RXCPP_NETWORKSERVICE_H
#define RXCPP_NETWORKSERVICE_H

#include "INetworkService.h"

namespace HanyoungparkClient::NetworkService {
    class NetworkService: public INetworkService {
    public:
        NetworkService();
        ~NetworkService() override;

        [[nodiscard]] int getStock(const std::string& symbol) const override;
    };
} // NetworkService::NetworkService

#endif //RXCPP_NETWORKSERVICE_H
