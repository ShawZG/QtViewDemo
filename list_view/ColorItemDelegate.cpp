//
// Created by xiao on 12/8/21.
//

#include "ColorItemDelegate.h"
#include <QPainter>
#include <QDebug>
ColorItemDelegate::ColorItemDelegate(QObject *parent) : QStyledItemDelegate(parent) {
}

void ColorItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.isValid()) {
        auto color = static_cast<QColor*>(index.internalPointer());
        painter->setBrush(*color);
        painter->drawRoundedRect(option.rect, 6, 6);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize ColorItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    return index.isValid() ? QSize(200, 60) : QSize();
}
