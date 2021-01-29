#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "text_highlighter.hpp"

#include <QMainWindow>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_pushButton_clicked();

private:
    void setupEditor();

    Ui::Window *ui;
    text_highlighter *highliter;

};

#endif // WINDOW_HPP
