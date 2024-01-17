#ifndef CUSTOMPLAINTEXT_H
#define CUSTOMPLAINTEXT_H

#include <QPlainTextEdit>
#include <QKeyEvent>

class CustomPlainTextEdit : public QPlainTextEdit {
public:
    explicit CustomPlainTextEdit(QWidget* parent = nullptr) : QPlainTextEdit(parent) {}

protected:
    void keyPressEvent(QKeyEvent* event) override {
        if (event->key() == Qt::Key_Return && !(event->modifiers() & Qt::ShiftModifier)) {
            // Captura o evento de pressionar Enter (Return) sem a tecla Shift
            qDebug() << "Enter Pressionado";
            // Adicione seu código aqui para lidar com a ação desejada
        } else {
            QPlainTextEdit::keyPressEvent(event);
        }
    }
};


#endif // CUSTOMPLAINTEXT_H
