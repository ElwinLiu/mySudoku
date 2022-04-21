#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <qpushbutton.h>
#include "Solution.h"
#include <qstack.h>
#include <qtimer.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getLabels();
    void getButtons();
    void show_num(int x, int y, int num);
    void generate_sudoku();
    void show_sudoku();
    bool check();
private slots:
    void on_renew_btn_clicked();

    void on_c0_clicked();

    void on_c8_clicked();

    void on_c7_clicked();

    void on_c6_clicked();

    void on_c5_clicked();

    void on_c4_clicked();

    void on_c3_clicked();

    void on_c2_clicked();

    void on_c1_clicked();

    void on_r0_clicked();

    void on_r1_clicked();

    void on_r2_clicked();

    void on_r3_clicked();

    void on_r4_clicked();

    void on_r5_clicked();

    void on_r6_clicked();

    void on_r7_clicked();

    void on_r8_clicked();

    void on_insert_clicked();

    void on_guide_btn_clicked();

    void on_restart_btn_clicked();

    void on_back_btn_clicked();

    void timer_slot();

    void on_stop_btn_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QVector<QLabel*>> labels;
    QVector<QVector<QPushButton*>> buttons;
    QVector<QVector<int>> sudoku;
    QVector<QVector<int>> saved_sudoku;
    QStack<QPair<int, int>> steps;     //记录“棋谱”
    int rowNum; //指向哪一行
    int colNum; //指向哪一列
    QTimer timer;
    int curTime;
    bool isFinished;
    int scores;
    QVector<QVector<int>> answer;

};
#endif // MAINWINDOW_H
