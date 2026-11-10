// =======================================================
// Лабораторная работа №1
// GUI-приложение "Hello, Qt" (Qt Creator, qmake)
// Студент: Савичева А.С., группа БПС2605, вариант 13
// =======================================================
#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QLabel label(u8"Савичева А.С., группа БПС2605\n"
                  "Вариант 13\n"
                  "Hello, Qt!");
    label.setAlignment(Qt::AlignCenter);
    label.resize(400, 250);
    label.setStyleSheet("font-size: 16px; font-weight: bold;");
    label.setWindowTitle("HelloQtCreator \u2014 Лабораторная работа №1");
    label.show();

    return app.exec();
}
