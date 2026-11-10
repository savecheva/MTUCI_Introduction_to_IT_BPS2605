// =======================================================
// Лабораторная работа №1
// GUI-приложение "Hello, Qt"
// Студент: Савичева А.С., группа БПС2605, вариант 13
// =======================================================
#include <QApplication>
#include <QLabel>
#include <QString>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QLabel label;
    // Исходный файл сохранён в UTF-8, поэтому строку декодируем как UTF-8
    label.setText(QString::fromUtf8("Савичева А.С., группа БПС2605\n"
                                    "Вариант 13\n"
                                    "Hello, Qt!"));
    label.setAlignment(Qt::AlignCenter);
    label.resize(400, 250);
    label.setStyleSheet("font-size: 16px; font-weight: bold;");
    label.setWindowTitle("HelloQt \u2014 Лабораторная работа №1");
    label.show();

    return app.exec();
}
