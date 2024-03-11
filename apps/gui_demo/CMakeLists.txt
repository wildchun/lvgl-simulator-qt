project(gui_demos)

file(GLOB_RECURSE SRC_FILES "*.cpp")

add_library(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
        lvgl)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})