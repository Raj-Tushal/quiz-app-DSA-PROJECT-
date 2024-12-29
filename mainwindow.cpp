#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox> // For displaying score

// Questions and options
struct Question {
    QString text;
    QStringList options;
    int correctOptionIndex; // Index of the correct option (0-based)
};

const QList<Question> quizQuestions = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
    {"What is 5 + 7?", {"10", "12", "15", "11"}, 1},
    {"Which programming language is used in Qt?", {"Python", "C++", "Java", "C#"}, 1}
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentQuestionIndex(0)
    , score(0)
{
    ui->setupUi(this);

    // Group radio buttons for exclusive selection
    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->option1, 0);
    buttonGroup->addButton(ui->option2, 1);
    buttonGroup->addButton(ui->option3, 2);
    buttonGroup->addButton(ui->option4, 3);

    // Connect Submit button to the handler
    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::onSubmitClicked);

    // Load the first question
    loadQuestion();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadQuestion()
{
    // Check if there are more questions
    if (currentQuestionIndex >= quizQuestions.size()) {
        // Quiz finished, show the score
        QMessageBox::information(this, "Quiz Completed", "Your score: " + QString::number(score));
        close(); // Close the app
        return;
    }

    // Load the current question
    const Question &q = quizQuestions[currentQuestionIndex];
    ui->questionLabel->setText(q.text);
    ui->option1->setText(q.options[0]);
    ui->option2->setText(q.options[1]);
    ui->option3->setText(q.options[2]);
    ui->option4->setText(q.options[3]);

    // Clear any previous selection
    buttonGroup->setExclusive(false);
    ui->option1->setChecked(false);
    ui->option2->setChecked(false);
    ui->option3->setChecked(false);
    ui->option4->setChecked(false);
    buttonGroup->setExclusive(true);
}

void MainWindow::onSubmitClicked()
{
    // Get the selected button
    QAbstractButton *selectedButton = buttonGroup->checkedButton();
    if (!selectedButton) {
        QMessageBox::warning(this, "No Selection", "Please select an answer before submitting.");
        return;
    }

    // Check if the selected answer is correct
    int selectedIndex = buttonGroup->id(selectedButton);
    if (selectedIndex == quizQuestions[currentQuestionIndex].correctOptionIndex) {
        score++; // Increment score for correct answer
    }

    // Move to the next question
    currentQuestionIndex++;
    loadQuestion();
}
