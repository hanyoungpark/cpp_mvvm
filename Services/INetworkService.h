//
// Created by HANYOUNG PARK on 5/13/22.
//

#ifndef RXCPP_INETWORKSERVICE_H
#define RXCPP_INETWORKSERVICE_H

#include <string>

namespace HanyoungparkClient::NetworkService{
    struct INetworkService {
    public:
        INetworkService() = default;
        virtual ~INetworkService() = default;
        [[nodiscard]] virtual int getStock(const std::string& symbol) const = 0;
    };
} // NetworkService::HanyoungparkClient

#endif //RXCPP_INETWORKSERVICE_H
