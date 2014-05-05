#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QSignalMapper>
#include <QGridLayout>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    explicit Game(int fSize, QWidget *parent = 0);
    ~Game();

signals:
    void newTurn(int num);

private slots:
    void stateChanged(int pos);

private:
    ///Method to generate field
    void randField(int fSize);
    ///Method to tell you, that you win
    void showMsgBox(QString const &text);
    ///Method to push the button
    void setupButtons();

    int fieldSize;
    Ui::Game *ui;
    QVector<QVector<int>> state;
    QVector<int> value;
    QVector<QPushButton*> buttons;
    QSignalMapper *qsm;
    int oldPos;
    int turn;
    int numberOfOpened;
};
