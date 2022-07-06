cmake_minimum_required(VERSION 3.18) 

project(string_sending)

include_directories(./)

add_executable(serverexec server/server.cpp server/server_main.cpp socket/socket.cpp check_functions.cpp)
add_executable(clientexec client/client.cpp client/client_main.cpp socket/socket.cpp check_functions.cpp)

if(WIN32)
     target_link_libraries(serverexec wsock32 ws2_32)
     target_link_libraries(clientexec wsock32 ws2_32)
endif()
