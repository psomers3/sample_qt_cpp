#include "mainwidget.h"
#include <QtWidgets>
#include <QObject>


/**
 * @brief Construct the main window.
 * @param parent an optional parent widget for this window.
 */
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
   _button = new QPushButton("Push Me!");
   _textBrowser = new QTextBrowser();
   connect(_button, &QPushButton::released, this, &MainWidget::fill_text);

   QVBoxLayout *mainLayout = new QVBoxLayout();
   mainLayout->addWidget(_button);
   mainLayout->addWidget(_textBrowser);
   setLayout(mainLayout);
   setWindowTitle("Test App");
}

/**
 * @brief The Destructor
 */
MainWidget::~MainWidget(){}

/**
 * @brief A function that fills the text field with a predefined string.
 */
void MainWidget::fill_text(){
    _textBrowser->setText("wow this is so cool");
}