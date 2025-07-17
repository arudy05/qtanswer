#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
#include <cluefile.h>

class StartWidget : public QWidget {
    Q_OBJECT
    QFormLayout *layout;
    QLabel *title;
    std::vector<QLineEdit*> playerNames;
    QLineEdit *filePath;
    QAction *fileSelect;
    QSpinBox *scoreBaseSelect;
    QPushButton *startButton;
public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();

signals:
    void gameStart(QString p1, QString p2, QString p3, std::string path, int scoreBase);
    void fileSelected(std::string filepath);

public slots:
    void gameStartPressed();
    void browseCatFile();
};

#endif // STARTWIDGET_H
