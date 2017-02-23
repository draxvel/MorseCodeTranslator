#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//Create a morse library
        alphabetMorse [0] = ".-";
        alphabetMorse [1] = "-...";
        alphabetMorse [2] = "-.-.";
        alphabetMorse [3] = "-..";
        alphabetMorse [4] = ".";
        alphabetMorse [5] = "..-.";
        alphabetMorse [6] = "--.";
        alphabetMorse [7] = "....";
        alphabetMorse [8] = "..";

        alphabetMorse [9] = ".---";
        alphabetMorse [10] = "-.-";
        alphabetMorse [11] = ".-..";
        alphabetMorse [12] = "--";
        alphabetMorse [13] = "-.";
        alphabetMorse [14] = "---";
        alphabetMorse [15] = ".--.";
        alphabetMorse [16] = "--.-";
        alphabetMorse [17] = ".-.";

        alphabetMorse [18] = "...";
        alphabetMorse [19] = "-";
        alphabetMorse [20] = "..-";
        alphabetMorse [21] = "...-";
        alphabetMorse [22] = ".--";
        alphabetMorse [23] = "-..-";
        alphabetMorse [24] = "-.--";
        alphabetMorse [25] = "--..";

//Create ENG library (using ASCII)
        for(int i = 65, k= 0; i<=90; i++, k++)
        {
           alphabetEng [k] =i;
        }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_Do_clicked()
{
    textConverted = "";
    temp="";

//Check if choosed type and plainTextEdit_Origin not Empty
    if(choosedTypeandPlainNotEmpty())
    {
        textOrigin = ui->plainTextEdit_Origin->toPlainText().toStdString();

        if(ui->radioButton_toText->isChecked())
        {
           toText();
        }

        if(ui->radioButton_toMorse->isChecked())
        {
           toMorse();
        }

        ui->plainTextEdit_Converted->setPlainText(textConverted.c_str());
    }
}

//convert morse code to text
void Widget::toText()
{
    textOrigin+=" ";

    for(size_t i = 0; i<textOrigin.size(); i++)
    {
        if(textOrigin[i] != ' ')
        {
              temp +=textOrigin[i];
        }
        else
        {
            for(int j = 0; j<=25; j++)
            {
                if (temp == alphabetMorse[j])
                {
                    textConverted += alphabetEng[j];
                    textConverted += " ";

                    //space between word
                    if(textOrigin[i+1] == ' ')
                    {
                        textConverted += " ";
                    }
                }
            }
            temp="";
        }
    }
}

//convert text to morse code
void Widget::toMorse()
{
    for(size_t i = 0; i<textOrigin.size(); i++)
    {
        if(textOrigin[i] == ' ')
        {
            textConverted += "  ";
            continue;
        }

        for(int j = 0; j<=25; j++)
        {
            if (toupper(textOrigin[i]) == alphabetEng[j])
            {
                textConverted += alphabetMorse[j];
                textConverted += " ";
            }
        }
    }

}

//checking empty PLaintTextEdit and choosed type converting
bool Widget::choosedTypeandPlainNotEmpty()
{
    if(!ui->radioButton_toMorse->isChecked() && !ui->radioButton_toText->isChecked())
    {
        QMessageBox ::information(this,
                                  "Error",
                                  "Please, choose a type");
        return false;
    }

    if(ui->plainTextEdit_Origin->toPlainText().isEmpty())
    {
        if(ui->radioButton_toMorse->isChecked())
        {
            QMessageBox ::information(this,
                                      "Error",
                                      "Please, enter the text (in English)");
            return false;

        }

        else
        {
            QMessageBox ::information(this,
                                      "Error",
                                      "Please, enter the morse code");
            return false;
        }
    }

    return true;
}

//Save as text file
void Widget::on_pushButton_OpenFile_clicked()
{
    QString filename =QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "Text File (*.txt)"
                );

     QFile file(filename);
     if(!file.open(QIODevice::ReadOnly | QFile::Text))
         QMessageBox::information(0,"Error", file.errorString());

     QTextStream in(&file);
     ui->plainTextEdit_Origin->setPlainText(in.readAll());

     file.close();
}

//Open text file
void Widget::on_pushButton_SaveFile_clicked()
{
    QString filename =QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                "C://",
                "Text File (*.txt)"
                );

     QFile file(filename);
     if(!file.open(QIODevice::WriteOnly | QFile::Text))
         QMessageBox::information(0,"Error", file.errorString());

     QTextStream out (&file);
     out << ui->plainTextEdit_Converted->toPlainText();
     file.flush();
     file.close();
}

//CLear both PlainTextEdit
void Widget::on_pushButton_Clear_clicked()
{
    ui->plainTextEdit_Origin->setPlainText("");
    ui->plainTextEdit_Converted->setPlainText("");
}
