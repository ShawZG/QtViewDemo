//
// Created by xiao on 12/8/21.
//

#include "ColorListView.h"
#include "ColorItemModel.h"
#include "ColorItemDelegate.h"

ColorListView::ColorListView(QWidget *parent) : QListView(parent) {
    initListView();
}

void ColorListView::initListView() {
    auto model = new ColorItemModel(this);
    model->setColorList({new QColor(Qt::red),
                         new QColor(Qt::blue),
                         new QColor(Qt::green),
                         new QColor(Qt::gray)});

    setModel(model);
    auto delegate = new ColorItemDelegate(this);
    setItemDelegate(delegate);
}

void ColorListView::paintEvent(QPaintEvent *e) {
    QListView::paintEvent(e);
}
