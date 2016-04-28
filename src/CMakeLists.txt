add_subdirectory(errors)
add_subdirectory(game_objects)
add_subdirectory(scenes)
add_subdirectory(sdl)

add_executable(SdlGame main.cpp ${SOURCEFILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)

target_link_libraries(SdlGame
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
)