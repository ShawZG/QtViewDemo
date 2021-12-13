//
// Created by xiao on 2021/9/28.
//

#include "UrlItem.h"

#include <utility>

UrlItem::~UrlItem() {
    qDeleteAll(childrenUrlItems);
    childrenUrlItems.clear();
}

UrlItem::UrlItem(UrlItem::ItemType itemType, QString itemName, QString itemDetail)
    : type(itemType), name(std::move(itemName)), detail(std::move(itemDetail))
{
}
