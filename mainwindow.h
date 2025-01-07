// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QList>  // Add this to include QList

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Question {  // Declare the Question struct to hold data for each question
    QString text;
    QList<QString> options;
    int correctOptionIndex;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QButtonGroup *buttonGroup;
    int currentQuestionIndex;
    int score;
    QList<Question> quizQuestions;  // Declare quizQuestions as a member variable

    // Function to load the questions from the database
    void loadQuestionsFromDatabase();

    // Function to load the current question
    void loadQuestion();  // Add this declaration

private slots:
    void onSubmitClicked();
};

#endif // MAINWINDOW_H
