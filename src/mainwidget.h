#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QtWidgets>
#include <QtCore>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget(); // Destructor

private:
   QPointer<QPushButton> _button;
   QPointer<QTextBrowser> _textBrowser;
   
private Q_SLOTS:
    void fill_text();
};

#endif 