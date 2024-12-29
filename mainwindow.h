#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSubmitClicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup *buttonGroup; // For grouping radio buttons
    int currentQuestionIndex;  // Tracks the current question
    int score;                 // Tracks the score

    void loadQuestion();       // Load the current question
};

#endif // MAINWINDOW_H
