
project(screen)

set(CMAKE_AUTOMOC ON)


find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB_RECURSE SRC_FILES "*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        lvgl_qt
        gui_demos
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/z_bin
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/z_bin
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/z_bin
)