#include <iostream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/node.hpp>
#include <boost/di.hpp>

#include <thread>

#include "Services/NetworkService.h"
#include "ViewModel/StockViewModel.h"

using namespace HanyoungparkClient::NetworkService;
using namespace ftxui;
namespace di = boost::di;
namespace rx = rxcpp;

int main() {
    const auto injector = di::make_injector(di::bind<INetworkService>.to<NetworkService>());
    const auto viewModel = injector.create<std::unique_ptr<StockViewModel>>();

    auto document = hbox({
        vbox({text("Stock Price")}) | border,
        vbox({text(std::to_string(viewModel->getStock("USD")))}) | border,
    });
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    screen.Print();

    viewModel->executeDummyObserver();
    std::this_thread::sleep_for (std::chrono::seconds(1000));

    return 0;
}
