cmake_minimum_required(VERSION 3.16)

project(ApplesGame
        VERSION 1.0.0
        LANGUAGES CXX)

if(CMAKE_GENERATOR STREQUAL "Ninja"
     AND CMAKE_VERSION VERSION_GREATER_EQUAL 3.24)
  set(CMAKE_COLOR_DIAGNOSTICS On) 
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS Off)

set(PRJ_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PRJ_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# move to differen directory later
set(SRC_FILES 
      ${PRJ_SRC_DIR}/Apple.cpp
      ${PRJ_SRC_DIR}/Engine.cpp
      ${PRJ_SRC_DIR}/Game.cpp
      ${PRJ_SRC_DIR}/Menu.cpp
      ${PRJ_SRC_DIR}/Player.cpp
      ${PRJ_SRC_DIR}/Resources.cpp
      ${PRJ_SRC_DIR}/Rock.cpp
      ${PRJ_SRC_DIR}/Settings.cpp
      ${PRJ_SRC_DIR}/UI.cpp)

add_executable(ApplesGame
                ${CMAKE_CURRENT_SOURCE_DIR}/MainGame.cpp)

target_sources(ApplesGame
                PRIVATE ${SRC_FILES})

target_include_directories(ApplesGame
                            PRIVATE ${PRJ_INCLUDE_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

target_link_libraries(ApplesGame
                        PRIVATE
                          sfml-graphics
                          sfml-window
                          sfml-audio
                          sfml-system)

if(WIN32)
    add_custom_command(
        TARGET ApplesGame
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:ApplesGame>
        VERBATIM)
endif()

install(TARGETS ApplesGame)
