#include <QApplication>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QFormLayout>
#include <QWidget>
#include <QMessageBox>
#include <QProcess>
#include <QFileDialog>
#include "window.h"

void Window::operate()
{
    QStringList arguments;
    arguments << _path_script->text();
    arguments << _path_input->text();
    arguments << _path_output->text();


    QProcess process;
    process.start(_path_interpritator->text(), arguments);
    process.waitForFinished();

    auto err = process.readAllStandardError();
    if (err.size() != 0)
        QMessageBox::information(this, "Error", err);
    else
        QMessageBox::information(this, "Success", "Check out the output file!\nHooray!!! :3 :3 :3");
}

void Window::set_path_interpritator()
{
    auto path = QFileDialog::getOpenFileName(0, "Choose file", "*.exe");
    if (!path.isEmpty())
        _path_interpritator->setText(path);
    else
        QMessageBox::information(this, "Error", "\nThe path is empty!");
}

void Window::set_path_script()
{
    auto path = QFileDialog::getOpenFileName(0, "Choose file", "*.py");
    if (!path.isEmpty())
        _path_script->setText(path);
    else
        QMessageBox::information(this, "Error", "\nThe path is empty!");
}

void Window::set_path_input()
{
    auto path = QFileDialog::getOpenFileName(0, "Choose file", "*.txt");
    if (!path.isEmpty())
        _path_input->setText(path);
    else
        QMessageBox::information(this, "Error", "\nThe path is empty!");
}

void Window::set_path_output()
{
    auto path = QFileDialog::getOpenFileName(0, "Choose file", "*.txt");;
    if (!path.isEmpty())
        _path_output->setText(path);
    else
        QMessageBox::information(this, "Error", "\nThe path is empty!");
}
void Window::close_app()
{
    this->close();
}

Window::Window()
{
    _path_interpritator = new QLineEdit("C:/Users/admin/AppData/Local/Programs/Python/Python39/python.exe");
    auto button_interpritator = new QPushButton("Choose file");
    button_interpritator->setFixedWidth(100);
    connect(button_interpritator, &QPushButton::clicked, this, &Window::set_path_interpritator);

    _path_script = new QLineEdit("C:/Users/admin/Desktop/lab4/validator.py");/////
    auto button_script = new QPushButton("Choose file");
    button_script->setFixedWidth(100);
    connect(button_script, &QPushButton::clicked, this, &Window::set_path_script);

    _path_input = new QLineEdit("C:/Users/admin/Desktop/lab4/input.txt");/////
    auto button_input = new QPushButton("Choose file");
    button_input->setFixedWidth(100);
    connect(button_input, &QPushButton::clicked, this, &Window::set_path_input);

    _path_output = new QLineEdit("C:/Users/admin/Desktop/lab4/output.txt");/////
    auto button_output = new QPushButton("Choose file");
    button_output->setFixedWidth(100);
    connect(button_output, &QPushButton::clicked, this, &Window::set_path_output);

    auto button_start = new QPushButton("Start!");
    connect(button_start, &QPushButton::clicked, this, &Window::operate);

    auto button_exit = new QPushButton("Exit");
    connect(button_exit, &QPushButton::clicked, this, &Window::close_app);


    auto layout1 = new QFormLayout();
    layout1->addRow("Python interpritator directory:", _path_interpritator);
    auto layout2 = new QFormLayout();
    layout2->addRow("Python script directory:", _path_script);
    auto layout3 = new QFormLayout();
    layout3->addRow("Input file directory:", _path_input);
    auto layout4 = new QFormLayout();
    layout4->addRow("Output file directory:", _path_output);
    auto layout = new QGridLayout();
    layout->addLayout(layout1, 0, 0);
    layout->addWidget(button_interpritator, 0, 1);
    layout->addLayout(layout2, 1, 0);
    layout->addWidget(button_script, 1, 1);
    layout->addLayout(layout3, 2, 0);
    layout->addWidget(button_input, 2, 1);
    layout->addLayout(layout4, 3, 0);
    layout->addWidget(button_output, 3, 1);
    layout->addWidget(button_start, 4, 0);
    layout->addWidget(button_exit, 4, 1);

    setLayout(layout);
    setFixedSize(sizeHint());
}