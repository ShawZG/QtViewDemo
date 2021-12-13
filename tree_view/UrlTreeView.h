//
// Created by xiao on 2021/9/28.
//

#ifndef URLTREEVIEWDEMO_URLTREEVIEW_H
#define URLTREEVIEWDEMO_URLTREEVIEW_H

#include <QTreeView>
#include <QStandardItemModel>

class UrlTreeView : public QTreeView {
Q_OBJECT
public:
    explicit UrlTreeView(QWidget *parent = nullptr);

private:
    void initTreeView();
};

#endif //URLTREEVIEWDEMO_URLTREEVIEW_H
