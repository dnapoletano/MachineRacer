set(Utils_SOURCES
  Vector2D.cpp
)

add_library(Utils ${Utils_SOURCES})
target_include_directories(Utils PUBLIC ${LOCAL_INCLUDE_DIRS})
set_target_properties(Utils PROPERTIES PREFIX "libTwoDEngine")