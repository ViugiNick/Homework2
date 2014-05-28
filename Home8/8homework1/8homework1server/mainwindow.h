#include <QMainWindow>
#include <QLabel>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>
#include <QLayout>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void sessionOpened();
        void acceptConnection();
        void sendMessage();
        void startReading();
        void clientDisconnected();
        void enableSmiles();
        void disableSmiles();
        void addSmile1();
        void addSmile2();
        void addSmile3();

    private:
        bool isNotSpaces(QString qStr);
        Ui::MainWindow *ui;
        QTcpServer *tcpServer;
        QTcpSocket *clientSocket;
        QNetworkSession *networkSession;
        quint16 blockSize;
};
