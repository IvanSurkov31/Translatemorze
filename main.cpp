#include "MW_translatemorze.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MW_TranslateMorze w;
    w.show();

    return a.exec();
}
