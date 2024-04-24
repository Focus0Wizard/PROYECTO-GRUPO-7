# CMakeList.txt : CMake project for proyecto, include source and define
# project specific logic here.
#

# Create BIN file
set(BIN proyecto)

# Copy configuration to build directory
file(COPY "${CMAKE_SOURCE_DIR}/proyecto/config" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# Enable FetchContent
include(FetchContent)

# Include header files
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add .cpp and .h files to this project
file(GLOB_RECURSE INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.*)
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

######################### spdlog
message("######################### Downloading spdlog library")
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.12.0
)
FetchContent_GetProperties(spdlog)
if (NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    set(CMAKE_BUILD_TYPE Release CACHE INTERNAL "Build type Release")
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR} EXCLUDE_FROM_ALL)
    include_directories(${spdlog_SOURCE_DIR}/include/)
endif ()
######################### spdlog

######################### nlohmann
message("######################### Downloading nlohmann library")
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.2
)
FetchContent_GetProperties(json)
if (NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
    include_directories(${json_SOURCE_DIR}/include/)
endif ()
######################### nlohmann

# Add source to this project's executable
add_executable(${BIN} ${INC_FILES} ${SRC_FILES})

# Link external libraries to this project's executable
target_link_libraries(${BIN} PRIVATE nlohmann_json::nlohmann_json spdlog::spdlog)

# Enable C++20
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ${BIN} PROPERTY CXX_STANDARD 20)
endif()
