#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ViewModel/StockViewModel.h"

using ::testing::Return;
using ::Service::INetworkService;
using ::HanyoungparkClient::NetworkService::INetworkService;

class NetworkServiceMock: public INetworkService {
public:
    MOCK_METHOD(int, getStock, (const std::string& symbol), (const, override));
    MOCK_METHOD(rxcpp::observable<int>, requestStock, (const std::string& symbol), (const, override));
};

TEST(StockViewModelUnitText, DummyTest) {
    NetworkServiceMock networkServiceMock;
    auto stockViewModel =
            new StockViewModel(static_cast<std::shared_ptr<INetworkService>>(&networkServiceMock));
    EXPECT_CALL(networkServiceMock, getStock("KRW")).Times(1).WillRepeatedly(Return(30));
    EXPECT_EQ(30, stockViewModel->getStock("KRW"));
}


