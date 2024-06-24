cmake_minimum_required(VERSION 3.5)

project(hhClientTCP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(tcp)
add_executable(hhClientTCP main.cpp)
target_link_libraries(hhClientTCP PRIVATE TCP)

include(GNUInstallDirs)
install(TARGETS hhClientTCP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(
    hhClientTCP PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tcp
)
