//
// Created by xiao on 2021/9/28.
//

#ifndef URLTREEVIEWDEMO_URLITEMMODEL_H
#define URLTREEVIEWDEMO_URLITEMMODEL_H

#include <QStandardItemModel>

class UrlItem;

class UrlItemModel : public QAbstractItemModel {
public:
    explicit UrlItemModel(QObject *parent = nullptr);
    ~UrlItemModel() override;

    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    bool hasChildren(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void setRootItem(UrlItem *rootUrlItem);

private:
    UrlItem* itemFromIndex(const QModelIndex &index) const;

    UrlItem* rootItem = nullptr;
};

#endif //URLTREEVIEWDEMO_URLITEMMODEL_H
