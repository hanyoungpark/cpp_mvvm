#include <gtest/gtest.h>
#include "ViewModel/StockViewModel.h"

TEST(StockViewModelUnitText, DummyTest) {
    auto stockViewModel = new StockViewModel(nullptr);
    EXPECT_EQ(5, stockViewModel->test());
}
