#pragma once
#include <QApplication>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QFormLayout>
#include <QWidget>
#include <QMessageBox>
#include <QProcess>
#include <QFileDialog>

class Window : public QWidget
{
    QLineEdit* _path_interpritator; // C:/Users/HP/AppData/Local/Programs/Python/Python39/python.exe
    QLineEdit* _path_script; // C:/Users/HP/Desktop/lab4/validator.py
    QLineEdit* _path_input; // C:/Users/HP/PycharmProjects/SecondLab/input.txt
    QLineEdit* _path_output; // C:/Users/HP/PycharmProjects/SecondLab/output.txt

    void operate();
    void set_path_interpritator();
    void set_path_script();
    void set_path_input();
    void set_path_output();
    void close_app();
public:
    Window();
};
