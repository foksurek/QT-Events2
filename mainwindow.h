#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QTabWidget>
#include <QTableWidget>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QSlider>
#include <QDial>

class MainWindow : public QWidget
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    
private slots:
    void onWidgetClicked();

private:
    void setupUi();
    void setupConnects();
    QGridLayout *layout{};
    QLabel *styleText{};
    QComboBox *style{};
    QCheckBox *useSpal{};
    QCheckBox *disWid{};
    QGroupBox *firstGroupBox{};
    QGroupBox *secondGroupBox{};
    QGroupBox *fourthGroupBox{};
    QRadioButton *firstRadioButton{};
    QRadioButton *secondRadioButton{};
    QRadioButton *thirdRadioButton{};
    QCheckBox *triStateCheckBox{};
    QPushButton *firstPushButton{};
    QPushButton *secondPushButton{};
    QPushButton *thirdPushButton{};
    QTabWidget *tabWidget{};
    QWidget *tab1{};
    QWidget *tab2{};
    QTableWidget *tableWidget{};
    QTextEdit *textEdit{};
    QLineEdit *password{};
    QLineEdit *number{};
    QDateTimeEdit *date{};
    QSlider *slider{};
    QDial *dial{};
};

#endif // MAINWINDOW_H
