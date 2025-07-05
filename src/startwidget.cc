#include "startwidget.h"


StartWidget::StartWidget(QWidget *parent) : QWidget{parent}, layout{new QFormLayout(this)},
    title{new QLabel("## Welcome to QtAnswer!")}, filePath{new QLineEdit},
    fileSelect{filePath->addAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), QLineEdit::TrailingPosition)},
    scoreBaseSelect{new QSpinBox}, startButton{new QPushButton("Start game")} {

    // Configure and add title
    title->setTextFormat(Qt::MarkdownText);
    title->setAlignment(Qt::AlignCenter);
    layout->addRow(title);

    // Initialize QLineEdits for player names and add them to layout
    for (int i = 0; i<3; ++i) {
        playerNames.push_back(new QLineEdit);
        playerNames[i]->setPlaceholderText("default");
        layout->addRow("Player " + QString::number(i+1) + " name:", playerNames[i]);
    }

    // Position stuff for selecting clue/category JSON files
    layout->addRow("Categories file:", filePath);
    filePath->setPlaceholderText("Path to categories.json file");
    connect(fileSelect, SIGNAL(triggered(bool)), this, SLOT (browseCatFile()));

    // Position and set up stuff for selecting score base
    layout->addRow("Score base:", scoreBaseSelect);
    scoreBaseSelect->setMaximum(1000);
    scoreBaseSelect->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    scoreBaseSelect->setValue(200);

    // When startButton is pressed, we set player names accordingly
    layout->addRow(startButton);
    connect(startButton, SIGNAL (clicked(bool)), this, SLOT (gameStartPressed()));

}

StartWidget::~StartWidget() {
    // memory cleanup time!
    delete layout;
    delete title;
    delete filePath;
    delete fileSelect;
    delete scoreBaseSelect;
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

    emit gameStart(playerNames[0]->displayText(), playerNames[1]->displayText(), playerNames[2]->displayText(),
                   path.toStdString(), scoreBaseSelect->value());
}

void StartWidget::browseCatFile() {
    // Get filepath for categories.json file
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Select categories file", QDir::homePath(), "JSON files (*.json)");
    filePath->setText(filename);
}
