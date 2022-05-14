#include <iostream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/node.hpp>

#include "Services/NetworkService.h"

using namespace HanyoungparkClient::NetworkService;

int main() {
    using namespace ftxui;

    // NetworkService Test
    std::unique_ptr<INetworkService> pNetworkService(new NetworkService());
    auto document = hbox({
        vbox({text("Stock Price")}) | border,
        vbox({text(std::to_string(pNetworkService->getStock("USD")))}) | border,
    });
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    screen.Print();

    return 0;
}
