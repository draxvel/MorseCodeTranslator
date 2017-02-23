#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_Do_clicked();

    void toText();
    void toMorse();

    bool choosedTypeandPlainNotEmpty();

    void on_pushButton_OpenFile_clicked();

    void on_pushButton_SaveFile_clicked();

    void on_pushButton_Clear_clicked();

private:
    Ui::Widget *ui;
    std::string alphabetMorse [26];
    char alphabetEng [25];

    //input text
    std::string textOrigin;

    //output text
    std::string textConverted;

    //for saving one morse symbol
    std::string temp;
};

#endif // WIDGET_H
