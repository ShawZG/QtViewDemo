//
// Created by xiao on 2021/9/28.
//

#ifndef URLTREEVIEWDEMO_URLITEM_H
#define URLTREEVIEWDEMO_URLITEM_H

#include <QString>
#include <QList>
#include <QRect>

class UrlItem {
public:
    enum ItemType {Unknown, Dir, Url};

    explicit UrlItem(ItemType itemType, QString itemName, QString itemDetail);
    ~UrlItem();

    QString name;
    QString detail;
    ItemType type = ItemType::Unknown;

    UrlItem *parent = nullptr;
    QList<UrlItem *> childrenUrlItems;
};

#endif //URLTREEVIEWDEMO_URLITEM_H
//