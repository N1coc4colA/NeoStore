#ifndef TOOLSVIEW_H
#define TOOLSVIEW_H

#include "mainview.h"

#include <QWidget>

namespace Ui {
class ToolsView;
}

class SpecialEdits;

class ToolsView : public QWidget
{
    Q_OBJECT

public:
    explicit ToolsView(QWidget *parent = nullptr);
    ~ToolsView();

private:
    Ui::ToolsView *ui;

public Q_SLOTS:
    void load(SpecialEdits *, Categories *category);
};

#endif // TOOLSVIEW_H
