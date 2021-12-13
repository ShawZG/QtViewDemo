//
// Created by xiao on 2021/9/28.
//

#ifndef URLTREEVIEWDEMO_URLITEMDELEGATE_H
#define URLTREEVIEWDEMO_URLITEMDELEGATE_H

#include <QStyledItemDelegate>

class UrlItemDelegate : public QStyledItemDelegate {
public:
    explicit UrlItemDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif //URLTREEVIEWDEMO_URLITEMDELEGATE_H
