// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

void connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("quiz_app"); // Replace with your database name
    db.setUserName("root");         // Replace with your MySQL username
    db.setPassword("khatri123");    // Replace with your MySQL password

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
    } else {
        qDebug() << "Database connection successful!";
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentQuestionIndex(0)
    , score(0)
{
    ui->setupUi(this);
    connectToDatabase();
    loadQuestionsFromDatabase();  // Load questions from the database
    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->option1, 0);
    buttonGroup->addButton(ui->option2, 1);
    buttonGroup->addButton(ui->option3, 2);
    buttonGroup->addButton(ui->option4, 3);

    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::onSubmitClicked);

    loadQuestion();  // Load the first question
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadQuestionsFromDatabase()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM questions");

    if (!query.exec()) {
        qDebug() << "Failed to load questions from database:" << query.lastError().text();
        return;
    }

    quizQuestions.clear();
    while (query.next()) {
        Question q;
        q.text = query.value("question").toString();
        q.options = {
            query.value("option1").toString(),
            query.value("option2").toString(),
            query.value("option3").toString(),
            query.value("option4").toString()
        };
        q.correctOptionIndex = query.value("correct_option").toInt();
        quizQuestions.append(q);  // Add question to the quizQuestions list
    }
}

void MainWindow::loadQuestion()
{
    if (currentQuestionIndex >= quizQuestions.size()) {
        QMessageBox::information(this, "Quiz Completed", "Your score: " + QString::number(score));
        close();
        return;
    }

    const Question &q = quizQuestions[currentQuestionIndex];
    ui->questionLabel->setText(q.text);
    ui->option1->setText(q.options[0]);
    ui->option2->setText(q.options[1]);
    ui->option3->setText(q.options[2]);
    ui->option4->setText(q.options[3]);

    buttonGroup->setExclusive(false);
    ui->option1->setChecked(false);
    ui->option2->setChecked(false);
    ui->option3->setChecked(false);
    ui->option4->setChecked(false);
    buttonGroup->setExclusive(true);
}

void MainWindow::onSubmitClicked()
{
    QAbstractButton *selectedButton = buttonGroup->checkedButton();
    if (!selectedButton) {
        QMessageBox::warning(this, "No Selection", "Please select an answer before submitting.");
        return;
    }

    int selectedIndex = buttonGroup->id(selectedButton);
    if (selectedIndex == quizQuestions[currentQuestionIndex].correctOptionIndex) {
        score++;
    }

    currentQuestionIndex++;
    loadQuestion();  // Load the next question
}
