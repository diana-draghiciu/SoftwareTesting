#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SoftwareTesting.h"

class SoftwareTesting : public QMainWindow
{
    Q_OBJECT

public:
    SoftwareTesting(QWidget *parent = Q_NULLPTR);

private:
    Ui::SoftwareTestingClass ui;
};
