set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_library(tree_view_object OBJECT "")
target_sources(tree_view_object PRIVATE UrlTreeView.cpp UrlItemModel.cpp UrlItemDelegate.cpp UrlItem.cpp)
target_link_libraries(tree_view_object PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)