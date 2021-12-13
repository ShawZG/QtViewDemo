set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_library(list_view_object OBJECT "")
target_sources(list_view_object PRIVATE ColorListView.cpp ColorItemModel.cpp ColorItemDelegate.cpp)
target_link_libraries(list_view_object PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)