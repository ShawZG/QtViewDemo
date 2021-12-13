//
// Created by xiao on 12/8/21.
//

#ifndef VIEWDEMO_COLORITEMMODEL_H
#define VIEWDEMO_COLORITEMMODEL_H

#include <QStandardItemModel>
#include <QColor>
#include <QList>

class ColorItemModel : public QAbstractItemModel {
public:
    explicit ColorItemModel(QObject *parent = nullptr);
    ~ColorItemModel() override;

    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    bool hasChildren(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void setColorList(QList<QColor*> colors);

private:
    QList<QColor*> colorList;
};

#endif //VIEWDEMO_COLORITEMMODEL_H
