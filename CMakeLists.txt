cmake_minimum_required(VERSION 3.16)

project(ApplesGame
        VERSION 1.0.0
        LANGUAGES CXX)

if((CMAKE_GENERATOR STREQUAL "Ninja")
   AND (CMAKE_VERSION VERSION_GREATER_EQUAL 3.24))
  set(CMAKE_COLOR_DIAGNOSTICS On) 
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS Off)

set(PRJ_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PRJ_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(ApplesGame
                ${CMAKE_CURRENT_SOURCE_DIR}/MainGame.cpp)

add_subdirectory(${PRJ_SRC_DIR})

target_include_directories(ApplesGame
                            PRIVATE ${PRJ_INCLUDE_DIR})

if(NOT DEFINED PRJ_SFML_VERSION)
  set(PRJ_SFML_VERSION 2.6.x)
endif()

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG ${PRJ_SFML_VERSION})
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
