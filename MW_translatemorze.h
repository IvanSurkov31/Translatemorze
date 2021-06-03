#ifndef MW_TRANSLATEMORZE_H
#define MW_TRANSLATEMORZE_H

#include <QMainWindow>
#include <QtWidgets>
#include <translateMorze.h>

class MW_TranslateMorze : public QMainWindow
{
    Q_OBJECT

public:
    MW_TranslateMorze(QWidget *parent = 0);
    ~MW_TranslateMorze();
private:
    TranslateMorze* var_translateMorze;
    QMenu* menu_File;
    QMenu* menu_Help;
private slots:
    void slot_menuHelp(bool);
};

#endif // MW_TRANSLATEMORZE_H
