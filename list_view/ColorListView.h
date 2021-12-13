//
// Created by xiao on 12/8/21.
//

#ifndef VIEWDEMO_COLORLISTVIEW_H
#define VIEWDEMO_COLORLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>

class ColorListView : public QListView {
Q_OBJECT
public:
    explicit ColorListView(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e) override;
private:
    void initListView();
};

#endif //VIEWDEMO_COLORLISTVIEW_H
