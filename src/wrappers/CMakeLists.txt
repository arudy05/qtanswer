qt_add_library(buzzer STATIC
    buzzer.cc)
qt_add_library(cluefile STATIC
    cluefile.cc)
qt_add_library(player STATIC
    player.cc)
qt_add_library(tile STATIC
    tile.cc)


target_link_libraries(buzzer PRIVATE Qt6::Widgets)
target_link_libraries(cluefile PRIVATE Qt6::Widgets nlohmann_json::nlohmann_json)
target_link_libraries(player PRIVATE Qt6::Widgets)
target_link_libraries(tile PRIVATE Qt6::Widgets)

target_include_directories(buzzer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(cluefile INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(player INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(tile INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(qtanswer PRIVATE
    buzzer
    cluefile
    player
    tile)
