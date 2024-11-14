#include "calculator.h"
#include "./ui_calculator.h"
#include <QRegularExpression>
//#include <QScriptEngine>
//#include <QJSEngine>

#include <QJSEngine>
#include <QJSValue>
#include <QDebug>

#include <cmath>


double calcVal = 0.0; // track the current value of calculation
QString currentExpression = "";  // Store the full expression
QString displayExpression = ""; // the displayed expression
int openParenthesesCount = 0; // track the number of open prentheses
int closeparenthesesCount = 0; // track the number of closed parentheses

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
bool DecimalTrigger = true;


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

    connect(ui->DeleteLastButton, SIGNAL(released()), this, SLOT(DeleteLast()));

    connect(ui->Prentheseses, SIGNAL(released()), this, SLOT(PrenthesesPressed()));

    connect(ui->SinButton, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
    connect(ui->CosButton, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
    connect(ui->TanButton, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
    connect(ui->LnButton, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
    connect(ui->LogButton, SIGNAL(released()), this, SLOT(TrigButtonPressed()));

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

    // append the button value to the current expression and display it
    currentExpression += butVal;
    displayExpression += butVal;
    ui->Display->setText(displayExpression);

    /*
    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0)){
        //ui->Display->setText(butVal); // display whatever the button value is

        //currentExpression += butVal;
        // ui->Display->setText(currentExpression); // display whatever the button value is
    }
    else{
        QString newVal = displayVal + butVal; // you add the numbers and store them in newVal
        double dblNewVal = newVal.toDouble(); // switch it to double
        //ui->Display->setText(QString::number(dblNewVal, 'g', 16)); // display it

        // Append the number to the current expression and update the display
        //currentExpression += newVal;
        //ui->Display->setText(currentExpression);
    }
    */
}

void Calculator::MathButtonPressed(){
    // track which math button is clicked last
    DivTrigger  = false;
    MultTrigger = false;
    AddTrigger  = false;
    SubTrigger  = false;
    PerTrigger  = false;
    DecimalTrigger = true;

    #include <string>
    std::string ops[5] = {"+", "-", "%", "*", "÷"};


    // store current value inside display
    QString displayVal = ui->Display->text();

    // Double Check Again, we can do it by giving priority to the last clicked operation!!!!!!!!!!!!!!!!
    if (displayVal.isEmpty() || displayVal.endsWith(" ") || displayVal.endsWith("+") || displayVal.endsWith("-") || displayVal.endsWith("x") || displayVal.endsWith("÷")){
        return;
    }


    //store it
    calcVal = displayVal.toDouble(); // all in double

    // check sender to see which operation was clicked
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayValue = butVal;


    // which one was clicked on
    if (QString::compare(butVal, "÷", Qt::CaseInsensitive) == 0){
        butVal = "/";
        DivTrigger = true;
    }
    else if (QString::compare(butVal, "x", Qt::CaseInsensitive) == 0){
        butVal = "*";
        MultTrigger = true;
    }
    else if (QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        butVal = "+";
        AddTrigger = true;
    }
    else if (QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        butVal = "-";
        SubTrigger = true;
    }
    else if (QString::compare(butVal, "%", Qt::CaseInsensitive) == 0){
        butVal = "/100";
        PerTrigger = true;
    }
    //ui->Display->setText(""); // clear display because we are about to enter a new number


    // Append the operator to the current expression and update the display
    currentExpression += butVal;  // Add spaces around operators for better formatting
    displayExpression += displayValue; // for looks - display
    ui->Display->setText(displayExpression);


}

void Calculator::EqualButtonPressed(){

    /*
    // if an equal button is pressed - submission
    double solution = 0.0;

    // get the value that is in the display to perform set calculation
    QString displayVal = ui->Display->text();

    // store it - and switch it to double
    double dblDisplayVal = displayVal.toDouble(); // THE PROBLEM IS HERE - THIS WOULD BE AN EXPRESSION AND IT CAN'T BE TURNED INTO DOUBLE

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
        currentExpression = QString::number(solution); // modified
    }
    */

    /*
    // Initialize the QSEngine
    QJSEngine engine;

    // set up the expression to be evaluated
    QString expression = currentExpression;

    //evaluate the expression
    QJSValue result = engine.evaluate(expression);

    // handle error
    if (result.isError()){
        qDebug() << "Error: "<< result.toString();
    }
    else{
        double solution = result.toNumber();
        // Display the result in the UI
        ui->Display->setText(QString::number(solution));

        // Update the current expression to the result
        currentExpression = QString::number(solution); // Store the result for further calculations
        displayExpression = QString::number(solution);
    }
    */

    // Initialize the QJSEngine
    QJSEngine engine;

    // Ensure Math functions are available in the global context
    engine.globalObject().setProperty("Math", engine.evaluate("Math"));

    // Prepare the expression to ensure it uses Math functions correctly
    // For example, we need to make sure the expression uses Math.sin, Math.cos, etc.
    QString expression = currentExpression;

    // Replace any trigonometric function references with the proper Math functions
    //expression.replace("sin", "Math.sin");
    //expression.replace("cos", "Math.cos");
    //expression.replace("tan", "Math.tan");
    //expression.replace("asin", "Math.asin");
    //expression.replace("acos", "Math.acos");
    //expression.replace("atan", "Math.atan");
    //expression.replace("atan2", "Math.atan2");
    //qDebug() << openParenthesesCount << closeparenthesesCount;

    // while loop that closes all the parentheses that are still open
    if (openParenthesesCount > closeparenthesesCount){
        while (openParenthesesCount > closeparenthesesCount){
            expression += ")";
            closeparenthesesCount += 1;
        }
    }

    qDebug() << expression;
    // Evaluate the expression using QJSEngine
    QJSValue result = engine.evaluate(expression);

    // Handle error in case of an invalid expression
    if (result.isError()) {
        qDebug() << "Error: " << result.toString();
        ui->Display->setText("Error");
        currentExpression = "";
        displayExpression = "";
    }
    else {
        double solution = result.toNumber();
        // Display the result in the UI
        ui->Display->setText(QString::number(solution));

        // Update the current expression to the result
        currentExpression = QString::number(solution); // Store the result for further calculations
        displayExpression = QString::number(solution);
    }

    // reset the parentheses back to zero for the next operations
    openParenthesesCount = 0;
    closeparenthesesCount = 0;
}

void Calculator::ChangeNumberSign(){
    /*
    QString displayVal = ui->Display->text(); //get the value in the display

    // check whats inside RegExp - regular expression
    QRegularExpression regex("[-]?[0-9.]*");

    QRegularExpressionMatch match = regex.match(displayVal); // perform the match

    if (match.hasMatch() && match.captured(0) == displayVal){
        double dblDisplayVal = displayVal.toDouble(); // switch display to double
        double dblDisplayValSign = dblDisplayVal * (-1); // multiply it by -1 to get the negative value

        // display it
        //ui->Display->setText(QString::number(dblDisplayValSign));
        currentExpression = "("+QString::number(dblDisplayValSign)+")";
        displayExpression = "("+QString::number(dblDisplayValSign)+")";
        //ui->Display->setText(QString::number(dblDisplayValSign));
        ui->Display->setText(displayExpression);
    }
    */
    QString displayVal = ui->Display->text(); // Get the value in the display

    // Regular expression to find the last number in the expression
    QRegularExpression regex("([-+]?[0-9]*\\.?[0-9]+)(?=[^0-9]*$)");

    QRegularExpressionMatch match = regex.match(displayVal); // Perform the match

    if (match.hasMatch()) {
        // Get the last number from the match
        QString lastNumberStr = match.captured(1);

        // Check if the number is negative (starts with '-')
        bool isNegative = lastNumberStr.startsWith('-');

        // Remove the leading "+" or "-" sign for easier processing
        if (isNegative) {
            lastNumberStr.remove(0, 1);  // Remove the leading '-' sign
        } else if (lastNumberStr.startsWith('+')) {
            lastNumberStr.remove(0, 1);  // Remove the leading '+' sign
        }

        // Convert the number to a double
        double lastNumber = lastNumberStr.toDouble();

        // Toggle the sign: If negative, make positive, if positive, make negative
        lastNumber = -lastNumber;  // This flips the sign

        // Convert the result back to string
        QString newNumberStr = QString::number(lastNumber);

        // If the number was negative, we need to ensure it has a leading '-'
        if (lastNumber < 0 && !newNumberStr.startsWith("-")) {
            newNumberStr = "-" + newNumberStr;
        }

        // Now, check if the number is preceded by an operator and handle it accordingly:
        QString operatorPart = "";
        int pos = match.capturedStart(1);

        // Check if there's an operator before the number (we care about +, -, *, /)
        if (pos > 0) {
            QChar prevChar = displayVal[pos - 1];
            if (prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '/' || prevChar == 'x' || prevChar == "÷") {
                operatorPart = prevChar;

                // If there is an operator, ensure the number is wrapped in parentheses
                // and adjust the operator part accordingly.
                if (prevChar == '*' || prevChar == '/' || prevChar == 'x' || prevChar == "÷") {
                    newNumberStr = "(" + newNumberStr + ")";
                }
            }
        }

        // If no operator is found, it means this number is at the end of the expression
        // or stands alone, and we don't need parentheses.

        // Construct the updated expression by replacing the last number with the new one
        QString updatedExpression = displayVal.left(pos) + newNumberStr;

        // Update both the display and the current expression
        displayExpression = updatedExpression;
        updatedExpression.replace("x", "*");
        updatedExpression.replace("÷", "/");
        currentExpression = updatedExpression;
        ui->Display->setText(displayExpression); // Update the display
    }

}

void Calculator::ClearButtonPressed(){
    // clear the display
    ui->Display->setText("0");
    currentExpression = "";  // Clear the stored expression
    displayExpression = "";

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

// PROBLEM HERE - IT ONLY WORK ONCE (for the first time)!!!!!!!!!!!!
void Calculator::DecimalButtonPressed(){
    // get and store curtrent value
    QString displayVal = ui->Display->text();

    // handle abnormal cases
    if (DecimalTrigger){
        // if the display empty or has a negative sign (which probably won't happen as I set the default value of the display to 0)
        if (displayVal.isEmpty() || displayVal.endsWith("+") || displayVal.endsWith("-") || displayVal.endsWith("x") || displayVal.endsWith("÷")){
            //ui->Display->setText("0.");
            displayVal += "0.";
        }
        // if the current value doesn't already contain a decimal point, add one
        //else if (!displayVal.contains('.')){
            //ui->Display->setText(displayVal + ".");
        //    displayVal += ".";
        //}
        // if user add . and doesn't a number after it consider it as x.0
        else if (displayVal.endsWith(".")) {
            //ui->Display->setText(displayVal + "0");
            displayVal += "0";
        }
        else if (endsWithInteger(displayVal)){
            displayVal += ".";
        }
        // If the display already has a decimal and a number after it, allow adding more digits
        //else if (displayVal.contains('.') && !displayVal.endsWith(".")) {
            // Only append decimal numbers if the current number is valid and ends with a digit
            //ui->Display->setText(displayVal);
    }

    //}
    currentExpression = displayVal;
    displayExpression = displayVal;
    ui->Display->setText(displayVal);
    //ui->Display->setText(displayExpression);

    DecimalTrigger = false;

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

// helper method to check if the last thing is a number
bool Calculator::endsWithInteger(const QString &str) {
    // Create a regular expression that matches an integer at the end of the string
    QRegularExpression regex(".*\\d+$");

    // Check if the string matches the pattern
    return regex.match(str).hasMatch();
}


void Calculator::DeleteLast(){
    // if it is not empty - remove last number or operation
    if (!currentExpression.isEmpty()){
        currentExpression.chop(1);
        displayExpression.chop(1);
    }
    ui->Display->setText(displayExpression);
}

void Calculator::PrenthesesPressed(){
    // get curtrent expression
    QString displayVal = ui->Display->text();

    /*
    // Case 1: If the expression ends with a number or a closing parenthesis, we can open a parenthesis.
    if (displayVal.isEmpty() || displayVal.endsWith("+") || displayVal.endsWith("-") || displayVal.endsWith("x") || displayVal.endsWith("÷")){
        currentExpression += "(";
        displayExpression += "(";
    }
    */
    // Case 1: If the last character is an operator or the display is empty, we can open a parenthesis.
    if (displayVal.isEmpty() || isOperator(displayVal[displayVal.length() - 1]) || displayVal.endsWith("(") || (displayVal.length() == 1 && displayVal.endsWith('0'))) {
        currentExpression += "(";  // Add opening parenthesis
        displayExpression += "(";  // Update the display
        openParenthesesCount += 1; // increment the open parentheses by 1
    }
    // Case 2: If there is already an open parenthesis, and the last character is a number or a closing parenthesis, we can close a parenthesis.
    else if (isNumberOrClosedParenthesis(displayVal[displayVal.length() - 1])) {
        currentExpression += ")";  // Add closing parenthesis
        displayExpression += ")";  // Update the display
        closeparenthesesCount += 1; // increment the close parentheses by 1
    }

    // Update the display
    ui->Display->setText(displayExpression);

}


//helper functions
// Helper function to validate if parentheses are allowed at this point in the expression
bool Calculator::isValidParenthesisPlacement() {
    QString displayVal = ui->Display->text();

    // If the expression ends with an operator or is empty, we can't open a parenthesis
    if (displayVal.isEmpty() || isOperator(displayVal[displayVal.length() - 1])) {
        return false;
    }

    // If the expression ends with a number or closing parenthesis, we can open a parenthesis
    if (displayVal.endsWith(")") || displayVal.length() == 0) {
        return true;
    }

    return false;
}
// Check if the given character is an operator
bool Calculator::isOperator(const QChar &ch) {
    return (ch == "+" || ch == "-" || ch == "*" || ch == "/");
}

// Check if the given character is a number or a closing parenthesis
bool Calculator::isNumberOrClosedParenthesis(const QChar &ch) {
    bool isDigit = ch.isDigit(); // Check if it's a digit
    bool isClosingParenthesis = (ch == ")");
    return (isDigit || isClosingParenthesis);
}


// IT IS NOT WORKING CORRECTLY - PARENTHESES LOGIC
void Calculator::TrigButtonPressed(){
    QString displayVal = ui->Display->text();

    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayValue = butVal;

    /*
    // which one was clicked on
    if (QString::compare(butVal, "sin", Qt::CaseInsensitive) == 0){
        butVal = "Math.sin";
        SinTrigger = true;
    }
    else if (QString::compare(butVal, "cos", Qt::CaseInsensitive) == 0){
        butVal = "Math.cos";
        CosTrigger = true;
    }
    else if (QString::compare(butVal, "tan", Qt::CaseInsensitive) == 0){
        butVal = "Math.tan";
        TanTrigger = true;
    }
    else if (QString::compare(butVal, "ln", Qt::CaseInsensitive) == 0){
        butVal = "ln(";
        LnTrigger = true;
    }
    else if (QString::compare(butVal, "log", Qt::CaseInsensitive) == 0){
        butVal = "log(";
        LogTrigger = true;
    }
    //ui->Display->setText(""); // clear display because we are about to enter a new number


    // Append the operator to the current expression and update the display
    currentExpression += butVal;  // Add spaces around operators for better formatting
    displayExpression += displayValue; // for looks - display
    ui->Display->setText(displayExpression);
    */

    // Determine which trig function was pressed and replace with the corresponding JS Math function
    if (QString::compare(butVal, "sin", Qt::CaseInsensitive) == 0) {
        butVal = "Math.sin";
        SinTrigger = true;
    }
    else if (QString::compare(butVal, "cos", Qt::CaseInsensitive) == 0) {
        butVal = "Math.cos";
        CosTrigger = true;
    }
    else if (QString::compare(butVal, "tan", Qt::CaseInsensitive) == 0) {
        butVal = "Math.tan";
        TanTrigger = true;
    }
    else if (QString::compare(butVal, "ln", Qt::CaseInsensitive) == 0) {
        butVal = "Math.log";  // ln(x) in JS is Math.log(x)
        LnTrigger = true;
    }
    else if (QString::compare(butVal, "log", Qt::CaseInsensitive) == 0) {
        butVal = "Math.log10";  // log(x) in JS is Math.log10(x)
        LogTrigger = true;
    }

    // Ensure that a number follows the function, i.e., append an opening parenthesis if necessary
    if (displayVal.isEmpty() || displayVal.endsWith(")") || displayVal.endsWith("+") || displayVal.endsWith("-") || displayVal.endsWith("*") || displayVal.endsWith("/")) {
        // The previous input is either empty or ends with an operator or closing parenthesis, so we need to append an opening parenthesis
        currentExpression += butVal + "(";
        displayExpression += displayValue + "(";
    } else {
        // If the last character is a number, we can append the function directly (e.g., sin(30) becomes Math.sin(30))
        currentExpression += butVal + "(";
        displayExpression += displayValue + "(";
    }

    openParenthesesCount += 1; // increment the open parentheses by 1

    // Update the display with the current expression
    ui->Display->setText(displayExpression);


}
