project(test)
add_executable(test_run StockViewModelTest.cpp)
target_link_libraries(test_run src)
target_link_libraries(test_run ${CONAN_LIBS})