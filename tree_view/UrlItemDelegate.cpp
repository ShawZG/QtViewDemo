//
// Created by xiao on 2021/9/28.
//

#include "UrlItemDelegate.h"
#include "UrlItem.h"

#include <QPainter>
//#include <QApplication>

UrlItemDelegate::UrlItemDelegate(QObject *parent) : QStyledItemDelegate(parent) {
}

void UrlItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        return;
    }
    auto *item = static_cast<UrlItem*>(index.internalPointer());
    if (!item || UrlItem::Unknown == item->type) {
        return;
    }

    // 调整缩进宽度
    int indentWidth = 10;
    auto tmpIndex = index;
    while (tmpIndex.parent().isValid()) {
        indentWidth += 50;
        tmpIndex = tmpIndex.parent();
    }

    auto backgroundRect = option.rect.adjusted(2, 2, -2, -2);
    painter->fillRect(backgroundRect, Qt::gray);

    auto nameRect = QRect(option.rect.topLeft().x() + indentWidth, option.rect.topLeft().y() + 5,
                          option.rect.width() - indentWidth, (option.rect.height() - 5) / 2);
    painter->drawText(nameRect, item->name);

    auto detailRect = QRect(nameRect.bottomLeft().x(), nameRect.bottomLeft().y() + 5,
                            nameRect.width(), nameRect.height());
    painter->drawText(detailRect, item->detail);
}

QSize UrlItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return index.isValid() ? QSize(200, 60) : QSize();
}
