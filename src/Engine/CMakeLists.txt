set(Engine_SOURCES
  Engine.cpp
)

include_directories(${SDL_Include})
link_directories(${SDL_Library_Path})
link_libraries(SDL2 SDL2_image)
add_library(Engine ${Engine_SOURCES})

target_include_directories(Engine PUBLIC ${LOCAL_INCLUDE_DIRS})

set_target_properties(Engine PROPERTIES PREFIX "libTwoDEngine")
# target_link_libraries(Engine PUBLIC Utils)
target_link_libraries(Engine PUBLIC Components)