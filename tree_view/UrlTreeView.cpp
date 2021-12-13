//
// Created by xiao on 2021/9/28.
//

#include "UrlTreeView.h"

#include "UrlItemDelegate.h"
#include "UrlItemModel.h"
#include "UrlItem.h"

#include <QMouseEvent>
#include <QModelIndex>

UrlTreeView::UrlTreeView(QWidget *parent) : QTreeView(parent)
{
    initTreeView();
}

void UrlTreeView::initTreeView()
{
    setIndentation(0);
    setHeaderHidden(true);

    // 添加根节点，TreeView中不可见
    auto rootDir = new UrlItem(UrlItem::Dir, "", "");
    rootDir->parent = nullptr;
    // 添加视频网站分类目录，View中可见
    auto videoDir = new UrlItem(UrlItem::Dir, "视频", "适合青少年的视频网站集合");
    rootDir->childrenUrlItems.append(videoDir);
    videoDir->parent = rootDir;

    auto iQiyi = new UrlItem(UrlItem::Url, "iQiYi", "www.iqiyi.com");
    videoDir->childrenUrlItems.append(iQiyi);
    iQiyi->parent = videoDir;

    auto bilibili = new UrlItem(UrlItem::Url, "Bilibili", "www.bilibili.com");
    videoDir->childrenUrlItems.append(bilibili);
    bilibili->parent = videoDir;

    // 添加游戏网站分类目录，TreeView中可见
    auto gameDir = new UrlItem(UrlItem::Dir, "游戏", "不适合青少年的游戏网站集合");
    rootDir->childrenUrlItems.append(gameDir);
    gameDir->parent = rootDir;

    auto steam = new UrlItem(UrlItem::Url, "Steam", "https://store.steampowered.com");
    gameDir->childrenUrlItems.append(steam);
    steam->parent = gameDir;

    auto model = new UrlItemModel(this);
    model->setRootItem(rootDir);

    setModel(model);
    auto delegate = new UrlItemDelegate(this);
    setItemDelegate(delegate);
}