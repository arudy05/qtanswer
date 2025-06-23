#include "startwidget.h"


StartWidget::StartWidget(QWidget *parent) : QWidget{parent}, layout{new QGridLayout(this)}, title{new QLabel("QtAnswer")},
playerNameText{new QLabel("Enter player names:")}, filePath{new QLineEdit}, fileSelect{new QPushButton("Browse...")},
  fileSelectLabel{new QLabel("Categories file:")}, startButton{new QPushButton("Start game")} {
    // Position QLabels on the layout
    layout->addWidget(title, 0, 0, 1, 3, Qt::AlignCenter);
    layout->addWidget(playerNameText, 1, 0);

    // Position QLineEdits for player names on the layout
    for (int i = 0; i<3; ++i) {
        playerNames.push_back(new QLineEdit("Player " + QString::number(i+1)));
        layout->addWidget(playerNames[i], i+1, 1, 1, 2);
    }

    // Position stuff for selecting clue/category JSON files
    layout->addWidget(fileSelectLabel, 4, 0);
    layout->addWidget(filePath, 4, 1);
    layout->addWidget(fileSelect, 4, 2);
    filePath->setReadOnly(true);
    connect(fileSelect, SIGNAL(clicked(bool)), this, SLOT (browseCatFile()));

    // When startButton is pressed, we set player names accordingly
    layout->addWidget(startButton, 5, 1, 1, 2);
    connect(startButton, SIGNAL (clicked(bool)), this, SLOT (gameStartPressed()));
}

StartWidget::~StartWidget() {
    // memory cleanup time!
    delete layout;
    delete title;
    delete playerNameText;
    delete filePath;
    delete fileSelect;
    delete fileSelectLabel;
    delete startButton;
    for (int i = 0; i<3; ++i) delete playerNames[i];
}

void StartWidget::gameStartPressed() {
    // Get all text entered in the QLineEdits and send it out
    // to other parts of the program to set player names properly

    QString path = filePath->text();
    QMessageBox error;

    if (path == "") {
        error.setText("No file selected!");
        error.exec();
        return;
    }

    ClueFile file(path.toStdString());
    if (!file.isFileValid()) {
        error.setText("The file " + path + " is not valid.");
        error.exec();
        return;
    }

    emit gameStart(playerNames[0]->displayText(), playerNames[1]->displayText(), playerNames[2]->displayText(), path.toStdString());
}

void StartWidget::browseCatFile() {
    // Get filepath for categories.json file
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Select categories file", "/home", "JSON files (*.json)");
    filePath->setText(filename);
}
