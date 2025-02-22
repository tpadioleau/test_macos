cmake_minimum_required(VERSION 3.22)

project(test LANGUAGES CXX)

find_package(Kokkos REQUIRED)
find_package(PDI REQUIRED COMPONENTS C)
find_package(paraconf REQUIRED COMPONENTS C)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC Kokkos::kokkos paraconf::paraconf PDI::PDI_C)

install(TARGETS main RUNTIME DESTINATION bin)
