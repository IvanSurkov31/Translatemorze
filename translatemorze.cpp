#include "translatemorze.h"

TranslateMorze::TranslateMorze(QWidget *parent)
    : QWidget(parent)
{
    TE_Text=new QTextEdit;
    TE_Translate=new QTextEdit;
    TE_Translate->setReadOnly(true);

    lbl_Text=new  QLabel("&Enter the text or a Morse code");
    lbl_Text->setBuddy(TE_Text);
    lbl_Translate=new  QLabel("&Ready translation");
    lbl_Translate->setBuddy(TE_Translate);

    PB_Translate=new QPushButton("&To translate");

    VBL_Text=new QVBoxLayout;
    VBL_Translate=new QVBoxLayout;
    VBL_Final=new QVBoxLayout;
    HBL_Text=new QHBoxLayout;
    HBL_Button=new QHBoxLayout;

    VBL_Text->addWidget(lbl_Text);
    VBL_Text->addWidget(TE_Text);
    VBL_Translate->addWidget(lbl_Translate);
    VBL_Translate->addWidget(TE_Translate);
    HBL_Text->addLayout(VBL_Text);
    HBL_Text->addLayout(VBL_Translate);
    HBL_Button->addWidget(PB_Translate);
    HBL_Button->addStretch();
    VBL_Final->addLayout(HBL_Text);
    VBL_Final->addLayout(HBL_Button);
    setLayout(VBL_Final);
    setFont(QFont("Times",12));

    connect(TE_Text,SIGNAL(textChanged()),SLOT(slot_WritteText()));
    connect(PB_Translate,SIGNAL(clicked(bool)),SLOT(slot_PB_Translate(bool)));
}

void TranslateMorze::slot_WritteText()
{
    this->TE_Translate->setPlainText(fun_Translate(this->TE_Text->toPlainText()));
}

void TranslateMorze::slot_PB_Translate(bool flag_click)
{
    this->TE_Translate->setPlainText(fun_Translate(this->TE_Text->toPlainText()));
}

QString TranslateMorze::fun_Translate(QString str_inText)
{
    QString str0,str1,str2,str3,str_return;
    str0=str_inText[0];
    str1=str_inText[1];
    str2=str_inText[2];
    str3=str_inText[3];

    if((str0=="-"||str0==".")/*||
                                   ((str0=="-"||str0==".")&&(str1==" ")&&(str2==" ")&&(str3=="-"||str3=="."))||
                                   ((str0=="-"||str0==".")&&(str1==" ")&&(str2=="-"||str2=="."))||
                                   ((str0=="-"||str0==".")&&(str1=="-"||str1=="."))*/)
        str_return=fun_MorzetoText(str_inText);
    else
        str_return=fun_TexttoMorze(str_inText);

    return str_return;
}

QString TranslateMorze::fun_TexttoMorze(QString str_text)
{
    QString str_translate,str_i;
    const int size=str_text.size();

    for(int i=0;i<size;i++)
    {
        str_i=str_text[i];
        if(str_i!=" ")
            str_translate+=fun_AzbukaMorze(str_i,true)+" ";
        else
            str_translate+="  ";
    }
    return str_translate;
}

QString TranslateMorze::fun_MorzetoText(QString str_kodMorze)
{
    QStringList lst_word,lst_letter;
    QString str_text;

    lst_word=str_kodMorze.split("  ");
    foreach(QString str,lst_word)
    {
        lst_letter=str.split(" ");
        foreach(QString str1,lst_letter)
            str_text+=fun_AzbukaMorze(str1,false);
        str_text+=" ";
    }
    return str_text;
}

void TranslateMorze::slot_OpenFile(bool flag_click)
{
    QString file_text =
            QFileDialog::getOpenFileName(0, "Open file" ,"" , "*.txt");

    QFile file(file_text);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"error, file not open";

    QTextStream in(&file);
    QString line = in.readAll();
    QStringList lst;
    lst=line.split("-----");
    file.close();

    QString str_1,str_2,str0;
    if(lst.count()>1)
    {
        str_1=lst[0];
        str_2=lst[1];
    }
    str0=line[0];

    TE_Translate->setPlainText(str_2);
    TE_Text->setPlainText(str_1);
}

void TranslateMorze::slot_SaveFile(bool flag_click)
{
    QString str_file;
    str_file=TE_Text->toPlainText()+"\r\n"+"-------"+"\r\n"+TE_Translate->toPlainText();
    QString name_file=QFileDialog::getSaveFileName(0,"Save file","file","*.txt");

    QFile file(name_file);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream<<str_file;
        file.close();
    }
}

QString TranslateMorze::fun_AzbukaMorze(QString letter,bool flag_TextorMorze)
{
    QMap<QString,QString> map_AzpukaMorze;
    map_AzpukaMorze["A"]=".-";
    map_AzpukaMorze["a"]=".-";
    map_AzpukaMorze["B"]="-...";
    map_AzpukaMorze["b"]="-...";
    map_AzpukaMorze["W"]=".--";
    map_AzpukaMorze["w"]=".--";
    map_AzpukaMorze["G"]="--.";
    map_AzpukaMorze["g"]="--.";
    map_AzpukaMorze["D"]="-..";
    map_AzpukaMorze["d"]="-..";
    map_AzpukaMorze["E"]=".";
    map_AzpukaMorze["e"]=".";
    map_AzpukaMorze["V"]="...-";
    map_AzpukaMorze["v"]="...-";
    map_AzpukaMorze["Z"]="--..";
    map_AzpukaMorze["z"]="--..";
    map_AzpukaMorze["I"]="..";
    map_AzpukaMorze["i"]="..";
    map_AzpukaMorze["J"]=".---";
    map_AzpukaMorze["j"]=".---";
    map_AzpukaMorze["K"]="-.-";
    map_AzpukaMorze["k"]="-.-";
    map_AzpukaMorze["L"]=".-..";
    map_AzpukaMorze["l"]=".-..";
    map_AzpukaMorze["M"]="--";
    map_AzpukaMorze["m"]="--";
    map_AzpukaMorze["N"]="-.";
    map_AzpukaMorze["n"]="-.";
    map_AzpukaMorze["O"]="---";
    map_AzpukaMorze["o"]="---";
    map_AzpukaMorze["P"]=".--.";
    map_AzpukaMorze["p"]=".--.";
    map_AzpukaMorze["R"]=".-.";
    map_AzpukaMorze["r"]=".-.";
    map_AzpukaMorze["S"]="...";
    map_AzpukaMorze["s"]="...";
    map_AzpukaMorze["T"]="-";
    map_AzpukaMorze["t"]="-";
    map_AzpukaMorze["U"]="..-";
    map_AzpukaMorze["u"]="..-";
    map_AzpukaMorze["F"]="..-.";
    map_AzpukaMorze["f"]="..-.";
    map_AzpukaMorze["H"]="....";
    map_AzpukaMorze["h"]="....";
    map_AzpukaMorze["C"]="-.-.";
    map_AzpukaMorze["c"]="-.-.";
    map_AzpukaMorze["Q"]="--.-";
    map_AzpukaMorze["q"]="--.-";
    map_AzpukaMorze["Y"]="-.--";
    map_AzpukaMorze["y"]="-.--";
    map_AzpukaMorze["X"]="-..-";
    map_AzpukaMorze["x"]="-..-";

    QString str_return;
    QMap<QString,QString>::iterator it =map_AzpukaMorze.begin();

    if(flag_TextorMorze==true)
    {
        for(;it!=map_AzpukaMorze.end();++it)
            if(it.key()==letter)
                str_return=it.value();
    }
    else
    {
        for(;it!=map_AzpukaMorze.end();++it)
            if(it.value()==letter)
                str_return=it.key();
    }
    return str_return;
}

TranslateMorze::~TranslateMorze()
{

}
