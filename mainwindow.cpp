#include "mainwindow.h"
#include <limits>
#include <iostream>
#include <QMessageBox>

using std::string;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setupUi();
    setupConnects();
}

void MainWindow::setupUi()
{
    setWindowTitle("Form Layout");
    resize(1200, 500);

    layout = new QGridLayout(this);

    styleText = new QLabel("style:");
    style = new QComboBox;
    style->addItem("Fusion");
    style->addItem("Windows");
    style->addItem("WindowsVista");

    useSpal = new QCheckBox("use standard palette");
    disWid = new QCheckBox("Disbale widgets");

    layout->addWidget(styleText, 0, 0);
    layout->addWidget(style, 0, 1, 1, 3);
    layout->addWidget(useSpal, 0, 6);
    layout->addWidget(disWid, 0, 7);

    firstGroupBox = new QGroupBox("Group 1");
    secondGroupBox = new QGroupBox("Group 2");
    fourthGroupBox = new QGroupBox("Group 4");

    firstRadioButton = new QRadioButton("Radio button 1");
    secondRadioButton = new QRadioButton("Radio button 2");
    thirdRadioButton = new QRadioButton("Radio button 3");
    triStateCheckBox = new QCheckBox("Tri-state check box");
    triStateCheckBox->setTristate(true);

    QVBoxLayout *firstGroupBoxLayout = new QVBoxLayout;
    firstGroupBoxLayout->addWidget(firstRadioButton);
    firstGroupBoxLayout->addWidget(secondRadioButton);
    firstGroupBoxLayout->addWidget(thirdRadioButton);
    firstGroupBoxLayout->addWidget(triStateCheckBox);

    firstGroupBox->setLayout(firstGroupBoxLayout);

    QVBoxLayout *secondGroupBoxLayout = new QVBoxLayout;
    firstPushButton = new QPushButton("Push button");
    secondPushButton = new QPushButton("Push button");
    thirdPushButton = new QPushButton("Push button");
    secondGroupBoxLayout->addWidget(firstPushButton);
    secondGroupBoxLayout->addWidget(secondPushButton);
    secondGroupBoxLayout->addWidget(thirdPushButton);

    secondGroupBox->setLayout(secondGroupBoxLayout);

    tabWidget = new QTabWidget();
    tab1 = new QWidget();
    tab2 = new QWidget();
    tabWidget->addTab(tab1, "Table");
    tabWidget->addTab(tab2, "Text Edit");
    tabWidget->setTabPosition(QTabWidget::North);

    tableWidget = new QTableWidget(10, 10);
    textEdit = new QTextEdit();

    QVBoxLayout *tab1Layout = new QVBoxLayout();
    tab1Layout->addWidget(tableWidget);
    tab1->setLayout(tab1Layout);

    QVBoxLayout *tab2Layout = new QVBoxLayout();
    tab2Layout->addWidget(textEdit);
    tab2->setLayout(tab2Layout);

    QGridLayout *fourthGroupBoxLayout = new QGridLayout();
    password = new QLineEdit();
    password->setEchoMode(QLineEdit::Password);
    number = new QLineEdit();
    number->setValidator(new QIntValidator(0, std::numeric_limits<int>::max()));
    date = new QDateTimeEdit();
    slider = new QSlider(Qt::Horizontal);
    dial = new QDial();

    fourthGroupBoxLayout->addWidget(password, 0, 0, 1, 2);
    fourthGroupBoxLayout->addWidget(number, 1, 0, 1, 2);
    fourthGroupBoxLayout->addWidget(date, 2, 0, 1, 2);
    fourthGroupBoxLayout->addWidget(slider, 3, 0, 1, 1);
    fourthGroupBoxLayout->addWidget(dial, 3, 1, 1, 1);

    fourthGroupBox->setLayout(fourthGroupBoxLayout);

    layout->addWidget(firstGroupBox, 1, 0, 3, 4);
    layout->addWidget(secondGroupBox, 1, 5, 3, 4);
    layout->addWidget(tabWidget, 4, 0, 3, 4);
    layout->addWidget(fourthGroupBox, 4, 5, 3, 4);

    setLayout(layout);
}

void MainWindow::setupConnects() {
    connect(style, &QComboBox::currentTextChanged, this, &MainWindow::onWidgetClicked);
    connect(useSpal, &QCheckBox::stateChanged, this, &MainWindow::onWidgetClicked);
    connect(disWid, &QCheckBox::stateChanged, this, &MainWindow::onWidgetClicked);
    connect(firstRadioButton, &QRadioButton::toggled, this, &MainWindow::onWidgetClicked);
    connect(secondRadioButton, &QRadioButton::toggled, this, &MainWindow::onWidgetClicked);
    connect(thirdRadioButton, &QRadioButton::toggled, this, &MainWindow::onWidgetClicked);
    connect(triStateCheckBox, &QCheckBox::stateChanged, this, &MainWindow::onWidgetClicked);
    connect(firstPushButton, &QPushButton::clicked, this, &MainWindow::onWidgetClicked);
    connect(secondPushButton, &QPushButton::clicked, this, &MainWindow::onWidgetClicked);
    connect(thirdPushButton, &QPushButton::clicked, this, &MainWindow::onWidgetClicked);
    connect(tableWidget, &QTableWidget::cellClicked, this, &MainWindow::onWidgetClicked);
    connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::onWidgetClicked);
    connect(password, &QLineEdit::textChanged, this, &MainWindow::onWidgetClicked);
    connect(number, &QLineEdit::textChanged, this, &MainWindow::onWidgetClicked);
    connect(date, &QDateTimeEdit::dateTimeChanged, this, &MainWindow::onWidgetClicked);
    connect(slider, &QSlider::valueChanged, this, &MainWindow::onWidgetClicked);
    connect(dial, &QDial::valueChanged, this, &MainWindow::onWidgetClicked);
    connect(tableWidget, &QTableWidget::cellChanged, this, &MainWindow::onWidgetClicked);
}

void showMsgBox(string text) {
//    QMessageBox msgBox;
//    msgBox.setText(text.c_str());
//    msgBox.exec();
    qInfo() << text.c_str() << "\n";
};

void MainWindow::onWidgetClicked()
{
    QObject *senderObj = sender();
    if (auto *cb = qobject_cast<QComboBox *>(senderObj))
        showMsgBox("ComboBox current text: " + cb->currentText().toStdString());
    else if (auto *cb = qobject_cast<QCheckBox *>(senderObj))
        showMsgBox("CheckBox state: " + std::to_string(cb->isChecked()));
    else if (auto *rb = qobject_cast<QRadioButton *>(senderObj))
        showMsgBox("RadioButton toggled: " + std::to_string(rb->isChecked()));
    else if (auto *pb = qobject_cast<QPushButton *>(senderObj))
        showMsgBox("PushButton clicked");
    else if (auto *tw = qobject_cast<QTableWidget *>(senderObj))
        showMsgBox("TableWidget cell (" + 
        std::to_string(tw->currentRow() + 1) + ", " + std::to_string(tw->currentColumn() + 1) + " ) clicked or changed");
    else if (auto *te = qobject_cast<QTextEdit *>(senderObj))
        showMsgBox("TextEdit text changed");
    else if (auto *le = qobject_cast<QLineEdit *>(senderObj))
        showMsgBox("LineEdit text changed: " + le->text().toStdString());
    else if (auto *de = qobject_cast<QDateTimeEdit *>(senderObj))
        showMsgBox("DateTimeEdit date changed: " + de->dateTime().toString().toStdString());
    else if (auto *s = qobject_cast<QSlider *>(senderObj))
        showMsgBox("Slider value: " + std::to_string(s->value()));
    else if (auto *d = qobject_cast<QDial *>(senderObj))
        showMsgBox("Dial value: " + std::to_string(d->value()));
    
}