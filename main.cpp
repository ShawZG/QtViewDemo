#include <QApplication>
#include <QLayout>
#include <QTabWidget>
#include "tree_view/UrlTreeView.h"
#include "list_view/ColorListView.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTabWidget tabWidget;
    tabWidget.addTab(new UrlTreeView, "TreeView");
    tabWidget.addTab(new ColorListView(), "ListView");
    tabWidget.addTab(new QWidget(), "TableView");

    tabWidget.show();

    return QApplication::exec();
}
