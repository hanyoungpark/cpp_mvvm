project(test)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conan_build/conanbuildinfo.cmake)
    message("conan setup")
    include(${CMAKE_CURRENT_SOURCE_DIR}/conan_build/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_executable(test_run StockViewModelTest.cpp)
target_link_libraries(test_run src)
target_link_libraries(test_run ${CONAN_LIBS})