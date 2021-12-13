//
// Created by xiao on 2021/9/28.
//

#include "UrlItemModel.h"

#include <utility>
#include "UrlItem.h"

#include <QDebug>

UrlItemModel::UrlItemModel(QObject *parent) : QAbstractItemModel(parent)
{
}

UrlItemModel::~UrlItemModel()
{
    delete rootItem;
}

QModelIndex UrlItemModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!rootItem || row < 0 || column < 0) {
        return {};
    }
    UrlItem *parentItem = itemFromIndex(parent);
    UrlItem *childItem = parentItem->childrenUrlItems.value(row);
    // 如果子存在则返回子的下标，若子不存在则返回空
    return childItem ? createIndex(row, column, childItem) : QModelIndex();
}

UrlItem *UrlItemModel::itemFromIndex(const QModelIndex &index) const
{
    if (index.isValid()) {
        return static_cast<UrlItem *>(index.internalPointer());
    } else {
        return rootItem;
    }
}

int UrlItemModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0) {
        return 0;
    }
    UrlItem *parentItem = itemFromIndex(parent);
    return parentItem ? parentItem->childrenUrlItems.count() : 0;
}

int UrlItemModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QModelIndex UrlItemModel::parent(const QModelIndex &child) const
{
    UrlItem *childItem = itemFromIndex(child);
    if (!childItem) {
        return {};
    }

    UrlItem *parentItem = childItem->parent;
    if (!parentItem) {
        return {};
    }
    //NOTE 此处为何需要判断祖父指针是否存在？
    UrlItem *grandparentItem = parentItem->parent;
    if (!grandparentItem) {
        return {};
    }

    int row = grandparentItem->childrenUrlItems.indexOf(parentItem);
    return createIndex(row, 0, parentItem);
}

bool UrlItemModel::hasChildren(const QModelIndex &parent) const
{
    UrlItem *parentItem = itemFromIndex(parent);
    if (parentItem && parentItem->childrenUrlItems.count() > 0) {
        return true;
    } else {
        return false;
    }
}

QVariant UrlItemModel::data(const QModelIndex &index, int role) const
{
    return {};
}

bool UrlItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return QAbstractItemModel::setData(index, value, role);
}

Qt::ItemFlags UrlItemModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |= Qt::ItemIsEnabled;
    return flags;
}

void UrlItemModel::setRootItem(UrlItem *rootUrlItem)
{
    delete rootItem;
    rootItem = rootUrlItem;
}
