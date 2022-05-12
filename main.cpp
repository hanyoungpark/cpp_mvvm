#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "ftxui/dom/node.hpp"

int main() {
    using namespace ftxui;
    auto document =
        hbox({
            vbox({
                text("Line 1"),
                text("Line 2"),
                text("Line 3"),
                }) | border,
            vbox({
                text("Line 4"),
                text("Line 5"),
                text("Line 6"),
            }) | border,
            vbox({
                text("Line 7"),
                text("Line 8"),
                text("Line 9"),
            }) | border,
        });
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    screen.Print();
    return 0;
}
