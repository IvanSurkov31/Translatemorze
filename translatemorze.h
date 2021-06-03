#ifndef TRANSLATEMORZE_H
#define TRANSLATEMORZE_H

#include <QWidget>
#include <QtWidgets>

class TranslateMorze : public QWidget
{
    Q_OBJECT

public:
    TranslateMorze(QWidget *parent = 0);
    ~TranslateMorze();
private:
    QTextEdit* TE_Text;
    QTextEdit* TE_Translate;
    QLabel* lbl_Text;
    QLabel* lbl_Translate;
    QPushButton* PB_Translate;
    QVBoxLayout* VBL_Text;
    QVBoxLayout* VBL_Translate;
    QVBoxLayout* VBL_Final;
    QHBoxLayout* HBL_Text;
    QHBoxLayout* HBL_Button;

    QString fun_Translate(QString text);
    QString fun_AzbukaMorze(QString letter,bool flag_TextorMorze);
    QString fun_TexttoMorze(QString text);
    QString fun_MorzetoText(QString kodMorze);

private slots:
    void slot_WritteText();
    void slot_PB_Translate(bool flag_click);
public slots:
    void slot_OpenFile(bool flag_click);
    void slot_SaveFile(bool flag_click);

};

#endif // TRANSLATEMORZE_H
