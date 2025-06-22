qt_add_executable(qtanswer
    main.cc
    gamewindow.cc
    boardwidget.cc
    cluewidget.cc
    player.cc
    tile.cc
    buzzer.cc
    cluefile.cc
    startwidget.cc
)
target_link_libraries(qtanswer PRIVATE Qt6::Widgets)

set_target_properties(qtanswer PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_custom_command(
    TARGET qtanswer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/categories.json
            ${CMAKE_CURRENT_BINARY_DIR}/categories.json
)
