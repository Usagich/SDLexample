# Project configuration.

set(PROJECT_TITLE "SDLexample")

set(project_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

set(UID3     0x1000abc1) # game.exe UID
set(APP_UID  0x1000abc2) # launcher.app UID
set(APP_NAME "Example")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/frame.bmp ${CMAKE_CURRENT_SOURCE_DIR}/export COPYONLY)
