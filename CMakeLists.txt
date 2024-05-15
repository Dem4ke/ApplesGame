cmake_minimum_required(VERSION 3.12)

project(ApplesGame
        LANGUAGES CXX)

if(CMAKE_GENERATOR STREQUAL "Ninja"
     AND CMAKE_VERSION VERSION_GREATER_EQUAL 3.24)
  set(CMAKE_COLOR_DIAGNOSTICS On) 
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS Off)

set(PRJ_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PRJ_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(ApplesGame
               ${CMAKE_CURRENT_SOURCE_DIR}/MainGame.cpp)
target_sources(ApplesGame
                PRIVATE
                  ${PRJ_SRC_DIR}/Apple.cpp
                  ${PRJ_SRC_DIR}/Engine.cpp
                  ${PRJ_SRC_DIR}/Game.cpp
                  ${PRJ_SRC_DIR}/Menu.cpp
                  ${PRJ_SRC_DIR}/Player.cpp
                  ${PRJ_SRC_DIR}/Resources.cpp
                  ${PRJ_SRC_DIR}/Rock.cpp
                  ${PRJ_SRC_DIR}/Settings.cpp
                  ${PRJ_SRC_DIR}/UI.cpp)

target_include_directories(ApplesGame
                            PRIVATE ${PRJ_INCLUDE_DIR})

if(WIN32)
  target_link_libraries(ApplesGame
                        ${CMAKE_CURRENT_SOURCE_DIR}/lib/openal32.dll)
endif()
