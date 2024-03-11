project(lvgl_qt)

set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB_RECURSE SOURCES "*.c" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
        lvgl
        Qt5::Core
        Qt5::Widgets
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})
