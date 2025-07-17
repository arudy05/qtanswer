qt_add_library(boardwidget STATIC
    boardwidget.cc)
qt_add_library(cluewidget STATIC
    cluewidget.cc)
qt_add_library(resultswidget STATIC
    resultswidget.cc)
qt_add_library(startwidget STATIC
    startwidget.cc)

target_link_libraries(boardwidget PRIVATE Qt6::Widgets tile player)
target_link_libraries(cluewidget PRIVATE Qt6::Widgets buzzer)
target_link_libraries(resultswidget PRIVATE Qt6::Widgets player)
target_link_libraries(startwidget PRIVATE Qt6::Widgets cluefile)

target_include_directories(boardwidget INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(cluewidget INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(resultswidget INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(startwidget INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(qtanswer PRIVATE
    boardwidget
    cluewidget
    resultswidget
    startwidget)
