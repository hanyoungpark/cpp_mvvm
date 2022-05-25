project(src)
set(HEADER_FILES Services/INetworkService.h Services/NetworkService.h ViewModel/StockViewModel.h)
set(SOURCE_FILES Services/NetworkService.cpp ViewModel/StockViewModel.cpp)
add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})