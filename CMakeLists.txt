cmake_minimum_required(VERSION 3.5.1)
add_compile_options(-W -Wall -Werror -Wno-unused-function)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_powermod test_powermod.cpp powermod.c)
#add_executable(main_powermod main_powermod.cpp powermod.c)
target_link_libraries(test_powermod GTest::GTest GTest::Main)
add_test(AllTestsInPowermod test_powermod)

add_executable(test_contains test_contains.cpp contains.c)
#add_executable(main_contains main_contains.cpp contains.c)
target_link_libraries(test_contains GTest::GTest GTest::Main)
add_test(AllTestsInContains test_contains)

add_executable(test_sort test_sort.cpp sort.c)
#add_executable(main_sort main_sort.cpp sort.c)
target_link_libraries(test_sort GTest::GTest GTest::Main)
add_test(AllTestsInSort test_sort)

