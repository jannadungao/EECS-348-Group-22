#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots: // slots are going to be executed whenever a signal is submitted (clicked)
    void NumPressed(); // handles the numbers 0-9
    void MathButtonPressed(); // handles all simple math
    //void TrigButtonPressed(); // handles all trig functions
    //void PrenthesesPressed(); // handles prentheses placement
    void ChangeNumberSign();  // handles changing the sign (+/-)
    void EqualButtonPressed(); // outputs the answer
    void ClearButtonPressed(); // clear and reset the calculator
    void DecimalButtonPressed(); // adding a decimal point
    //void HistoryPressed();    // function that will show past operations (Not sure yet)
};
#endif // CALCULATOR_H
