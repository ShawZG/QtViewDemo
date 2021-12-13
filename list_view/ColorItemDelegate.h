//
// Created by xiao on 12/8/21.
//

#ifndef VIEWDEMO_COLORITEMDELEGATE_H
#define VIEWDEMO_COLORITEMDELEGATE_H

#include <QStyledItemDelegate>

class ColorItemDelegate : public QStyledItemDelegate {
public:
    explicit ColorItemDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif //VIEWDEMO_COLORITEMDELEGATE_H
