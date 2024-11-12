#include "calculator.h"
#include "./ui_calculator.h"
#include <QRegularExpression>
//#include <QScriptEngine>
//#include <QJSEngine>

double calcVal = 0.0; // track the current value of calculation
QString currentExpression = "";  // Store the full expression

// last math button clicked on - keep track of the buttons that has been clicked on
bool DivTrigger  = false;
bool MultTrigger = false;
bool AddTrigger  = false;
bool SubTrigger  = false;
bool PerTrigger  = false;
bool SinTrigger  = false;
bool CosTrigger  = false;
bool TanTrigger  = false;
bool LogTrigger  = false;
bool LnTrigger   = false;


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent) // main window constructor
    , ui(new Ui::Calculator) // create ui class and assign it the ui member that we created
{
    ui->setupUi(this); // setup ui

    ui->Display->setText(QString::number(calcVal)); // convert from double to QString

    // create an array that hold a reference to all the QPushButton
    QPushButton *numButtons[10];

    // cycle through them and assign signal and slot
    for(int i= 0; i <10; i++){
        QString butName = "Button" + QString::number(i); // get the button

        // get the buttons by name and add them into the array (search for a specific widget by providing the name)
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);

        // whenever the button is realeased - call function numpressed
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed())); // Double check
    }
    // connect buttons in the constructor
    connect(ui->Add, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Percent, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->Equals, SIGNAL(released()), this, SLOT(EqualButtonPressed()));

    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));

    connect(ui->ClearButton, SIGNAL(released()), this, SLOT(ClearButtonPressed()));

    connect(ui->DecimalButton, SIGNAL(released()), this, SLOT(DecimalButtonPressed()));

}

Calculator::~Calculator() // deconstructor
{
    delete ui;
}


void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender(); // sender will return a pointer of the button that was pressed
    QString butVal = button->text(); // get the number of the button that was clicked on

    // get the value on display
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0)){
        ui->Display->setText(butVal); // display whatever the button value is
    }
    else{
        QString newVal = displayVal + butVal; // you add the numbers and store them in newVal
        double dblNewVal = newVal.toDouble(); // switch it to double
        ui->Display->setText(QString::number(dblNewVal, 'g', 16)); // display it

        // Append the number to the current expression and update the display
        //currentExpression += newVal;
        //ui->Display->setText(currentExpression);
    }
}

void Calculator::MathButtonPressed(){
    // track which math button is clicked last
    DivTrigger  = false;
    MultTrigger = false;
    AddTrigger  = false;
    SubTrigger  = false;
    PerTrigger  = false;

    // store current value inside display
    QString displayVal = ui->Display->text();
    //store it
    calcVal = displayVal.toDouble(); // all in double

    // check sender to see which operation was clicked
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();

    // which one was clicked on
    if (QString::compare(butVal, "÷", Qt::CaseInsensitive) == 0){
        DivTrigger = true;
    }
    else if (QString::compare(butVal, "x", Qt::CaseInsensitive) == 0){
        MultTrigger = true;
    }
    else if (QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        AddTrigger = true;
    }
    else if (QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        SubTrigger = true;
    }
    else if (QString::compare(butVal, "%", Qt::CaseInsensitive) == 0){
        PerTrigger = true;
    }
    ui->Display->setText(""); // clear display because we are about to enter a new number

    // Append the operator to the current expression and update the display
    //currentExpression += " " + butVal + " ";  // Add spaces around operators for better formatting
    //ui->Display->setText(currentExpression);


}

void Calculator::EqualButtonPressed(){
    // if an equal button is pressed - submission
    double solution = 0.0;

    // get the value that is in the display to perform set calculation
    QString displayVal = ui->Display->text();

    // store it - and switch it to double
    double dblDisplayVal = displayVal.toDouble();

    // make sure that an operation was pressed
    if (AddTrigger || SubTrigger || DivTrigger || MultTrigger || PerTrigger){
        if (AddTrigger){
            solution = calcVal + dblDisplayVal;
        }
        else if (SubTrigger){
            solution = calcVal - dblDisplayVal;
        }
        else if (MultTrigger){
            solution = calcVal * dblDisplayVal;
        }
        else if (DivTrigger){
            if (dblDisplayVal != 0){
                solution = calcVal / dblDisplayVal;
            }
            else{
                solution = 0; // handle division by zero error - raise an error maybe (or do not allow them to press =)
            }
        }
        else if (PerTrigger){
            solution = calcVal * (dblDisplayVal / 100.0);
        }

        // display the result on the UI
        ui->Display->setText(QString::number(solution));
    }
}

void Calculator::ChangeNumberSign(){
    QString displayVal = ui->Display->text(); //get the value in the display

    // check whats inside RegExp - regular expression
    QRegularExpression regex("[-]?[0-9.]*");

    QRegularExpressionMatch match = regex.match(displayVal); // perform the match

    if (match.hasMatch() && match.captured(0) == displayVal){
        double dblDisplayVal = displayVal.toDouble(); // switch display to double
        double dblDisplayValSign = dblDisplayVal * (-1); // multiply it by -1 to get the negative value

        // display it
        ui->Display->setText(QString::number(dblDisplayValSign));

    }
}

void Calculator::ClearButtonPressed(){
    // clear the display
    ui->Display->setText("0");
    currentExpression = "";  // Clear the stored expression

    // reset calculations to zero
    calcVal = 0.0;

    // reset all operation triggers
    DivTrigger  = false;
    MultTrigger = false;
    AddTrigger  = false;
    SubTrigger  = false;
    PerTrigger  = false;
    SinTrigger  = false;
    CosTrigger  = false;
    TanTrigger  = false;
    LogTrigger  = false;
    LnTrigger   = false;
}

void Calculator::DecimalButtonPressed(){
    // get and store curtrent value
    QString displayVal = ui->Display->text();

    // handle abnormal cases
    // if the display empty or has a negative sign (which probably won't happen as I set the default value of the display to 0)
    if (displayVal.isEmpty() || displayVal == "-"){
        ui->Display->setText("0.");
    }
    // if the current value doesn't already contain a decimal point, add one
    else if (!displayVal.contains('.')){
        ui->Display->setText(displayVal + ".");
    }
    // if user add . and doesn't a number after it consider it as x.0
    else if (displayVal.endsWith(".")) {
        ui->Display->setText(displayVal + "0");
    }
    // If the display already has a decimal and a number after it, allow adding more digits
    else if (displayVal.contains('.') && !displayVal.endsWith(".")) {
        // Only append decimal numbers if the current number is valid and ends with a digit
        ui->Display->setText(displayVal);
    }


    /*
     *
    // If the current value is empty or just contains a negative sign, set it to "0."
    if (displayVal.isEmpty() || displayVal == "-") {
        currentExpression += "0.";  // Append "0." if it's the first decimal input
    }
    // If there is no decimal in the current input, append the decimal
    else if (!displayVal.contains('.')) {
        currentExpression += ".";
    }

    // Update the display with the current expression
    ui->Display->setText(currentExpression);

    */

}
