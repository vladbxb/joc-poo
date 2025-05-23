cmake_minimum_required(VERSION 3.28)
project(Joc_POO LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(include)

add_executable(main
	src/main.cpp
	src/Game.cpp
	src/InputHandlers.cpp
	src/InputManager.cpp
	src/Boat.cpp
	src/Rope.cpp
	src/TubePos.cpp
	src/Tube.cpp
	src/Player.cpp
	src/obstacles/Obstacle.cpp
	src/obstacles/Buoy.cpp
	src/obstacles/Rock.cpp
	src/obstacles/ObstacleSpawner.cpp
	src/obstacles/ObstacleManager.cpp
	src/CollisionManager.cpp
	src/math/MathFormulas.cpp
	src/graphics/LineSegment.cpp
	src/TubeTrail.cpp
	src/hud/HUD.cpp
	src/hud/Score.cpp
	src/hud/Lives.cpp
	src/states/PlayState.cpp
	src/states/EndState.cpp
	src/states/StartState.cpp
	src/buttons/PlayButton.cpp
	src/buttons/RectangularButton.cpp
	src/buttons/RestartButton.cpp
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE sfml-graphics)
