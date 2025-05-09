cmake_minimum_required(VERSION 3.30)
project(FEUP_DA_PROJECT_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(FEUP_DA_PROJECT_2 main.cpp
        cli/CLI.cpp
        cli/CLI.h
        cli/CommandRegistry.cpp
        cli/CommandRegistry.h
        context/Context.h
        commands/Command.cpp
        commands/Command.h
        commands/ReadFromFile.cpp
        commands/ReadFromFile.h
        csv_parser/CSVParser.cpp
        csv_parser/CSVParser.h
        data_structures/TruckProblemInstance.cpp
        data_structures/TruckProblemInstance.h
        commands/CreateProblemInstance.cpp
        commands/CreateProblemInstance.h
)
