#include "MW_translatemorze.h"
#include <QtWidgets>

MW_TranslateMorze::MW_TranslateMorze(QWidget *parent)
    : QMainWindow(parent)
{
    QAction* pastSave=new QAction("file save",0);
    pastSave->setText("&Save");
    QAction* pastOpen=new QAction("open file",0);
    pastOpen->setText("&Open File");
    QAction* pastAbout=new QAction("About",0);
    pastAbout->setText("&About");

    menu_File=new QMenu("&File");
    menu_File->addAction(pastSave);
    menu_File->addAction(pastOpen);

    menu_Help=new QMenu("&Help");
    menu_Help->addAction(pastAbout);

    this->menuBar()->addMenu(menu_File);
    this->menuBar()->addMenu(menu_Help);

    var_translateMorze=new TranslateMorze;
    this->setCentralWidget(var_translateMorze);

    connect(pastSave,SIGNAL(triggered(bool)),var_translateMorze,SLOT(slot_SaveFile(bool)));
    connect(pastOpen,SIGNAL(triggered(bool)),var_translateMorze,SLOT(slot_OpenFile(bool)));
    connect(pastAbout,SIGNAL(triggered(bool)),SLOT(slot_menuHelp(bool)));

    setWindowTitle("Translate Morze");
}

void MW_TranslateMorze::slot_menuHelp(bool f)
{
    QLabel* lbl_help=new QLabel("Program: translator latintsky alphabet of the Morse alphabet.\r\nThe text is determined automatically by first symbol.\r\n2016.");
    lbl_help->setFixedSize(450,200);
    lbl_help->setFont(QFont("Times",12));
    lbl_help->show();
    lbl_help->setWindowTitle("About");
}

MW_TranslateMorze::~MW_TranslateMorze()
{

}
