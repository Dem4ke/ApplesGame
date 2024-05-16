set(SRC_FILES 
      Apple.cpp
      Engine.cpp
      Game.cpp
      Menu.cpp
      Player.cpp
      Resources.cpp
      Rock.cpp
      Settings.cpp
      UI.cpp
)

target_sources(ApplesGame
                PRIVATE ${SRC_FILES})
