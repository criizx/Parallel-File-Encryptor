cmake_minimum_required(VERSION 4.0)
project(Parallel_File_Encryptor)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/app/include/)

add_executable(Parallel_File_Encryptor
        main.cpp
        src/app/src/fileHandling/IO.cpp
        src/app/include/fileHandling/envReader.h
        src/app/src/processes/ProcessManagment.cpp
        src/app/include/processes/ProcessManagment.h
        src/app/include/processes/Task.h
)