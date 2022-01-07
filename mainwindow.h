#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(QString message);

private:
    Ui::MainWindow *ui;

    QWebSocket socket;
    QUrl url;
};

#endif // MAINWINDOW_H
