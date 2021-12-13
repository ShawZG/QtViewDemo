//
// Created by xiao on 12/8/21.
//

#include "ColorItemModel.h"
#include <QDebug>

ColorItemModel::ColorItemModel(QObject *parent) : QAbstractItemModel(parent) {
}

ColorItemModel::~ColorItemModel() {
    qDeleteAll(colorList);
    colorList.clear();
}

QModelIndex ColorItemModel::index(int row, int column, const QModelIndex &parent) const {
    if (row < 0 || row >= colorList.size() || column != 0) {
        return {};
    }
    auto color = colorList.at(row);
    return createIndex(row, column, color);
}

QModelIndex ColorItemModel::parent(const QModelIndex &child) const {
    return {};
}

int ColorItemModel::rowCount(const QModelIndex &parent) const {
    return colorList.size();
}

int ColorItemModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

bool ColorItemModel::hasChildren(const QModelIndex &parent) const {
    return false;
}

QVariant ColorItemModel::data(const QModelIndex &index, int role) const {
//    if (Qt::BackgroundRole == role) {
//        auto color = static_cast<QColor*>(index.internalPointer());
//        return QVariant(*color);
//    } else {
//        return {};
//    }
    return {};
}

Qt::ItemFlags ColorItemModel::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |= Qt::ItemIsEnabled;
    return flags;
}

bool ColorItemModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractItemModel::setData(index, value, role);
}

void ColorItemModel::setColorList(QList<QColor*> colors) {
    colorList = std::move(colors);
}
