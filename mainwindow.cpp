#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "qmessagebox.h"
QVector <QVector<int>> sudoku_tmp = {{9, 7, 8, 3, 1, 2, 6, 4, 5}, {3, 1, 2, 6, 4, 5, 9, 7, 8},
                                     {6, 4, 5, 9, 7, 8, 3, 1, 2}, {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                     {1, 2, 3, 4, 5, 6, 7, 8, 9}, {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                     {8, 9, 7, 2, 3, 1, 5, 6, 4}, {2, 3, 1, 5, 6, 4, 8, 9, 7},
                                     {5, 6, 4, 8, 9, 7, 2, 3, 1}};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_slot()));
    getLabels(); //将label控件信息存入数组
    getButtons(); //将button控件信息存入数组
    rowNum = -1; //初始化为-1
    colNum = -1; //初始化为-1
    scores = 0;
    ui->lcdNumber->setDigitCount(2);
    ui->lcdNumber->display(scores);
    ui->lcdNumber_2->setDigitCount(3);
    isFinished = false;
    curTime = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_num(int x, int y, int num)
{
    QString lable = "image: url(:/new/prefix1/_square.png);";
    if (num != -1) lable.insert(25, QString::number(num));
    labels[x][y]->setStyleSheet(lable);
    return;
}

void MainWindow::getLabels()
{
    labels.resize(10);
    for (int i = 0; i < 10; i++)
    {
        labels[i].resize(10);
    }

    labels[1][1] = ui->label11;
    labels[1][2] = ui->label12;
    labels[1][3] = ui->label13;
    labels[1][4] = ui->label14;
    labels[1][5] = ui->label15;
    labels[1][6] = ui->label16;
    labels[1][7] = ui->label17;
    labels[1][8] = ui->label18;
    labels[1][9] = ui->label19;
    labels[2][1] = ui->label21;
    labels[2][2] = ui->label22;
    labels[2][3] = ui->label23;
    labels[2][4] = ui->label24;
    labels[2][5] = ui->label25;
    labels[2][6] = ui->label26;
    labels[2][7] = ui->label27;
    labels[2][8] = ui->label28;
    labels[2][9] = ui->label29;
    labels[3][1] = ui->label31;
    labels[3][2] = ui->label32;
    labels[3][3] = ui->label33;
    labels[3][4] = ui->label34;
    labels[3][5] = ui->label35;
    labels[3][6] = ui->label36;
    labels[3][7] = ui->label37;
    labels[3][8] = ui->label38;
    labels[3][9] = ui->label39;
    labels[4][1] = ui->label41;
    labels[4][2] = ui->label42;
    labels[4][3] = ui->label43;
    labels[4][4] = ui->label44;
    labels[4][5] = ui->label45;
    labels[4][6] = ui->label46;
    labels[4][7] = ui->label47;
    labels[4][8] = ui->label48;
    labels[4][9] = ui->label49;
    labels[5][1] = ui->label51;
    labels[5][2] = ui->label52;
    labels[5][3] = ui->label53;
    labels[5][4] = ui->label54;
    labels[5][5] = ui->label55;
    labels[5][6] = ui->label56;
    labels[5][7] = ui->label57;
    labels[5][8] = ui->label58;
    labels[5][9] = ui->label59;
    labels[6][1] = ui->label61;
    labels[6][2] = ui->label62;
    labels[6][3] = ui->label63;
    labels[6][4] = ui->label64;
    labels[6][5] = ui->label65;
    labels[6][6] = ui->label66;
    labels[6][7] = ui->label67;
    labels[6][8] = ui->label68;
    labels[6][9] = ui->label69;
    labels[7][1] = ui->label71;
    labels[7][2] = ui->label72;
    labels[7][3] = ui->label73;
    labels[7][4] = ui->label74;
    labels[7][5] = ui->label75;
    labels[7][6] = ui->label76;
    labels[7][7] = ui->label77;
    labels[7][8] = ui->label78;
    labels[7][9] = ui->label79;
    labels[8][1] = ui->label81;
    labels[8][2] = ui->label82;
    labels[8][3] = ui->label83;
    labels[8][4] = ui->label84;
    labels[8][5] = ui->label85;
    labels[8][6] = ui->label86;
    labels[8][7] = ui->label87;
    labels[8][8] = ui->label88;
    labels[8][9] = ui->label89;
    labels[9][1] = ui->label91;
    labels[9][2] = ui->label92;
    labels[9][3] = ui->label93;
    labels[9][4] = ui->label94;
    labels[9][5] = ui->label95;
    labels[9][6] = ui->label96;
    labels[9][7] = ui->label97;
    labels[9][8] = ui->label98;
    labels[9][9] = ui->label99;

}

void MainWindow::getButtons()
{
    buttons.resize(9);
    for (int i = 0; i < 9; i++)
    {
        buttons[i].resize(9);
    }

    buttons[0][0] = ui->r0;
    buttons[0][1] = ui->r1;
    buttons[0][2] = ui->r2;
    buttons[0][3] = ui->r3;
    buttons[0][4] = ui->r4;
    buttons[0][5] = ui->r5;
    buttons[0][6] = ui->r6;
    buttons[0][7] = ui->r7;
    buttons[0][8] = ui->r8;

    buttons[1][0] = ui->c0;
    buttons[1][1] = ui->c1;
    buttons[1][2] = ui->c2;
    buttons[1][3] = ui->c3;
    buttons[1][4] = ui->c4;
    buttons[1][5] = ui->c5;
    buttons[1][6] = ui->c6;
    buttons[1][7] = ui->c7;
    buttons[1][8] = ui->c8;
}

void MainWindow::generate_sudoku()
{
    //手动创建一个数独矩阵
    sudoku.resize(9);
    for (int i = 0; i < 9; i++)
    {
        sudoku[i].resize(9);
        sudoku[i] = sudoku_tmp[i];
    }

    //创建一个1-9无重复的数组
    QVector<int> list(9);
    int random = 1;
    for (int i = 0; i < 9; i++)
    {
        random = (rand() % 9)+ 1;
        while (true)
        {
            if (!count(list.begin(), list.end(), random))//如果该随机数不在数组中
            {
                list[i] = random;
                break;
            }
            else random = (rand() % 9)+ 1;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (sudoku[i][j] == list[k])
                {
                    sudoku[i][j] = list[(k + 1) % 9];
                    break;
                }
            }
        }
    }
}

void MainWindow::show_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            show_num(i+1, j+1, sudoku[i][j]);
        }
    }
}

bool MainWindow::check()
{
    int row[9][10] = {0};// 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
           // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
           int col[9][10] = {0};// 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
           int box[9][10] = {0};// 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
           for(int i=0; i<9; i++){
               for(int j = 0; j<9; j++){
                   // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
                   // 同时判断这个数在其所在的列有没有出现过
                   // 同时判断这个数在其所在的box中有没有出现过
                   if(sudoku[i][j] == -1) continue;
                   int curNumber = sudoku[i][j];
                   if(row[i][curNumber]) return false;
                   if(col[j][curNumber]) return false;
                   if(box[j/3 + (i/3)*3][curNumber]) return false;

                   row[i][curNumber] = 1;// 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
                   col[j][curNumber] = 1;
                   box[j/3 + (i/3)*3][curNumber] = 1;
               }
           }
           isFinished = true;
           for (int i = 0; i < 9; i++)
           {
               for (int j = 0; j < 9; j++)
               {
                   if (sudoku[i][j] == -1) isFinished = false;
               }
           }
           return true;
       }

void MainWindow::on_renew_btn_clicked()
{
    ui->lcdNumber_2->display(0);
    isFinished = false;
    curTime = 0;
    sudoku.clear();
    int level = ui->comboBox->currentIndex();
    QVector<QVector<int>> block; //存放被屏蔽的元素位置
    QVector<int> tmp; //赋值数组
    generate_sudoku();
    //随机元素屏蔽
    switch (level)
    {
    case 0: //简单模式,屏蔽15个元素
        for (int i = 0; i < 15; i++)
        {
            while (true)
            {
                tmp.push_back(rand() % 9);
                tmp.push_back(rand() % 9);
                if (!count(block.begin(), block.end(), tmp))
                {//避免重复屏蔽同一个位置的元素
                    block.push_back(tmp);
                    tmp.clear();
                    break;//跳出循环
                }
                tmp.clear();
            }
        }
        break;
    case 1: //中等模式，屏蔽25个元素
        for (int i = 0; i < 25; i++)
        {
            while (true)
            {
                tmp.push_back(rand() % 9);
                tmp.push_back(rand() % 9);
                if (!count(block.begin(), block.end(), tmp))
                {//避免重复屏蔽同一个位置的元素
                    block.push_back(tmp);
                    tmp.clear();
                    break;//跳出循环
                }
                tmp.clear();
            }
        }
        break;
    case 2: //困难模式，屏蔽35个元素
        for (int i = 0; i < 35; i++)
        {
            while (true)
            {
                tmp.push_back(rand() % 9);
                tmp.push_back(rand() % 9);
                if (!count(block.begin(), block.end(), tmp))
                {//避免重复屏蔽同一个位置的元素
                    block.push_back(tmp);
                    tmp.clear();
                    break;//跳出循环
                }
                tmp.clear();
            }
        }
        break;
    default:
        break;
    }
    //屏蔽体现在数独矩阵中
    generate_sudoku(); //生成数独矩阵
    for (int i = 0; i < block.size(); i++)
    {
        sudoku[block[i][0]][block[i][1]] = -1;
    }
    saved_sudoku = sudoku;
    show_sudoku();
    timer.start(1000); //1秒为间隔
    return;
}

void MainWindow::on_c0_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c0->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c0->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 0;
}
void MainWindow::on_c8_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c8->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c8->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 8;
}
void MainWindow::on_c7_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c7->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c7->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 7;
}
void MainWindow::on_c6_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c6->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c6->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 6;
}
void MainWindow::on_c5_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c5->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c5->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 5;
}
void MainWindow::on_c4_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c4->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c4->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 4;
}
void MainWindow::on_c3_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c3->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c3->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 3;
}
void MainWindow::on_c2_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c2->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c2->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 2;
}
void MainWindow::on_c1_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (colNum == -1)
    {
        ui->c1->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[1][colNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->c1->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    colNum = 1;
}
void MainWindow::on_r0_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r0->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r0->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 0;
}
void MainWindow::on_r1_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r1->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r1->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 1;
}
void MainWindow::on_r2_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r2->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r2->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 2;
}
void MainWindow::on_r3_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r3->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r3->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 3;
}
void MainWindow::on_r4_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r4->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r4->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 4;
}
void MainWindow::on_r5_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r5->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r5->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 5;
}
void MainWindow::on_r6_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r6->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r6->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 6;
}
void MainWindow::on_r7_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r7->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r7->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 7;
}
void MainWindow::on_r8_clicked()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    if (rowNum == -1)
    {
        ui->r8->setStyleSheet("QPushButton{background:blue}");
    }
    else
    {
        buttons[0][rowNum]->setStyleSheet("QPushButton{background:}"); //前一个设置为空
        ui->r8->setStyleSheet("QPushButton{background:blue}"); //当前设置为蓝色
    }
    rowNum = 8;
}

void MainWindow::on_insert_clicked()
{
    //补丁
    if (sudoku.size() == 0)
    {
        QMessageBox::information(NULL, "注意", "您还未开始游戏，请点击new");
        return;
    }
    QString text = ui->plainTextEdit->toPlainText();
    int tmpNum = text.toInt();
    if (colNum == -1 || rowNum == -1)
    {
        QMessageBox::information(NULL, "注意", "请选择您要求改的方块");
        return;
    }
    else if (tmpNum > 9 || tmpNum < 1)
    {
        QMessageBox::information(NULL, "注意", "请填入1-9之间的数字！");
        return;
    }
    sudoku[rowNum][colNum] = tmpNum;
    bool isValid = check();
    if (!isValid)
    {
        QMessageBox::information(NULL, "注意", "此处不可填入该数字！");
        sudoku[rowNum][colNum] = -1;
        return;
    }

    steps.push({rowNum, colNum});
    show_num(rowNum+1, colNum+1, tmpNum);

    //如果完成整个数独
    if (isFinished)
    {
        QMessageBox::information(NULL, "恭喜", "您完成了此关卡！");
        ui->lcdNumber->display(++scores);
    }
}

void MainWindow::on_guide_btn_clicked()
{
    //补丁
    if (sudoku.size() == 0)
    {
        QMessageBox::information(NULL, "注意", "您还未开始游戏，请点击new");
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    //获取答案
    Solution solution;
    answer = sudoku;
    solution.solveSudoku(answer);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == -1)
            {
                show_num(i+1,j+1,answer[i][j]);
                buttons[0][i]->setStyleSheet("QPushButton{background:yellow}"); //当前设置为黄色
                buttons[1][j]->setStyleSheet("QPushButton{background:yellow}"); //当前设置为黄色
                sudoku[i][j] = answer[i][j];

                steps.push({i, j}); //入栈棋谱

                //如果完成整个数独
                check();
                if (isFinished)
                {
                    QMessageBox::information(NULL, "恭喜", "您完成了此关卡！");
                    ui->lcdNumber->display(++scores);
                }

                return;
            }
        }
    }

}

void MainWindow::on_restart_btn_clicked()
{
    ui->lcdNumber_2->display(0);
    curTime = 0;
    //补丁
    if (sudoku.size() == 0)
    {
        QMessageBox::information(NULL, "注意", "您还未开始游戏，请点击new");
        return;
    }
    sudoku = saved_sudoku; //还原数独矩阵
    show_sudoku();
    isFinished = false;
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    timer.start(1000); //1秒为间隔
}

void MainWindow::on_back_btn_clicked()
{
    //补丁
    if (sudoku.size() == 0)
    {
        QMessageBox::information(NULL, "注意", "您还未开始游戏，请点击new");
        return;
    }
    //补丁
    if (steps.empty())
    {
        QMessageBox::information(NULL, "注意", "您已经回退至最后一步！");
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        buttons[0][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
        buttons[1][i]->setStyleSheet("QPushButton{background:}"); //背景颜色设置为空
    }
    int row, col;
    row = steps.top().first;
    col = steps.top().second;
    buttons[0][row]->setStyleSheet("QPushButton{background:red}"); //当前设置为黄色
    buttons[1][col]->setStyleSheet("QPushButton{background:red}"); //当前设置为黄色
    steps.pop();
    sudoku[row][col] = -1;
    show_num(row+1, col+1, -1);
}

void MainWindow::timer_slot()
{
    if(timer.isActive())
    {
       ui->lcdNumber_2->display(++curTime);
       if (isFinished) timer.stop();
    }
}

void MainWindow::on_stop_btn_clicked()
{
    if (timer.isActive()) timer.stop();
    else timer.start(1000);

}
