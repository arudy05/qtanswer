find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(qtanswer
    main.cc
    gamewindow.cc
    mainwindow.cc
)
target_link_libraries(qtanswer PRIVATE Qt6::Widgets)

set_target_properties(qtanswer PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
