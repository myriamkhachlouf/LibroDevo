#ifndef CRUD_H
#define CRUD_H

#include <QDialog>

namespace Ui {
class crud;
}

class crud : public QDialog
{
    Q_OBJECT

public:
    explicit crud(QWidget *parent = nullptr);
    ~crud();

private:
    Ui::crud *ui;
};

#endif // CRUD_H
