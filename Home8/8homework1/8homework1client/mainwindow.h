#include <QMainWindow>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>

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
        void displayError(QAbstractSocket::SocketError socketError);
        void sendMessage();
        void startReading();
        void enableSendButton();
        void serverDisconnected();
        void enableAddressChange();
        void disableAddressChange();
        void enableSmiles();
        void disableSmiles();
        void tryConnect();
        void addSmile1();
        void addSmile2();
        void addSmile3();

    private:
        bool isNotSpaces(QString qStr);
        Ui::MainWindow *ui;
        QTcpSocket *serverSocket;
        QNetworkSession *networkSession;
        quint16 blockSize;
};
